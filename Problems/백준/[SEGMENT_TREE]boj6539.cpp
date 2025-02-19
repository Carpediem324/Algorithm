// 거의못품

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<ll> numbers;     // 히스토그램의 높이들을 저장 (0-indexed)
vector<int> segtree;    // 각 구간에서 최소값을 갖는 인덱스를 저장

// 세그먼트 트리 초기화: node가 담당하는 구간 [start, end]에서 최소값의 인덱스를 구함.
int init(int node, int start, int end) {
    if (start == end) {
        return segtree[node] = start;
    }
    int mid = (start + end) / 2;
    int leftIndex = init(node * 2, start, mid);
    int rightIndex = init(node * 2 + 1, mid + 1, end);
    // 두 구간 중 더 작은 높이를 가진 인덱스를 저장
    if (numbers[leftIndex] <= numbers[rightIndex])
        segtree[node] = leftIndex;
    else
        segtree[node] = rightIndex;
    return segtree[node];
}

// 세그먼트 트리 쿼리: 구간 [l, r]에서 최소 높이를 가진 인덱스를 반환
int query(int node, int start, int end, int l, int r) {
    // 구간 밖이면 -1 반환
    if (r < start || end < l) return -1;
    if (l <= start && end <= r) return segtree[node];

    int mid = (start + end) / 2;
    int leftIndex = query(node * 2, start, mid, l, r);
    int rightIndex = query(node * 2 + 1, mid + 1, end, l, r);

    if (leftIndex == -1) return rightIndex;
    if (rightIndex == -1) return leftIndex;

    return (numbers[leftIndex] <= numbers[rightIndex]) ? leftIndex : rightIndex;
}

// 분할 정복을 이용하여 구간 [start, end]에서 만들 수 있는 최대 직사각형 넓이를 구함
ll getMaxArea(int start, int end) {
    if (start > end) return 0;
    // 구간 내 최소 높이를 가진 인덱스 구하기
    int index = query(1, 0, n - 1, start, end);
    // 현재 구간 전체를 덮는 직사각형의 넓이
    ll area = (ll)(end - start + 1) * numbers[index];
    // 최소값을 기준으로 좌우 구간에 대해 재귀적으로 최대 넓이 계산
    ll leftArea = getMaxArea(start, index - 1);
    ll rightArea = getMaxArea(index + 1, end);
    return max(area, max(leftArea, rightArea));
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 반복: 첫 번째 숫자가 0이면 종료
    while (true) {
        cin >> n;
        if (n == 0) break;

        numbers.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        // 세그먼트 트리 초기화: 트리 배열 크기는 최대 4*n
        segtree.assign(4 * n, 0);
        init(1, 0, n - 1);

        cout << getMaxArea(0, n - 1) << "\n";
    }

    return 0;
}
