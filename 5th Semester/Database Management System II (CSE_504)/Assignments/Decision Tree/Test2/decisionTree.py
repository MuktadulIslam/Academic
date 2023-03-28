import numpy as np
import pandas as pd
import json
import pprint


def calculateEntropy(data):
    targetColumn = data.keys()[-1]
    targetValues = data[targetColumn].unique()
    entropy = 0

    for value in targetValues:
        probability = data[targetColumn].value_counts()[value] / data.shape[0]
        entropy += -(probability * np.log2(probability))

    return np.float16(entropy)


def calculateEntropyAttributes(data, attribute):
    targetColumn = data.keys()[-1]
    targetValues = data[targetColumn].unique()
    attributeValues = data[attribute].unique()
    averageEntropy = 0

    for attributeValue in attributeValues:
        entropy = 0
        for value in targetValues:
            numerator = len(data[attribute][data[attribute] == attributeValue][data[targetColumn] == value])
            denominator = len(data[attribute][data[attribute] == attributeValue])

            if denominator != 0 and numerator != 0:
                probability = numerator / denominator
                entropy += -(probability * np.log2(probability))
            else:
                entropy += 0

        averageEntropy += (denominator / len(data)) * entropy

    return np.float16(averageEntropy)


def maxInfoGain(data):
    infoGain = []
    parentEntropy = calculateEntropy(data)

    for key in data.keys()[:-1]:
        childEntropy = calculateEntropyAttributes(data, key)
        infoGain.append(parentEntropy - childEntropy)

    return data.keys()[np.argmax(infoGain)]


def createSubTable(data, attribute, value):
    return data[data[attribute] == value].reset_index(drop=True)


def buildTree(data, tree=None):
    node = maxInfoGain(data)
    nodeAttribute = data[node].unique()
    targetColumn = data.keys()[-1]

    if tree is None:
        tree = {}
        tree[node] = {}

    for attribute in nodeAttribute:
        newSubtable = createSubTable(data, node, attribute)

        targetValues = np.unique(newSubtable[targetColumn])

        if len(targetValues) == 1:
            tree[node][attribute] = targetValues.item()
        else:
            tree[node][attribute] = buildTree(newSubtable)

    return tree


def predict(tree, instance):
    # print(tree)
    # print(tree, "\nINSTANCE: ",instance, "\n")
    # print(isinstance(tree, dict))
    if not isinstance(tree, dict):
        return tree
    else:
        for item, val in tree.items():
            newTree = val
            root_node = item

            if root_node in instance.keys():
                # print(root_node)
                newTree = tree[root_node]
                newRootNode = instance[root_node]

                # print(newRootNode, newTree.keys())

                if newRootNode in newTree.keys():
                    resultTree = predict(newTree[newRootNode], instance)
                    # print(type(resultTree))
                else:
                    # print("I am in none\n")
                    return None

    return resultTree


def evaluate(tree, testData):
    correctPredict = 0
    wrongPredict = 0
    targetColumn = testData.keys()[-1]
    # print()
    for index, row in testData.iterrows():
        test = row[:-1]
        instance = test.to_dict()

        result = predict(tree, instance)
        # print(result, row[targetColumn], "\n")
        if result == row[targetColumn]:
            correctPredict += 1
        else:
            wrongPredict += 1
            # print("hehe")
    accuracy = correctPredict / (correctPredict + wrongPredict)
    # print(accuracy)
    return accuracy


Data = pd.read_csv('nursery.data')

avgAcc = 0
for i in range(0, 1):
    print("Tree-", i, ": \n\n")
    trainData = Data.sample(frac=0.8)
    testData = Data.drop(trainData.index)
    trainData.reset_index(inplace=True, drop=True)
    testData.reset_index(inplace=True, drop=True)

    Tree = buildTree(trainData)
    avgAcc += evaluate(Tree, testData)
    # print(avgAcc)
    # pprint.pprint(Tree)
    print(json.dumps(Tree, indent=4, default=str))
    print("\n\n\n")

print("Average accuracy: ", avgAcc * 100, "%")
