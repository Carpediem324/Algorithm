//boj 12738 가장 긴 증가하는 부분 수열 3
// 첫수를 집어넣고
// 다음들어올수가 첫수보다 크면 그냥넣고
// 작으면 lower바운드로 집어넣어서 바꿔치기한다.
// 이게전분가? 작은수를 갱신해서 끝낸다.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int N;
vector<int> v;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	vector<int> res;
	res.push_back(v[0]);
	
	for (int i = 1; i < N; i++)
	{
		int next = v[i];
		int count = res.size() - 1; //res의 사이즈가변하니까
		if (res[count] < next) {
			res.push_back(next);
		}
		else {
			int pose = lower_bound(res.begin(), res.end(), next) - res.begin();
			res[pose] = next;
		}


	}
	cout << res.size();
}