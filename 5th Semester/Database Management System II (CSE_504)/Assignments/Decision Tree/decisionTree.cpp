#include<bits/stdc++.h>
using namespace std;

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


int main(void) {
    vector<dataItem> root;
    read_from_File("dataSet.txt", &root);

    printEdge(root);

}


