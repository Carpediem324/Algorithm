#include<bits/stdc++.h>
using namespace std;

int K, P, N;
const int MOD = 1000000007;

int main(int argc, char** argv)
{
    cin >> K >> P >> N;

    unsigned long long res = K;
    for (int i = 0; i < N; i++) {
        res = (res * P) % MOD;
    }
    
    cout << res;
    return 0;
}
