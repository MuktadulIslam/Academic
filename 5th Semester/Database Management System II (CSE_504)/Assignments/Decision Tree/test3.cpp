// 2.36 pm

#include<bits/stdc++.h>
#define TOTAL_CLASS 3
#define L 1
#define R 2
#define B 3

#define TOTAL_FEATURE_VECTOR 5
// giving attribute no
#define LRB 1
#define LEFT_WEIGHT 2
#define LEFT_DISTANCE 3
#define RIGHT_WEIGHT 4
#define RIGHT_DISTANCE 5

using namespace std;

int tempArray[700][5];
int tempArraySize = 0;

struct dataItem{
    char LRB_value;
    int dataNo;
    int leftWeight;
    int leftDistance;
    int rightWeight;
    int rightDistance;

};

void printEdge(vector<dataItem> edge) {
    for(auto & a:edge) {
        cout << a.dataNo << " ";
        //cout << a.dataNo << "-> " << a.LRB_value << " " << a.leftWeight << " " << a.leftDistance;
        //cout << " " << a.rightWeight << " " << a.rightDistance << endl;
    }
    cout << endl << endl;
}

void addDataItem(string line, int dataNo, vector<dataItem> *root) {
    struct dataItem item;
    item.LRB_value = line[0];
    item.leftWeight = line[2]-48;
    item.leftDistance = line[4]-48;
    item.rightWeight = line[6]-48;
    item.rightDistance = line[8]-48;
    item.dataNo = dataNo;

    (*root).push_back(item);
}

void read_from_File(string filename, vector<dataItem> *root) {
    fstream fin;
    fin.open(filename, ios::in);
    string line;
    int dataNo=1;

    while(getline(fin, line)) {
        addDataItem(line, dataNo, root);
        dataNo++;
    }
    fin.close();
}


void structToArray(vector<dataItem> edge) {
    int i=0;
    for(auto & a:edge) {
        if(a.LRB_value == 'L') tempArray[i][0] = L;
        else if(a.LRB_value == 'R') tempArray[i][0] = R;
        else tempArray[i][0] = B;

        tempArray[i][1] = a.leftWeight;
        tempArray[i][2] = a.rightDistance;
        tempArray[i][3] = a.rightWeight;
        tempArray[i][4] = a.rightDistance;
        i++;
    }
    tempArraySize = i;
}


float getProvabolity(int attributeNo, int type) {
    int item = 0;

    for(int i=0 ; i<tempArraySize ; i++) {
        if(tempArray[i][attributeNo-1] == type) item++;
    }

    return (float)item/(float)tempArraySize;
}


float getProvability_with_class(int classType, int attributeNo, int attType) {
    int item = 0;
    for(int i=0 ; i<tempArraySize ; i++) {
        if(tempArray[i][0] == classType && tempArray[i][attributeNo-1] == attType) item++;
    }

    return (float)item/(float)tempArraySize;
}


float getInformationGain(vector<dataItem> edge, int attributeNo) {
    float prov_Ci_Xi, prov_Ci, prov_Xi;
    structToArray(edge);    // array will store in tempArray and the size in tempArraySize

    float informationGain = 0.0;
    for(int classType=1 ; classType<=TOTAL_CLASS ; classType++) {
        for(int attType=1 ; attType<=TOTAL_FEATURE_VECTOR ; attType++) {

            prov_Ci_Xi = getProvability_with_class(classType, attributeNo, attType);
            prov_Ci = getProvabolity(1, classType);
            prov_Xi = getProvabolity(attributeNo, attType);
            cout << prov_Ci_Xi << "  " << prov_Ci << "  " << prov_Xi << endl;

        }
    }
}

int main(void) {
    vector<dataItem> root;
    read_from_File("dataSet.txt", &root);

    //printEdge(root);
    cout << getInformationGain(root, 1);

}

