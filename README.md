# 코테 준비하면서 배운 알고리즘

1. Direct Address Table (D.A.T.)

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

2. 