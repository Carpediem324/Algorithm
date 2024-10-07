#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100001];

int main(void) {


    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {//N개입력받고
        cin >> arr[i];
    }
    
    int start = 0, end = 0;//시작 끝
    int sum = arr[0];//합
    int ans = INT_MAX;
    while (start <= end && end <= N) {
        if (sum >= S) {//합계가작으면
            ans = min(ans, end - start + 1);
        }
        if (sum < S) {
            end++;
            sum += arr[end];
        }
        else {
            sum -= arr[start];
            start++;
        }
    }
    if (ans == INT_MAX) {
        cout << 0 << '\n';
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}