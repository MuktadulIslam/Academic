#include<bits/stdc++.h>
#define N 100   // variable size
#define T 100   // total transection number
#define R 111
#define W 222
#define INITIAL 1
#define VISITED 2
#define FINISHED 3


using namespace std;

int conflictSerializable = 0;
int transactions[N][N][2] = {0};      // [variableID][No of transection][transection number, mood]
int dataItemTransectionSize[N] = {0};

string dataItem[N] = {};
int numberOfDataItem = 0;

int totalTransaction[T] = {0};          // For finding total number of transection to defining total nodes
int total_number_of_transection= 0;     // r4(X),W5(Y),W4(X) total transection = 2



void add_new_transaction_number(int number) {
    for(int i=0 ; i<total_number_of_transection ; i++){
        if(totalTransaction[i] == number) return;
    }
    totalTransaction[total_number_of_transection++] = number;
}

int get_transaction_number(string str){
    char s[10];
    int i = 1;
    while(1){
        if(str[i] == '(') break;
        s[i-1] = str[i];
        i++;
    }
    s[i-1] = '\0';

    int transaction_number = atoi(s);

    add_new_transaction_number(transaction_number);
    return transaction_number;

}

int push_in_variable(string str){
    char s[10];
    int j,i=2;
    while(str[i] != '(');
    i++;

    for(j=0 ; str[i] != ')' ; i++, j++)
        s[j] = str[i];
    s[j] = '\0';

    string tempStr = s;

    for(int i=0 ; i< numberOfDataItem ; i++){
        if(tempStr == dataItem[i]) return i;
    }

    dataItem[numberOfDataItem] = tempStr;
    return numberOfDataItem++;
}

void make_transaction(string str){
    int variableIndex = push_in_variable(str);
    int transactionNumber = get_transaction_number(str);

    if(str[0] == 'r')
        transactions[variableIndex][dataItemTransectionSize[variableIndex]][1] = R;
    else
        transactions[variableIndex][dataItemTransectionSize[variableIndex]][1] = W;

    transactions[variableIndex][dataItemTransectionSize[variableIndex]][0] = transactionNumber;
    dataItemTransectionSize[variableIndex]++;



}


int getTransectionIndex(int transactionValue) {
    for(int i=0 ; i<total_number_of_transection ; i++){
        if(totalTransaction[i] == transactionValue)
            return i;
    }

    return -1;
}

void make_tree(int tree[T][T]) {
    int i,j,k;
    int origin, destin;

    for(i=0 ; i<numberOfDataItem ; i++) {
        for(j=0 ; j<dataItemTransectionSize[i] ; j++) {

            if(transactions[i][j][1] == W) {
                for(k=j+1 ; k<dataItemTransectionSize[i] ; k++) {

                    if(transactions[i][j][0] != transactions[i][k][0]) {
                        origin = getTransectionIndex(transactions[i][k][0]);
                        destin = getTransectionIndex(transactions[i][j][0]);

                        tree[origin][destin] = 1;
                    }
                }
            }
            else {
                for(k=j+1 ; k<dataItemTransectionSize[i] ; k++) {
                    if(transactions[i][j][0] != transactions[i][k][0]    &&   transactions[i][k][1] == W) {
                        origin = getTransectionIndex(transactions[i][k][0]);
                        destin = getTransectionIndex(transactions[i][j][0]);

                        tree[origin][destin] = 1;
                    }
                }
            }
        }
    }
}

void DFS(int currentNode, int state[T], int tree[T][T]) {
    state[currentNode] = VISITED;

    for(int i=0; i<total_number_of_transection ; i++) {
        if(tree[currentNode][i] == 1) {
            if(state[i] == INITIAL)
                DFS(i, state, tree);

            else if(state[i] == VISITED) {
                cout << "\nGraph is cyclic\n";
                cout << "Conflict Non-Cerializable" << endl;
                conflictSerializable = -1;
            }
        }
    }
    state[currentNode] = FINISHED;
}


void cycleDetect(int tree[T][T]) {
    int i;
    int state[total_number_of_transection];

    for(i=0; i<total_number_of_transection; i++)
        state[i] = INITIAL;

    DFS(0, state, tree);
    for(i=0 ; i<total_number_of_transection ; i++) {
        if(state[i] == INITIAL)
            DFS(i, state, tree);
    }

    if(conflictSerializable == 0) {
        printf("\nGraph is Acyclic\n");
        cout << "Conflict Cerializable" << endl;
        conflictSerializable = 1;
    }
}

int main(void) {
    string inputStr;

    // Read from the text file
    ifstream readFile("input.txt");
    while (getline (readFile, inputStr)) {
        make_transaction(inputStr);
    }
    readFile.close();


    int tree[100][100] = {0};

    make_tree(tree);
    cout<<endl<<endl;

    /*for(int i=0 ; i<numberOfDataItem ; i++){
        for(int j=0 ; j < dataItemTransectionSize[i] ; j++)
            cout << "variable = " << dataItem[i] << "  transection = " << transactions[i][j][0] << "  mode= " << transactions[i][j][1] << endl;
    }*/

    cycleDetect(tree);
}




