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

