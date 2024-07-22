# 매일 알고리즘 정리
## 2024.07-26 (금)

## 2024.07-25 (목)

## 2024.07-24 (수)

## 2024.07-23 (화)
> 테스트

## 2024.07-22 (월) D.A.T
> sort함수는 char array가 꽉차있으면 에러가 난다. 15개가 꽉차있다면 16으로 사이즈를 정해 제일 끝 칸을 비워야한다.
### 1) DAT를 안쓰고 배열의 알파뱃 종류를 찾아내는 코드를 작성하세요
"A, D, B, F, A, D"
> 나의 답
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char arr[7] = { "ADBFAD" };

int main() {
	//freopen("input.txt", "r", stdin);
	char result[7] = { 0 };
	int isalreadydone[7] = { 0 };
	int counting = 0;
	bool flag;
	for (int j = 'A'; j < 'Z'; j++)
	{
		for (int i = 0; i < strlen(arr); i++)
		{
			flag = false;
			if (j == arr[i]) {
				for (int p = 0; p < 7; p++)
				{
					if (j == isalreadydone[p]) {
						flag = true;
					}
				}
				if (flag == false) {
					cout << arr[i]<<" ";
					isalreadydone[counting] = arr[i];
					counting++;
				}
			}
		}
	}
}
```
>알파벳 A~Z 까지 체크하고 이미체크한건 is alreadydone배열에 추가하여 isalreadydone배열을 추가로 확인하도록 하여 flag로 다시 안나오게 한다는 컨셉.

> 정답
```c++
#include <iostream>

using namespace std;

char arr[10] = "ADBFAD";

int main()
{
    for (int i = 0; arr[i] != '\0'; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i];
        }
    }
    return 0;
}
```
>2중 포문으로 체크하는 방법. 비효율적

### DAT면 1중 포문으로 해결할 수 있다.
문자도 index로 쓸 수 있다.

A = 65 ~ Z = 90

a = 97 ~ z = 122

### D.A.T Direct Access Table
즉각 접근 자료구조

> 값을 인덱스로 사용하는 자료구조

```c++
#include <iostream>

using namespace std;

char arr[10] = "ADBFAD";
int result[100] = { 0 };
int main()
{

	for (int i = 0; i < strlen(arr); i++)
	{
		result[arr[i]]++;
	}

	for (int i = 0; i < 100; i++)
	{
		if (result[i] >= 1) {
			cout << char(i);
		}
	}
}
```
### 뭐가 좋아졌나?
- 2중 for문 -> 1중 for문
- 정렬이 자동으로 된다.
- 직관적이다.
- 배열이 길어지면 차이는 더 커진다.
### 뭐가 안좋나?
- 메모리낭비(공간낭비)

### 2) 4 1 1 1 5 4 각각의 숫자가 몇개인지 출력하시오

```c++
#include <iostream>

using namespace std;

int arr[6] = { 4, 1, 1, 1, 5, 4 };
int result[10] = { 0 };
int main()
{
	for (int i = 0; i < 6; i++)
	{
		result[arr[i]]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (result[i] > 0) {
			cout << i << ":" << result[i] << "개\n";
		}
	}
}
```
### 3) 8글자의 대문자 알파벳으로 구성된 문장을 입력 하세요. 입력한 문장에서 가장 많이 사용된 알파벳을 출력하세요.

```c++
#include <iostream>

using namespace std;

char arr[8];
int DAT[150];

int main()
{
    cin >> arr;

    for (int i = 0; i < 8; i++)
    {
        DAT[arr[i]]++;
    }

    int maxIdx = 0;

    for (int i = 65; i < 150; i++)
    {
        if (DAT[maxIdx] < DAT[i])
        {
            maxIdx = i;
        }
    }

    cout << (char)(maxIdx);

    return 0;
}
```

### 4) 5 x 3에 채워진 알파벳을 정렬하여 한 줄로 공백 없이 출력합니다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char alphabet[5][3] = {
	{'A', 'B', 'C'},
	{'A', 'G', 'H'},
	{'H', 'I', 'J'},
	{'K', 'A', 'B'},
	{'A', 'B', 'C'}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	char result[16] = { 0 };
	int bucket[100] = { 0 };
	int counting = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[counting] = alphabet[i][j];
			counting++;

			bucket[alphabet[i][j]]++;
		}
	}
	sort(&result[0], &result[0] + 15);

	cout << result;
	cout << '\n';

	for (int i = 0; i < 100; i++)
	{
		if (bucket[i] > 0) {
			cout << char(i);
			bucket[i] -= 1;
			i = 0;
		}
	}	
}
```
> 두가지 방법으로 해결.

