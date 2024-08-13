# 매일 알고리즘 정리
## 2024.08-13 (화) 

## Union Find

1. 어떤 사람이, 어떤 그룹에 속해 있는지?

- 어느 그룹에 속해 있는지 궁금하다.

2. 어떤 두 사람을 뽑았더니 같은 그룹에 속해 있는지? 

- 생일이 같을까?

값이 같은 것을 앞에서부터 하나하나 그룹으로 묶는 형태

find 재귀 함수 사용, 그래프 구조 표현

구현

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 부모 노드
int parent[10];
// 각 사람의 생일을 나타내는 배열
int birthdays[10] = { 8, 2, 2, 8, 3, 3, 12, 12, 6, 8 };

int find(int tar)
{
    if (tar == parent[tar])
        return tar;

//  경로압축
//  int ret = find(parent[tar])
//  parent[tar]=ret;
//  return paretn[tar];
    return find(parent[tar]);
}

void setUnion(int a, int b)
{
    int t1 = find(a);
    int t2 = find(b);

    if (t1 == t2)
        return;

    parent[t2] = t1;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        parent[i] = i;
    }

    // 생일이 같은 사람들끼리 집합을 만듭니다.
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (birthdays[i] == birthdays[j])
            {
                setUnion(i, j);
            }
        }
    }

    // 각 사람이 어떤 집합에 속하는지 출력합니다.
    for (int i = 0; i < 10; i++)
    {
        cout << i << "는" << find(i) << "그룹에 속해있습니다." << endl;
    }

    return 0;
}
```


### 경로 압축 Path Compression

Root로 전부 묶어버린다
find함수 수정

```c++
//  경로압축
//  int ret = find(parent[tar])
//  parent[tar]=ret;
//  return paretn[tar];
```
## MST

### 최소신장트리 Minimum Spanning Tree

- 다음과 같은 조건을 만족하는 그래프

1. 모든 노드를 포함한다.
2. edge의 개수는 N-1개
3. 사이클 없음
4. 최소한의 비용을 사용한다

> 도시계획 - 수로, 전기, 도로, 배관, 네트워크

두가지 방법이 있다.
- Cruscal - Union Find 활용 MST만들기
- Prim

### Cruscal

- edge의 cost를 오름차순 정렬 후 낮은 순으로 넣는다

- union find의 find함수를 사용해 같은 그룹인지 아닌지 cycle을 체크한다.

- edge의 개수가 N-1이면 끝낸다

```c++

```