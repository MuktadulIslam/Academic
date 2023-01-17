#include<bits/stdc++.h>
using namespace std;

int main(void) {
    vector<pair<int,int>> v;
    v.push_back(make_pair(2,3));
    v.push_back(make_pair(20,33));
    for(int i = 0; i < v.size(); i++)
{
     cout << v[i].first<< "  " << v[i].second << endl;
}
}
