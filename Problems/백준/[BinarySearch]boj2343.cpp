#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//M개의 블루레이
//블루레이의 크기를 최소로
// M개의 블루레이는 모두 같은 크기
int N, M;
vector<int> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int maxn = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		ans.push_back(temp);
		sum += temp;
		maxn = max(maxn, temp);
	}

	int left = maxn;
	int right = sum;

	while (left <= right) {
		int cnt = 0; //블루레이의 개수
		int sum = 0;
		int mid = (left + right)/2;
		for (int i = 0; i < N; i++)
		{
			sum += ans[i]; //다더해봐
			if (sum > mid) { //더한게  mid보다크면 다음블루레이로
				sum = ans[i]; //다음블루레이처음꺼
				cnt++; //개수추가
			}
		}

		if (sum > 0) {
			cnt++;
		}
		if (cnt > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		
	}
	cout << left;
}