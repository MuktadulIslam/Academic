#include<bits/stdc++.h>
using namespace std;

struct dataItem{
    char LRB_value;
    int dataNo;
    int dataValue[4];
    // dataValue[0] = leftWeight;
    // dataValue[1] = leftDistance;
    // dataValue[2] = rightWeight;
    // dataValue[3] = rightDistance;

};

struct node{
    int total_balanced = 0;
    int total_left = 0;
    int total_right = 0;
    int total_data = 0;

    vector<dataItem> dataSet;
    struct node *parent = NULL, *child[5] = {NULL};
};

void printEdge(vector<dataItem> edge) {
    for(auto & a:edge) {
        cout << a.dataNo << " ";
        //cout << a.dataNo << "-> " << a.LRB_value << " " << a.dataValue[0] << " " << a.dataValue[1];
        //cout << " " << a.dataValue[2] << " " << a.dataValue[3];
        cout << endl;
    }
    cout << endl << endl;
}

void addDataItem(string line, int dataNo, vector<dataItem> *root) {
    struct dataItem item;
    item.LRB_value = line[0];
    item.dataValue[0] = line[2]-48;
    item.dataValue[1] = line[4]-48;
    item.dataValue[2] = line[6]-48;
    item.dataValue[3] = line[8]-48;
    item.dataNo = dataNo;

    (*root).push_back(item);
}

void read_from_File(string filename, vector<dataItem> *allDataSet) {
    fstream fin;
    fin.open(filename, ios::in);
    string line;
    int dataNo=1;

    while(getline(fin, line)) {
        addDataItem(line, dataNo, allDataSet);
        dataNo++;
    }
    fin.close();
}

void add_dataSet_intoChild(int feature_vectors_Index, vector<dataItem> *dataSet, struct node *child[5]) {
    for(auto & item:(*dataSet)) {
        if((item.dataValue[feature_vectors_Index] == 1)) (*child[0]).dataSet.push_back(item);
        else if((item.dataValue[feature_vectors_Index] == 2)) (*child[1]).dataSet.push_back(item);
        else if((item.dataValue[feature_vectors_Index] == 3)) (*child[2]).dataSet.push_back(item);
        else if((item.dataValue[feature_vectors_Index] == 4)) (*child[3]).dataSet.push_back(item);
        else if((item.dataValue[feature_vectors_Index] == 5)) (*child[4]).dataSet.push_back(item);
    }
}

void insert_data_into_node(vector<dataItem> *dataSet, struct node *parentNode, int feature_vectors_Index) {
    if(feature_vectors_Index == -1) {
        for(auto & item:(*dataSet)) {
            (*parentNode).dataSet.push_back(item);
        }
    }

    else{
        /*struct node *child[5];
        child[0] = (node*) malloc(sizeof(node));
        child[1] = (node*) malloc(sizeof(node));
        child[2] = (node*) malloc(sizeof(node));
        child[3] = (node*) malloc(sizeof(node));
        child[4] = (node*) malloc(sizeof(node));

        (*child[0]).parent = parentNode;
        (*child[1]).parent = parentNode;
        (*child[2]).parent = parentNode;
        (*child[3]).parent = parentNode;
        (*child[4]).parent = parentNode;

        (*parentNode).child[0] = child[0];
        (*parentNode).child[1] = child[1];
        (*parentNode).child[2] = child[2];
        (*parentNode).child[3] = child[3];
        (*parentNode).child[4] = child[4];
        vector<node*> child(5);
        for (int i = 0; i < 5; i++) {
            child[i] = new node();
            child[i]->parent = parentNode;
        }

        (*parentNode).child[0] = child[0];
        (*parentNode).child[1] = child[1];
        (*parentNode).child[2] = child[2];
        (*parentNode).child[3] = child[3];
        (*parentNode).child[4] = child[4];



        if(feature_vectors_Index == 0) {
            add_dataSet_intoChild(0, dataSet, child);
        }
        else if(feature_vectors_Index == 1) {
            add_dataSet_intoChild(1, dataSet, child);
        }
        else if(feature_vectors_Index == 2) {
            add_dataSet_intoChild(2, dataSet, child);
        }
        else if(feature_vectors_Index == 3) {
            add_dataSet_intoChild(3, dataSet, child);
        }

        else{
            cout << "Data insertion into node failed!!!!" << endl;
            exit(0);
        }*/

        vector<node*> child(5);

        for (int i = 0; i < 5; i++) {
            child[i] = new node();
            child[i]->parent = parentNode;
        }

        (*parentNode).child[0] = child[0];
        (*parentNode).child[1] = child[1];
        (*parentNode).child[2] = child[2];
        (*parentNode).child[3] = child[3];
        (*parentNode).child[4] = child[4];

        if (feature_vectors_Index == 0) {
            add_dataSet_intoChild(0, dataSet, child.data());
        } else if (feature_vectors_Index == 1) {
            add_dataSet_intoChild(1, dataSet, child.data());
        } else if (feature_vectors_Index == 2) {
            add_dataSet_intoChild(2, dataSet, child.data());
        } else if (feature_vectors_Index == 3) {
            add_dataSet_intoChild(3, dataSet, child.data());
        } else {
            cout << "Data insertion into node failed!!!!" << endl;
            exit(0);
        }
    }

    (*dataSet).clear();

}


