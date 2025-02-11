#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
long long v[1000001];
long long tree[4000004];

// 세그먼트 트리 초기화
long long seg_init(int start, int end, int node) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = seg_init(start, mid, node * 2) + seg_init(mid + 1, end, node * 2 + 1);
}

// 구간 합 계산
long long seg_sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0; // 범위 밖
    if (left <= start && end <= right) return tree[node]; // 범위 안
    int mid = (start + end) / 2;
    return seg_sum(start, mid, node * 2, left, right) + seg_sum(mid + 1, end, node * 2 + 1, left, right);
}

// 값 업데이트
void seg_update(int start, int end, int node, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    seg_update(start, mid, node * 2, index, diff);
    seg_update(mid + 1, end, node * 2 + 1, index, diff);
}

// 입력 처리
void input() {
    cin >> N >> M >> K;


    for (int i = 0; i < N; i++) {
        cin >> v[i]; // push_back 사용하지 않음 (메모리 할당 최적화)
    }

    seg_init(0, N - 1, 1); // 세그먼트 트리 초기화

    int query_count = M + K;
    for (int i = 0; i < query_count; i++) {
        int types;
        cin >> types;

        if (types == 1) { // 값 변경
            int numbers;
            long long changenum;
            cin >> numbers >> changenum;
            numbers--; // 인덱스 변환
            long long dif = changenum - v[numbers]; // 차이 계산
            v[numbers] = changenum; // 값 갱신
            seg_update(0, N - 1, 1, numbers, dif);
        }
        else if (types == 2) { // 구간 합 계산
            int from, to;
            cin >> from >> to;
            from--; to--; // 인덱스 변환
            cout << seg_sum(0, N - 1, 1, from, to) << "\n"; // '\n' 대신 "\n" 사용해 속도 개선
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    input();
}
