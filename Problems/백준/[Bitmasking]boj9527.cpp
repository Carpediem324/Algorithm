#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

// 0부터 n까지의 모든 수에서 1의 개수를 계산하는 함수
ll countOnesUpTo(ll n) {
    ll sum = 0;
    // 63비트까지 확인 (ll 타입)
    for (int i = 0; i < 63; i++) {
        ll cycle = 1LL << (i + 1);        // 한 주기의 길이: 2^(i+1)
        ll fullCycles = (n + 1) / cycle;    // 전체에서 완전한 주기의 개수
        sum += fullCycles * (1LL << i);     // 각 주기마다 i번째 비트의 1은 2^i번 등장

        // 완전한 주기 이후 남은 부분에서의 1의 개수 계산
        ll remainder = (n + 1) % cycle;
        sum += max(0LL, remainder - (1LL << i));
    }
    return sum;
}

int main() {
    ll A, B;
    cin >> A >> B;

    // 구간 [A, B]의 1의 총 개수는 0부터 B까지의 1의 개수에서 0부터 A-1까지의 1의 개수를 빼면 됩니다.
    ll answer = countOnesUpTo(B) - (A ? countOnesUpTo(A - 1) : 0);

    cout << answer << "\n";
    return 0;
}
