#include <bits/stdc++.h>
using namespace std;

struct Node {
    int from;
    int to;
};

// 시작 시간을 기준으로 정렬하기 위한 비교 함수
struct cmp {
    bool operator() (Node a, Node b) {
        return a.from > b.from;
    }
};

priority_queue<Node, vector<Node>, cmp> pq; // 시작 시간을 기준으로 한 우선순위 큐
priority_queue<int, vector<int>, greater<int>> endTimes; // 끝나는 시간을 관리하는 우선순위 큐
int T;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int from, to;
        cin >> from >> to;
        pq.push({from, to});
    }
    
    int minRooms = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // 끝나는 시간 중 가장 빠른 시간보다 현재 강의의 시작 시간이 크거나 같으면 강의실 재사용 가능
        if (!endTimes.empty() && endTimes.top() <= current.from) {
            endTimes.pop();
        } else {
            // 새 강의실이 필요함
            minRooms++;
        }

        // 현재 강의의 끝나는 시간을 endTimes 큐에 추가
        endTimes.push(current.to);
    }

    cout << minRooms << '\n';
    return 0;
}
