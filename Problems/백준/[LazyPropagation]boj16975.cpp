#define _CRT_SECURE_NO_WARNINGS
//BOJ 16975 수열과 쿼리 21
//컨셉 Lazy Propation
// 구간의 합을 누적해놓고 (즉각반영 X)
// 출력할 때만 그때 그때더함.
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <string>
using namespace std;
#define NUMBER 100001
long long numbers[NUMBER];
long long tree[4 * NUMBER]; // 각 노드에 구간 업데이트 값을 저장 (lazy)

int N, M;

// [start, end] 구간이 현재 노드의 구간이고, [l, r]에 k를 더하는 함수
void update_seg(int start, int end, int node, int l, int r, long long k) {
    if (r < start || end < l) return;  // 업데이트 구간과 겹치지 않으면 리턴
    if (l <= start && end <= r) {        // 현재 구간이 완전히 포함되면
        tree[node] += k;                 // lazy 값 누적 (자식으로 바로 전파하지 않음)
        return;
    }
    int mid = (start + end) / 2;
    update_seg(start, mid, node * 2, l, r, k);
    update_seg(mid + 1, end, node * 2 + 1, l, r, k);
}

// index에 해당하는 값을 구하는 함수 (루트부터 내려오며 누적된 lazy 값을 합산)
long long query(int start, int end, int node, int index) {
    if (index < start || index > end) return 0; // 호출 시에는 해당되지 않음
    long long ret = tree[node];  // 현재 노드의 lazy 값 (이 구간 전체에 적용되는 업데이트)
    if (start == end)
        return ret;
    int mid = (start + end) / 2;
    if (index <= mid)
        ret += query(start, mid, node * 2, index);
    else
        ret += query(mid + 1, end, node * 2 + 1, index);
    return ret;
}

int main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> numbers[i];
    }
    
    cin >> M;
    for (int i = 0; i < M; i++){
        int type;
        cin >> type;
        if(type == 1){ // 구간 [a, b]에 k를 더함
            int a, b;
            long long k;
            cin >> a >> b >> k;
            update_seg(0, N - 1, 1, a - 1, b - 1, k);
        }
        else if(type == 2){ // 특정 인덱스 a의 최종 값을 출력
            int a;
            cin >> a;
            long long addVal = query(0, N - 1, 1, a - 1);
            cout << numbers[a - 1] + addVal << '\n';
        }
    }
    
    return 0;
}
