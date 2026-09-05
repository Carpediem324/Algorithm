#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    size_t pos;

    while ((pos = my_string.find(letter)) != string::npos) {
        my_string.erase(pos, letter.length());
    }

    return my_string;
}

// my_string.erase(
// remove(my_string.begin(), my_string.end(), letter[0]), 
// my_string.end());
// 이런식으로 구현 가능하고 원리는 아래와 같다.
// remove는 단순히 제거할 요소를 뒤로 보내고, 실제로 문자열의 길이를 줄이지 않기 때문에
// erase를 사용하여 문자열의 길이를 줄이는 것이 더 적합합니다.      

//이는 한글자만 제거에 적합하므로(remove함수의 매개변수가 char형이기 때문에) 
//여러 글자를 제거할 때는 find와 erase를 사용하는 것이 더 적합합니다.
