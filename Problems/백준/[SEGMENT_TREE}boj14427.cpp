#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

typedef long long ll;
// (값, 인덱스) 형태를 저장할 세그먼트 트리
// 인덱스는 0-based로 저장 후 출력 시 +1
pair<ll, int> segtree[400001];
ll numbers[100001];
int N, M;

// 두 노드(p, q)를 비교해 최소값, 그 인덱스를 리턴
// 값이 같으면 인덱스가 더 작은 쪽을 채택
pair<ll, int> cmp(pair<ll, int> p, pair<ll, int> q) {
    if (p.first == q.first) {
        return (p.second < q.second ? p : q);
    }
    else {
        return (p.first < q.first ? p : q);
    }
}

// 세그먼트 트리 초기화
pair<ll, int> init(int start, int end, int node) {
    if (start == end) {
        // 리프 노드는 (numbers[start], start) 저장
        return segtree[node] = make_pair(numbers[start], start);
    }
    int mid = (start + end) / 2;
    pair<ll, int> leftVal = init(start, mid, node * 2);
    pair<ll, int> rightVal = init(mid + 1, end, node * 2 + 1);
    // 더 작은 값, 혹은 인덱스가 작은 쪽
    return segtree[node] = cmp(leftVal, rightVal);
}

// 세그먼트 트리 갱신
pair<ll, int> update(int start, int end, int node, int idx, ll val) {
    // 범위 밖
    if (idx < start || idx > end) return segtree[node];
    // 리프 노드(단일 구간)
    if (start == end) {
        return segtree[node] = make_pair(val, start);
    }
    int mid = (start + end) / 2;
    pair<ll, int> leftVal = update(start, mid, node * 2, idx, val);
    pair<ll, int> rightVal = update(mid + 1, end, node * 2 + 1, idx, val);
    return segtree[node] = cmp(leftVal, rightVal);
}

// 구간 [left, right] 최솟값/인덱스 조회 (여기서는 전 구간 사용)
pair<ll, int> query(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        // 비교에 방해되지 않도록 (아주 큰 값, 큰 인덱스)
        return make_pair(LLONG_MAX, INT_MAX);
    }
    if (left <= start && end <= right) {
        return segtree[node];
    }
    int mid = (start + end) / 2;
    pair<ll, int> leftVal = query(start, mid, node * 2, left, right);
    pair<ll, int> rightVal = query(mid + 1, end, node * 2 + 1, left, right);
    return cmp(leftVal, rightVal);
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    // 세그먼트 트리 초기화
    init(0, N - 1, 1);

    cin >> M;
    while (M--) {
        int type; cin >> type;
        if (type == 1) {
            int index; ll change;
            cin >> index >> change;
            // 0-based로 맞춰서 업데이트
            index -= 1;
            numbers[index] = change;
            update(0, N - 1, 1, index, change);
        }
        else if (type == 2) {
            // 세그먼트 트리 전체 구간에서 최솟값의 인덱스 찾기
            pair<ll, int> ans = query(0, N - 1, 1, 0, N - 1);
            // 인덱스는 0-based로 들고 있으니 +1
            cout << ans.second + 1 << "\n";
        }
    }
    return 0;
}