- sort함수를 이용 -> 반드시 \n들어갈 사이즈 키워야함. 그래야 sorting 에러안뜸.

- dat이용. bucket[i]의 값만큼 반복문.

### 5) 카운팅 값 찾기
- 1~9사이의 정수 N 1개를 입력 받습니다.
- 5 x 3 의 정수 배열 내에서 N개가 존재하는 숫자를 출력합니다.

만약 N개가 존재하는 숫자가 두 개 이상이라면, 오름차순으로 출력합니다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[3][5] = {
	1,3,3,5,1,
	3,6,2,4,2,
	1,9,2,6,5
};

int bucket[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	int x;
	cin >> x;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			bucket[arr[i][j]]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (bucket[i] == x) {
			cout << i<<" ";
		}
	}
}
```

### 중요 * DAT2개문제

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int apt[1001][1001];
int black[1001][1001];
int ay, ax;
int by, bx;
int bucket[100001];
int blackbucket[100001];
int maxcount;
int blackman;
int whiteman;

void input() {
	cin >> ay >> ax;
	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			cin >> apt[i][j];
		}
	}
	cin >> by >> bx;
	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			cin >> black[i][j];
		}
	}
}

void process() {
	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			bucket[apt[i][j]]++;
		}
	}

	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			blackbucket[black[i][j]]=1;
		}
	}
}

int main()
{

	//freopen("input.txt", "r", stdin);
	input();
	maxcount = ay * ax;
	process();
	int flag = false;
	
	int count = 0;

	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			if (blackbucket[apt[i][j]] == 1) {
				blackman++;
			}
		}
	}

	cout << blackman << '\n';
	cout << ay*ax- blackman;

}
```

### 중요 *키순으로 카드번호 확인 

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int T;
int N;
int k[1000001];
int keys[1000001];

int bucket[251];
int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int test = 0; test < T; test++)
	{
		memset(bucket, 0, sizeof(bucket));
		memset(k, 0, sizeof(k));
		memset(keys, 0, sizeof(keys));
		//입력부///////////////
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> k[i];
			bucket[k[i]]++;
		}
		for (int i = 0; i < N; i++)
		{

			cin >> keys[i];
		}
		/////////////////////////

		bool isok = false;
		int total = 0;
		for (int i = 251; i >= 0; i--)
		{
			if (bucket[i] > 0) { //i=232

				for (int p = 0; p < N; p++) 
				{
					if (k[p] == i) { //i=232 ,k[p] =232
						if (total < keys[p]  && keys[p] <= total + bucket[i]) {
							isok = true;
						}
						else {
							isok = false;
							break;
						}
					}
				}
				total = total + bucket[i];
				if (isok == false) {
					break;
				}
			}
		}


		//출력부
		if (test == T - 1) {
			if (isok) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			if (isok) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}

	}
}
```

>위 방법은 단순하게 생각해서 푼거다 하지만 251*N번돈다
>아래는 정답이다. 최대 O(n);

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T, N;
int DAT[1000001];
int heights[1000001];
int nums[1000001];

void init()
{
	memset(DAT, 0, sizeof(DAT));
}

void input()
{
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
}

bool isSortedDesc()
{
	int minVal = 999999;
	for (int i = 1; i <= N; i++)
	{
		if (minVal >= DAT[i])
		{
			minVal = DAT[i];
			continue;
		}
		return false;
	}
	return true;
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		init();
		input();

		for (int i = 0; i < N; i++)
		{
			DAT[nums[i]] = heights[i];
		}

		bool ret = isSortedDesc();
		if (ret)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
```