void calculate_distinct_output(struct node *node) {
    int left=0, right=0, balanced=0;

    for(auto &item:(*node).dataSet) {
        if(item.LRB_value == 'L') left++;
        else if(item.LRB_value == 'R') right++;
        else balanced++;
    }

    (*node).total_left = left;
    (*node).total_right = right;
    (*node).total_balanced = balanced;
    (*node).total_data = left + right + balanced;
}


float log_calculator(float value, float base){
    return log2(value) / log2(base);
}


float calculate_attribute_entropy(int total_left, int total_right, int total_balanced) {
    float totalData = total_balanced + total_left + total_right;

    float entropy = total_left/totalData * log_calculator(total_left/totalData, 3.0);
    entropy += total_right/totalData * log_calculator(total_right/totalData, 3.0);
    entropy += total_balanced/totalData * log_calculator(total_balanced/totalData, 3.0);
    //cout << "endtropy= " << entropy << endl;
    return -entropy;
}


float calculate_entropy(struct node *node, int feature_vectors_Index) {
    if(feature_vectors_Index == -1) {
        int total_leftData = (*node).total_left;
        int total_rightData = (*node).total_right;
        int total_balancedData = (*node).total_balanced;

        return calculate_attribute_entropy(total_leftData, total_rightData, total_balancedData);
    }
    else {
        int totalL_type1=0, totalR_type1=0, totalB_type1=0;
        int totalL_type2=0, totalR_type2=0, totalB_type2=0;
        int totalL_type3=0, totalR_type3=0, totalB_type3=0;
        int totalL_type4=0, totalR_type4=0, totalB_type4=0;
        int totalL_type5=0, totalR_type5=0, totalB_type5=0;


        for(auto &item:(*node).dataSet) {
            if(item.LRB_value == 'L'){
                if(item.dataValue[feature_vectors_Index] == 1) totalL_type1++;
                else if(item.dataValue[feature_vectors_Index] == 2) totalL_type2++;
                else if(item.dataValue[feature_vectors_Index] == 3) totalL_type3++;
                else if(item.dataValue[feature_vectors_Index] == 4) totalL_type4++;
                else if(item.dataValue[feature_vectors_Index] == 5) totalL_type5++;
            }
            else if(item.LRB_value == 'R'){
                if(item.dataValue[feature_vectors_Index] == 1) totalR_type1++;
                else if(item.dataValue[feature_vectors_Index] == 2) totalR_type2++;
                else if(item.dataValue[feature_vectors_Index] == 3) totalR_type3++;
                else if(item.dataValue[feature_vectors_Index] == 4) totalR_type4++;
                else if(item.dataValue[feature_vectors_Index] == 5) totalR_type5++;
            }

            else if(item.LRB_value == 'B'){
                if(item.dataValue[feature_vectors_Index] == 1) totalB_type1++;
                else if(item.dataValue[feature_vectors_Index] == 2) totalB_type2++;
                else if(item.dataValue[feature_vectors_Index] == 3) totalB_type3++;
                else if(item.dataValue[feature_vectors_Index] == 4) totalB_type4++;
                else if(item.dataValue[feature_vectors_Index] == 5) totalB_type5++;
            }
        }


        int totalData_type1 = totalL_type1 + totalR_type1 + totalB_type1;
        int totalData_type2 = totalL_type1 + totalR_type1 + totalB_type1;
        int totalData_type3 = totalL_type1 + totalR_type1 + totalB_type1;
        int totalData_type4 = totalL_type1 + totalR_type1 + totalB_type1;
        int totalData_type5 = totalL_type1 + totalR_type1 + totalB_type1;
        float totalData = (*node).total_data;
        //cout << totalData_type1 << "  " << totalData_type2 << "  "  << totalData_type3 << "  "  << totalData_type4 << "  " << totalData_type5 << endl;

        float entropy1 = calculate_attribute_entropy(totalL_type1, totalR_type1, totalB_type1);
        float entropy2 = calculate_attribute_entropy(totalL_type2, totalR_type2, totalB_type2);
        float entropy3 = calculate_attribute_entropy(totalL_type3, totalR_type3, totalB_type3);
        float entropy4 = calculate_attribute_entropy(totalL_type4, totalR_type4, totalB_type4);
        float entropy5 = calculate_attribute_entropy(totalL_type5, totalR_type5, totalB_type5);
        //cout << entropy1 << "  " << entropy2 << "  " << entropy3 << "  " << entropy4 << "  " << entropy5 << "  " << endl;

        cout << "Total_type1= " << totalL_type1 << "  " << totalR_type1 << "  "  << totalB_type1 << "    " << totalData_type1 << "   " << entropy1 << endl;
        cout << "Total_type2= " << totalL_type2 << "  " << totalR_type2 << "  "  << totalB_type2 << "    " << totalData_type2 << "   " << entropy2 << endl;
        cout << "Total_type3= " << totalL_type3 << "  " << totalR_type3 << "  "  << totalB_type3 << "    " << totalData_type3 << "   " << entropy3 << endl;
        cout << "Total_type4= " << totalL_type4 << "  " << totalR_type4 << "  "  << totalB_type4 << "    " << totalData_type4 << "   " << entropy4 << endl;
        cout << "Total_type5= " << totalL_type5 << "  " << totalR_type5 << "  "  << totalB_type5 << "    " << totalData_type5 << "   " << entropy5 << endl;

        float average_entropy = totalData_type1/totalData * entropy1 + totalData_type2/totalData * entropy2;
        average_entropy += totalData_type3/totalData * entropy3 + totalData_type4/totalData * entropy4;
        average_entropy += totalData_type5/totalData * entropy5;
        //cout << average_entropy << endl;

        return average_entropy;
    }
}


