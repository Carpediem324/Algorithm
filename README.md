# 코테 준비하면서 배운 알고리즘

## 1. Direct Address Table (D.A.T.)

데이터를 주소(인덱스)로 직접 입력하는 기법이다

```c++
char A[10] = {"ABCDEAA"};
int result[100] = {0};
for(int i;i<strlen(A);i++){
    result[A[i]]++;
}

cout<<result
//result[65]=3 A
//result[66]=1 B
//result[67]=1 C
//result[68]=1 D
//result[69]=1 E
```

- 대표적으로 가장 많은 갯수 구하기
- 패턴구하기 

## 2.  Direct Coding

네 방향 Offset 상, 하, 좌, 우 이동

```c++
int direct[4][2] ={  // dirrect 배열 저장.
    {-1, 0}, //up
    {1 , 0}, //down
    {0 ,-1}, //left
    {0 , 1} //right
}

for(i=0;i<4;i++){
    dy = y + direct[i][0];
    dx = x + direct[i][1];

    sum += data[dy][dx];
}
```

 - 범위 넘어가는 오버플로우 방지

 ```c++
 for(i=0;i<4;i++){
    dy = y + direct[i][0];
    dx = x + direct[i][1];

    if(dy>=0 && dy<4 && dx>=0 && dx<4>)
    {
        sum += data[dy][dx];
    }
}
```
### Direct 사용 예제

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int arr[3][3] = {
		3,5,4,
		1,1,2,
		1,3,9
	};
	int y, x;
	cin >> y >> x;
	int direct[4][2] = {
		{-1,0},
		{1,0},
		{0,-1},
		{0,1}
	};
	int total = 0;
	int dy, dx;
	dy = y;
	dx = x;
	for (int i = 0; i < 4; i++)
	{
		dy = y + direct[i][0];
		dx = x + direct[i][1];
		if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3) {
			total += arr[dy][dx];
		}
	}
	cout << total;
}
```

## 재귀호출 Recursive Call

> 함수 안에서 자기 자신을 호출하는 함수,     재귀함수를 이용한 코딩 기법을 배우게 됨

### abc(x+1)

1. x + 1 값을 abc함수로 보냄

2. x 변수값을 바꾸지 않는다.

### abc(x++)

1. x값을 그대로 보냄

2. 보낸뒤 x변수에 1추가

## 예시) n번 재귀호출하기

```c++
#include <iostream>
using namespace std;

int vect[5] = { 8, 7, 1, 2, 3};
void bbq(int level){
	cout<<level;
	if(level == 5){
		return;
	}
	cout<<vect[level];
	bbq(level + 1);
	cout<<vect[level];
}

int main(){
	bbq(0);

	return 0;
}
```

> 실행결과 :8712332178

## 예시) 입력받은 레벨까지 재귀함수 동작
입력: 2

출력: 0122122

```c++
#include<iostream>
using namespace std;

int limit;
void run(int level) {
	cout << level;
	if (level == limit) {
		return;
	}
	run(level + 1);
	run(level + 1);

	return;
}
int main()
{
	cin >> limit;
	run(0);
	return 0;
}
```
> 엄청 쉬운건데 생각하기 쉽지않음...

## strlen, strcpy, strcmp 사용하기

### 긴문장을 제일 앞으로
```c++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char vect[3][11];
	int len;
	int maxlen;
	int maxIndex;

	//세 문장 입력
	for (int i = 0; i < 3; i++)
	{
		cin >> vect[i];
	}

	//가장 긴 문장 찾기
	maxlen = -1;
	for (int i = 0; i < 3; i++)
	{
		len = strlen(vect[i]);
		if (maxlen < len)
		{
			maxlen = len;
			maxIndex = i;
		}
	}

	//1번과 가장긴 문장 교환
	char temp[11];

	strcpy(temp, vect[maxIndex]);
	strcpy(vect[maxIndex], vect[0]);
	strcpy(vect[0], temp);


	for (int i = 0; i < 3; i++)
	{
		cout << vect[i] << endl;
	}

	return 0;
}
```

