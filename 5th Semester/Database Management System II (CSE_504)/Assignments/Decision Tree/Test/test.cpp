#include <bits/stdc++.h>
using namespace std;

float log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}

// Driver code
int main()
{
    int a = 3;
    int b = 2;
    cout << log_a_to_base_b(a, b) << endl;

    a = 256;
    b = 4;
    cout << log_a_to_base_b(a, b) << endl;

    return 0;
}
