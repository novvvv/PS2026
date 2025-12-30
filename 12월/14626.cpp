#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    // 9788968322*73
    // 9 21 8 24 9 18 8 9 2 6 1* 21 3
    string str;
    cin >> str;
    int weight = 0;
    bool is_1_flag = true;
    bool isbn_flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            if (is_1_flag) {
                weight += str[i] - '0';
                is_1_flag = false;
            }
            else {
                weight += 3 * (str[i] - '0');
                is_1_flag = true;
            }
        }
        
        else {
            if (is_1_flag) {
                isbn_flag = true;
                is_1_flag = false;
            }
            else {
                isbn_flag = false;
                is_1_flag = true;
            }
        }
            
    }
    int i = 0;
    if (isbn_flag) {
        while (!(weight % 10 == 0)) {
            weight += 1;
            i++;
        }
    }
    
    else {
        while (!(weight % 10 == 0)) {
            weight += 3;
            i++;
        }
    }
    
    cout << i << '\n';
    
        
}

// 가중치 1, 3, 1, 3 ... 를 곱한 것을 모두 더하고 그 값을 10으로 나눈 나머지가 0이 되도록 만드는 숫자 m을 사용
