#include <bits/stdc++.h>
using namespace std;

int M;
int S = 0; // 비트마스킹을 위한 변수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for (int i = 0; i < M; i++) {
        string order;
        cin >> order;
        
        if (order == "all") {
            S = (1 << 21) - 1; // 1부터 20까지 모든 비트를 1로 설정
        } else if (order == "empty") {
            S = 0; // 모든 비트를 0으로 초기화
        } else {
            int temp;
            cin >> temp;
            if (order == "add") {
                S |= (1 << temp); // temp번째 비트를 1로 설정
            } else if (order == "remove") {
                S &= ~(1 << temp); // temp번째 비트를 0으로 설정
            } else if (order == "check") {
                cout << ((S & (1 << temp)) ? "1\n" : "0\n");
            } else if (order == "toggle") {
                S ^= (1 << temp); // temp번째 비트를 반전
            }
        }
    }

    return 0;
}
