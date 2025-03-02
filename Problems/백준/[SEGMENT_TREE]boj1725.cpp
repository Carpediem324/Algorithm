#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int numbers[100001];   // 히스토그램 높이 배열
int tree[400001];      // 세그먼트 트리
int N;

// 세그먼트 트리 초기화 (최소값을 저장)
int init(int start, int end, int node) {
    if (start == end) return tree[node] = start; // 인덱스를 저장
    int mid = (start + end) / 2;
    int leftIdx = init(start, mid, node * 2);
    int rightIdx = init(mid + 1, end, node * 2 + 1);

    return tree[node] = min(leftIdx, rightIdx, [](int a, int b) {
        return numbers[a] < numbers[b];
        });
}

// 구간 최소 높이 인덱스 찾기
int findmin(int start, int end, int node, int left, int right) {
    if (end < left || right < start) return -1; // 범위를 벗어남
    if (left <= start && end <= right) return tree[node]; // 최소값의 인덱스 반환

    int mid = (start + end) / 2;
    int leftIdx = findmin(start, mid, node * 2, left, right);
    int rightIdx = findmin(mid + 1, end, node * 2 + 1, left, right);

    if (leftIdx == -1) return rightIdx;
    if (rightIdx == -1) return leftIdx;
    return min(leftIdx, rightIdx, [](int a, int b) {
        return numbers[a] < numbers[b];
        });
}

// 특정 인덱스의 값을 변경하고 세그먼트 트리를 업데이트
int update(int start, int end, int node, int index, int newValue) {
    if (index < start || index > end) return tree[node]; // 범위 밖이면 현재 값 유지

    if (start == end) { // 리프 노드 도착 (값 변경)
        numbers[index] = newValue;
        return tree[node] = start; // 인덱스를 그대로 저장
    }

    int mid = (start + end) / 2;
    int leftIdx = update(start, mid, node * 2, index, newValue);
    int rightIdx = update(mid + 1, end, node * 2 + 1, index, newValue);

    return tree[node] = min(leftIdx, rightIdx, [](int a, int b) {
        return numbers[a] < numbers[b];
        });
}

// 히스토그램에서 가장 큰 직사각형 넓이 구하기 (재귀)
long long getMaxArea(int left, int right) {
    if (left > right) return 0;

    int minIndex = findmin(0, N - 1, 1, left, right);
    long long maxArea = (long long)numbers[minIndex] * (right - left + 1);

    long long leftArea = getMaxArea(left, minIndex - 1);
    long long rightArea = getMaxArea(minIndex + 1, right);

    return max({ maxArea, leftArea, rightArea });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    init(0, N - 1, 1);

    cout << "초기 최대 직사각형 넓이: " << getMaxArea(0, N - 1) << '\n';

    // 예제: 2번 인덱스 값을 10으로 변경
    update(0, N - 1, 1, 2, 10);
    cout << "업데이트 후 최대 직사각형 넓이: " << getMaxArea(0, N - 1) << '\n';

    return 0;
}
