#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R, X;
    cin >> N >> L >> R >> X;
    vector<int> problems(N);

    for (int i = 0; i < N; i++) {
        cin >> problems[i];
    }

    int answer = 0;
    int total_subsets = 1 << N; // 2^N개의 부분 집합

    for (int subset = 0; subset < total_subsets; subset++) {
        int sum = 0;
        int max_difficulty = 0;
        int min_difficulty = INT_MAX;
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (subset & (1 << i)) { // i번째 문제를 선택한 경우
                sum += problems[i];
                max_difficulty = max(max_difficulty, problems[i]);
                min_difficulty = min(min_difficulty, problems[i]);
                count++;
            }
        }

        if (count >= 2 && sum >= L && sum <= R && (max_difficulty - min_difficulty) >= X) {
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
    
}