float calculate_information_gain(struct node *node, int feature_vectors_Index, float parentEntropy) {
    float childEntropy = calculate_entropy(node, feature_vectors_Index);
    return parentEntropy - childEntropy;
}


void make_decisionTree(struct node *root, float parentEntropy, int parent_feature_vectors_Index){
    if(parentEntropy == 0.0) return;


    float bestInfoGain = 0;
    float bestInfoGainEntropy;
    float infoGain, childEntropy;
    int feature_vectors_Index;

    for(int i=0 ; i<4 ; i++) {
        if(i == parent_feature_vectors_Index) continue;

        cout << "Hello WOrld....................\n";
        childEntropy = calculate_entropy(root, feature_vectors_Index);
        infoGain = parentEntropy - childEntropy;

        if(infoGain > bestInfoGain) {
            bestInfoGain = infoGain;
            feature_vectors_Index = i;
            bestInfoGainEntropy = childEntropy;
        }
    }

    insert_data_into_node(&((*root).dataSet), root, feature_vectors_Index);

    // For printing
    cout << "-----------------Child-1---------------------\n";
    printEdge(root->child[0]->dataSet);
    cout <<"\n\n\n\n\n";
    make_decisionTree(root->child[0], bestInfoGainEntropy, feature_vectors_Index);

    cout << "-----------------Child-2---------------------\n";
    printEdge(root->child[1]->dataSet);
    cout <<"\n\n\n\n\n";
    make_decisionTree(root->child[0], bestInfoGainEntropy, feature_vectors_Index);

    cout << "-----------------Child-3---------------------\n";
    printEdge(root->child[2]->dataSet);
    cout <<"\n\n\n\n\n";
    make_decisionTree(root->child[0], bestInfoGainEntropy, feature_vectors_Index);

    cout << "-----------------Child-4---------------------\n";
    printEdge(root->child[3]->dataSet);
    cout <<"\n\n\n\n\n";
    make_decisionTree(root->child[0], bestInfoGainEntropy, feature_vectors_Index);

    cout << "-----------------Child-5---------------------\n";
    printEdge(root->child[4]->dataSet);
    cout <<"\n\n\n\n\n";
    make_decisionTree(root->child[0], bestInfoGainEntropy, feature_vectors_Index);

}


void decisionTree(struct node *root) {
    calculate_distinct_output(root);
    float parentEntropy = calculate_entropy(root, -1);

    make_decisionTree(root, parentEntropy, -1);

}


int main(void) {
    vector<dataItem> allDataSet;
    struct node *root = (node*) malloc(sizeof(node));

    read_from_File("dataSet.txt", &allDataSet);
    insert_data_into_node(&allDataSet, root, -1);
    //calculate_distinct_output(root);

    decisionTree(root);

    //printEdge((*root).dataSet);

}

