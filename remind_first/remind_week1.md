<h1> 1주차 복습 </h1>

# DAT
> Direct Access Table : 즉각 접근 자료구조
 
key 값을 배열의 인덱스로 사용하는 기법이다. 매우 유용하고 중요한 기법이다.
- 정렬이 자동으로 된다 (인덱스값으로 사용하기 때문에)

A,B,C,D,E를 E,D,C,B,A순으로 입력을 받았다 하자.

```c++
int dat[200];
char temp;
for(int i=0; i<5;i++){
    cin>>temp;
    dat[temp]++;
}
```

이렇게 된다면 dat배열에는 65,66,67,68,69번 인덱스의 값이 ++되었을 것이다.

- 최빈수 구하기가 정말 쉬워진다. 그냥 dat테이블에서 가장 큰 값의 인덱스가 최빈수다.

- for문을 하나 줄일 수 있다.(매우중요)

중요한 문제는 Problems에 추가한다.

- 공간차지를 많이한다. 하지만 이는 생각할 이유가 없다. 코딩테스트를 준비한다면 Time Limit이 매우 중요하기 때문이다.


# Direct
> 방향배열을 이용하여 전체 탐색하는 것이다.


## vector
- 크기할당 X,동적할당, -> 정적배열이 빠르다.
- <type> 탬플릿이라고한다.
- v.push_back(값)
- v.pop_back() : pop과 다르게 return은 없이 삭제만한다.
- v.clear() : 벡터를 비운다
- 사용자가 정의한 구조체도 벡터의 템플릿으로 이용할 수 있다.

## 방향배열

> 동서남북, y와 x의 이동을 배열로 만들어 사용한다.
- y,x 쌍의 구조체를 만들어 사용한다면 묶어서 사용하기 더 쉽다.

말보다는 문제로 보는게 더 이해하기 쉽다.

### 대각선값들의 합이 가장 큰 좌표 구하기
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int direct[4][2] = {
	{-1,-1},
	{1,-1},
	{-1,1},
	{1,1}
};

int MAP[5][5] = {
	{3, 3, 5, 3, 1},
	{2, 2, 4, 2, 6},
	{4, 9, 2, 3, 4},
	{1, 1, 1, 1, 1},
	{3, 3, 5, 9, 2}
};

struct Point
{
	int y;
	int x;
};

int sum(Point p) {
	int total=0;
	for (int i = 0; i < 4; i++)
	{
		int ny = p.y + direct[i][0]; 
		int nx = p.x + direct[i][1]; 


		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
			total += MAP[ny][nx];
		}
	}
	return total;
}
int main()
{
	Point st = { 0,0 };
	Point result;
	int maxvalue = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			st = { i,j };
			if (sum(st) > maxvalue) {
				maxvalue = sum(st);
				result = st;
			}
		}
	}
	cout << result.y << " " << result.x;

}
```


# cstring

# string

# vector

# Sort

# Greedy