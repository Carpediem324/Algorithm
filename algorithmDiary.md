# 매일 정리

## 2024.07-24

## 2024.07-23


## 2024.07-22 D.A.T

### DAT를 안쓰고 배열의 알파뱃 종류를 찾아내는 코드를 작성하세요
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