#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<long long> A, B, C, D;
vector<long long> AB, CD;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long tmp,tmp2;
			tmp = A[i] + B[j];
			tmp2 = C[i] + D[j];
			AB.push_back(tmp);
			CD.push_back(tmp2);
		}
	}
	sort(CD.begin(), CD.end());
	long long result = 0;
	for (int i = 0; i < N*N; i++)
	{
		long long target = AB[i];

		int sindex = lower_bound(CD.begin(), CD.end(), -target) - CD.begin();
		int eindex = upper_bound(CD.begin(), CD.end(), -target) - CD.begin();
	
		result += eindex - sindex;
	}

	cout << result;
}