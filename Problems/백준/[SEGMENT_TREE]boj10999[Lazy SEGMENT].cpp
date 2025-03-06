#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001; // 더 큰 값으로 안전하게 설정
long long numbers[MAX];
long long tree[4 * MAX];
long long lazy[4 * MAX];

// 세그먼트 트리 초기화
long long init(int start, int end, int node) {
    if (start == end) 
        return tree[node] = numbers[start];

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// Lazy Propagation 적용
void propagate(int start, int end, int node) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// 구간 합 계산
long long query(int start, int end, int node, int left, int right) {
    propagate(start, end, node);
    if (right < start || end < left)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

// 구간 업데이트
void update(int start, int end, int node, int left, int right, long long value) {
    propagate(start, end, node);
    if (right < start || end < left)
        return;

    if (left <= start && end <= right) {
        lazy[node] += value;
        propagate(start, end, node);
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, left, right, value);
    update(mid + 1, end, node * 2 + 1, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    init(0, N - 1, 1);

    int total_operations = M + K;
    while (total_operations--) {
        int type;
        cin >> type;

        if (type == 1) { // 구간 업데이트
            int b, c;
            long long d;
            cin >> b >> c >> d;
            update(0, N - 1, 1, b - 1, c - 1, d);
        }
        else if (type == 2) { // 구간 합 출력
            int b, c;
            cin >> b >> c;
            cout << query(0, N - 1, 1, b - 1, c - 1) << '\n';
        }
    }
}
