#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	string arr;
	string temp;
	cin >> arr;
	int count = 0;
	size_t pos = 0;
	while (true) {
		temp = { 0 };
		count++;
		if (arr.find('_',pos) == string::npos) {
			break;
		}
		int i = 0;
		while (arr[arr.find('_', pos) + i] != '_') {
			i++;
		}
		temp = arr.substr(pos, arr.find('_', pos));

		pos = arr.find('_', pos);
		cout <<count<<"#"<<temp<<'\n';

	}
}
