#include<bits/stdc++.h>
using namespace std;

union  binary_representation_of_N {
    unsigned int length;
    unsigned char x[16];
};

void messageTo_Nx1024(string *str, unsigned int length) {
    int len = length%1024, numberOfZero;
    string s;
    if(len < 896) {
        // Padding 10000000
        *str += 0x80;
        // Padding 0's till length 896
        for(int i=len+1 ; i<=896 ; i+=8) *str += 0x00;
    }
    else {

    }
}

int main(void) {
    string mess = "";

    messageInput(&mess, "text.txt");
    cout << "Main message: " << mess << endl << endl << endl;
    messageTo_Nx1024(&mess, mess.length());
    int length = mess.length();
    unsigned char message[length+1];
    for(int i=0 ; i<length ; i++) {
        message[i] = mess[i];
    }
}
