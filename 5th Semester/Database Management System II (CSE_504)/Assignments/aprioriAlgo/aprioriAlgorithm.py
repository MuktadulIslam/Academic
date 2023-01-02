import dataTable


def createFrequency(datatable, level, minSupportCount):
    supportCountTable = createFrequencyForLevel_1(datatable, minSupportCount)
    if level < 1:
        return []
    elif level == 1:
        return supportCountTable
    else:
        for i in range(level - 1):
            supportCountTable = createFrequencyForLevel_N(supportCountTable, i + 2, minSupportCount)
            if len(supportCountTable) == 0:
                return []

        return supportCountTable


def createFrequencyForLevel_N(frequencyTable, level, minSupportCount):
    # finding the old elements set from the previous support count table and storing in newElementsList
    oldTableList = []
    for i in frequencyTable:
        oldTableList.append(i[0])

    # finding the new elements set and storing in newElementsList
    oldElementsNumber = len(oldTableList)
    newElementsList = []
    for i in range(oldElementsNumber - 1):
        j = i + 1
        while j < oldElementsNumber:
            if len(oldTableList[i].intersection(oldTableList[j])) >= (level - 2):
                newElementsList.append(oldTableList[i].union(oldTableList[j]))
            j += 1

    # creating new support count table
    newElementsNumber = len(newElementsList)
    newFrequencyTable = [];
    for i in newElementsList:
        newFrequencyTable.append([i, 0])

    for i in range(newElementsNumber):
        for j in dataTable.table:
            if j.issuperset(newElementsList[i]):
                newFrequencyTable[i][1] += 1

    # checking whose element supports the support count
    finalFrequencyTable = []
    for i in newFrequencyTable:
        if i[1] >= minSupportCount:
            finalFrequencyTable.append(i)

    return removeDuplicates(finalFrequencyTable)


def createFrequencyForLevel_1(datatable, minSupportCount):
    a = []
    for i in datatable:
        a.extend(list(i))

    totalItems = list(set(a))
    length = len(totalItems)
    c1 = []

    # creating support counter table for length 1 (using dictionary)
    for i in range(length):
        x = a.count(totalItems[i])
        if x >= minSupportCount:
            c1.append([{totalItems[i]}, x])

    return c1


def removeDuplicates(frequencyTable):
    new_list = []
    for i in frequencyTable:
        if i not in new_list:
            new_list.append(i)

    return new_list


def supportCount(itemSet, datatable, minSupportCount):
    frequencyTable = createFrequency(datatable, len(itemSet), minSupportCount)
    for i in frequencyTable:
        if i[0] == itemSet:
            return i[1]
    return 0


def getNumberSetFromString(string):
    string += ","
    numList = []
    while string != "":
        i = string.index(",")
        numList.append(int(string[0:i]))
        string = string[i + 1:]

    return set(numList)


def getConfidence(expression, datatable, minSupportCount):
    # filtering the string
    expression = expression.replace(" ", "")
    expression = expression.replace("I", "")
    expression = expression.replace("i", "")
    expression = expression.replace("{,", "")
    expression = expression.replace(",}", "")
    expression = expression.replace("{", "")
    expression = expression.replace("}", "")

    # getting number set from the expression
    index = expression.index("=>")
    ifPart = getNumberSetFromString(expression[0:index])
    thenPart = getNumberSetFromString(expression[index + 2:])

    a = supportCount(ifPart.union(thenPart), datatable, minSupportCount)
    b = supportCount(ifPart, datatable, minSupportCount)

    if b == 0:
        return 0
    else:
        return a/b
