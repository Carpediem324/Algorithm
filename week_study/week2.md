# 매일 알고리즘 정리
## 2024.08-02 (금) BFS 넓이우선탐색

## 2024.08-01 (목) DFS2

## 2024.07-31 (수) DFS1

## 2024.07-30 (화) 백트래킹2

백트래킹 - 결과를 알고 재귀함수의 탈출조건을 마련하는 것이 백트래킹이라고 생각...

###복습1: 주사위를 N번 던져서 M에 따른결과 출력

> 주사위, 카드문제는 기본 중에 기본이다. 
 
> 잊지 않도록 반복학습하자.
```c++
#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int M;
int N;
int dice[6] = { 1,2,3,4,5,6 };
int path[10] = { -1 };
int isvisited[6];
void func(int level, int M)
{
	if (level == N) {
		for (int i = 0; i < N; i++) //Path에 저장된 내 길을 출력
		{
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	if (M == 1) { //1번모드일때 , 모든 경우의 수 출력
		for (int i = 0; i < 6; i++)
		{

			path[level] = dice[i];
			func(level + 1, M);
			path[level] = 0;
		}
	}
	else if (M == 2) {
		for (int i = 0; i < 6; i++)
		{
			if (level != 0 && path[level - 1] >dice[i]) {
				continue;
			}
			path[level] = dice[i];
			func(level + 1, M);
			path[level] = 0;
		}

	}
	else if (M == 3) {
		for (int i = 0; i < 6; i++)
		{
			if (isvisited[i] == 1) {
				continue;
			}
			isvisited[i] = 1;
			path[level] = dice[i];
			func(level + 1, M);
			path[level] = 0;
			isvisited[i] = 0;
		}
	}

}
int main() {

	cin >> N >> M;


	func(0, M);



	return 0;


	return 0;
}
```


## 2024.07-29 (월) 백트래킹1 🤔🤔🤔

> recursion의 연장선

### **Path**
- 경로기억하기 -> 왔던 길을 기억해야한다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int path[2] = { -1, -1 };

void func(int level) {
	if (level == N) return;

	for (int i = 0; i < 2; i++)
	{
		path[level] = i;
		func(level + 1);
		path[level] = -1;

	}
	
}
int main() {
	//freopen("input.txt", "r", stdin);
	
	cin >> N;
	func(0);

}
```
> path에 내 위치 넣고 반환하고...


### path를 매개변수로 넣으면 되지않냐?

-> 배열은 call by reference 주소를 넘긴다.
손상이 된다.

그냥 전역변수로 선언해라 -> 어차피 유지안된다.

기록했다가 원상복구하고. 반복

### Path를 구해서 어디에쓰냐?

경로를 구해서 가지수 구하기.

### 가지치기의 두가지 방법.

### 1. for loop 안에서 조건이 맞으면 continue처리
```c++
    for (int i = 0; i < 6; i++)
    {
        if(i==3){ //3이면 넘긴다.
            continue; 
        }
        path[level] = i;
        func(level + 1, M);
        path[level] = -1;
    }
```

### 2. 들어가고 즉시 나간다. 재귀함수 최 상단에 if로 처리 return
```c++
    if(level==3){ //3이면 넘긴다.
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        
        path[level] = i;
        func(level + 1, M);
        path[level] = -1;
    }
```

### visited 매우 중요

> 왔던 곳이면 가지마라. 

```c++
    for (int i = 0; i < 6; i++)
    {
        if (visited[i] == 1) {
            continue;
        }
        visited[i] = 1;
        path[level] = i;
        func(level + 1, M);
        path[level] = -1;
        visited[i] = 0;
    }
```

### 2차원 visited - 지나온 길(맵)
visited[3][4] ==1; 

### 주사위 N번 던지는 경우의 수 문제!!기초