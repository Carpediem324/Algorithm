#include <bits/stdc++.h>
using namespace std;

struct Node {
    int now;
    int dice;
};

int N, M;
vector<int> ladder[101]; // 사다리와 뱀 정보
int visited[101]; // 방문 여부 및 최소 주사위 횟수 저장

int main() {
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int from, to;
        cin >> from >> to;
        ladder[from].push_back(to);
    }

    fill(&visited[0], &visited[0] + 101, 21e8); // 방문 배열 초기화
    visited[1] = 0; // 시작 위치는 주사위를 던지지 않음
    queue<Node> q;
    q.push({1, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        // 현재 위치가 100이면 종료
        if (now.now == 100) {
            cout << now.dice << '\n';
            return 0;
        }

        // 주사위를 굴려서 1부터 6까지의 이동을 시도
        for (int i = 1; i <= 6; i++) {
            int next = now.now + i;
            if (next > 100) continue; // 100번 칸을 넘으면 무시

            // 사다리나 뱀이 있는 경우 처리 무조건타야함. 안탈수가없음.
            if (!ladder[next].empty()) {
                next = ladder[next][0]; // 사다리나 뱀을 타고 이동
            }

            // 아직 방문하지 않았거나 더 적은 횟수로 도달할 수 있는 경우
            if (visited[next] > now.dice + 1) {
                visited[next] = now.dice + 1;
                q.push({next, now.dice + 1});
            }
        }
    }

    return 0;
}
