#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int word;

word W[80];

const word roundConstants[80]
    = { 0x428a2f98d728ae22, 0x7137449123ef65cd,
        0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019,
        0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe,
        0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
        0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
        0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
        0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210,
        0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725,
        0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926,
        0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8,
        0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001,
        0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910,
        0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
        0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
        0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60,
        0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9,
        0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207,
        0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6,
        0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493,
        0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
        0x5fcb6fab3ad6faec, 0x6c44198c4a475817 };

void messageInput(string *message, string fileName) {
    ifstream readFile;
    readFile.open(fileName);
    char str[5001];
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            readFile.getline(str,5000);
            *message += str;
        }
    }
    readFile.close();
}

void messageTo_Nx1024(string *str, unsigned int length) {
    int len = length%(1024/8), numberOfZero;
    string s;
    if(len > 896/8) {
        unsigned int l = (2048 - 128)/8;
        // Padding 10000000
        *str += 0x80;
        length++;
        // Padding 0's untill last 128's bit
        while(length < l) {
            *str += '\0';
            length++;
        }
    }
    else{
        // Padding 10000000
        *str += 0x80;
        // Padding 0's untill last 128's bit
        for(int i=len+1 ; i<(896/8) ; i++) *str += '\0';
    }

    // Padding last 128's bit with the binary value of the length of the string
    union  binary_representation {
        unsigned int n;
//        unsigned int n[8] = {};
        unsigned char ch[16];
    } x;

    x.n = length;
    for(int i=15 ; i>=0 ; --i) {
        *str += x.ch[i];
    }
    cout << endl;
}

word sigma0_function(word w) {
    return ((w >> 1) | (w << 64-1)) ^ ((w >> 8) | (w << 64-8)) ^ (w << 7);
}
word sigma1_function(word w) {
    return ((w >> 19) | (w << 64-19)) ^ ((w >> 61) | (w << 64-61)) ^ (w << 6);
}
word sigmaA_function(word w) {
    return ((w >> 28) | (w << 64-28)) ^ ((w >> 34) | (w << 64-34)) ^ ((w >> 39) | (w << 64-39));
}
word sigmaE_function(word w) {
    return ((w >> 14) | (w << 64-14)) ^ ((w >> 18) | (w << 64-18)) ^ ((w >> 41) | (w << 64-41));
}
word ch_function(word a, word b, word c){
    return ( (a & b) ^ (~a & c));
}
word maj_function(word a, word b, word c){
    return ( (a & b) ^ (b & c) ^ (c & a) );
}


void wordExpantion(unsigned char str[]) {
    union  binary_representation {
        word w;
        unsigned char ch[8];
    } x;

    int i,j;
    // first 16 Word are storing directly in W
    for(i=0 ; i<16 ; i++) {
        for(int j=0 ; j<8 ; j++)
            x.ch[7-j] = str[i*8 + j];

        W[i] = x.w;
//        cout << hex << W[i] << endl;
    }

    for(int i=16 ; i<80 ; i++) {
        W[i] = sigma1_function(W[i-2]) + W[i-7] + sigma0_function(W[i-15]) + W[i-16];
//        cout << hex << W[i] << endl;
    }
//    cout << endl;
}

void SHA_512(unsigned char str[], int lenght, word hashValue[8]) {
    int roundNumber = lenght/1024;
    int i,j,k;
    word temp1, temp2, tempHV[8];

    // initializing hashValue registers
    hashValue[0] = 0x6a09e667f3bcc908;
    hashValue[1] = 0xbb67ae8584caa73b;
    hashValue[2] = 0x3c6ef372fe94f82b;
    hashValue[3] = 0xa54ff53a5f1d36f1;
    hashValue[4] = 0x510e527fade682d1;
    hashValue[5] = 0x9b05688c2b3e6c1f;
    hashValue[6] = 0x1f83d9abfb41bd6b;
    hashValue[7] = 0x5be0cd19137e2179;

    wordExpantion(str);

//    for(i=0 ; i<numberOfRound ; i++) {
//
//    }

    for(roundNumber=0 ; roundNumber<80 ; roundNumber++) {
        for(i=0 ; i<8 ; i++)
            tempHV[i] = hashValue[i];

        temp1 = ch_function(hashValue[4], hashValue[5], hashValue[6]) ^ sigmaE_function(hashValue[4]) ^
            W[roundNumber] ^ roundConstants[roundNumber] ^ hashValue[7];
        temp2 = sigmaA_function(hashValue[0]) ^ maj_function(hashValue[0], hashValue[1], hashValue[2]) ^ temp1;

        hashValue[7] = hashValue[6] + tempHV[7];
        hashValue[6] = hashValue[5] + tempHV[6];
        hashValue[5] = hashValue[4] + tempHV[5];
        hashValue[4] = hashValue[3] + temp1 + tempHV[4];
        hashValue[3] = hashValue[2] + tempHV[3];
        hashValue[2] = hashValue[1] + tempHV[2];
        hashValue[1] = hashValue[0] + tempHV[1];
        hashValue[0] = temp2 + tempHV[0];
    }
}

int main(void) {
    string mess = "";

    messageInput(&mess, "text.txt");
    cout << "Main message: " << mess << endl << endl;
    messageTo_Nx1024(&mess, mess.length());
    int length = mess.length();
    unsigned char message[length+1];
    cout << length <<  endl;
    for(int i=0 ; i<length ; i++) {
        message[i] = mess[i];
        printf("%x  ", (int)mess[i]);
        if((i+1) %8 == 0) cout << endl;
    }
//    cout << endl;

    word hash_value[8];
    SHA_512(message, length, hash_value);
    cout << "SHA-512 Hash Value:  ";
    for(int i=0 ; i<8 ; i++)
        cout << hex << uppercase << hash_value[i];
}
