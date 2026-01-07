#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string str;
    
    cin >> n >> str;
    
    string res = "";

    // 1. S의 길이가 25 이하라면 S를 그대로 출력
    if (n <= 25) {
        cout << str;
    }
    else { // n > 25
        
        // 중간 부분 문자열 추출 (앞 11글자, 뒤 11글자 제외)
        string mid_str = "";
        for (int i = 11; i <= n - 12; i++) {
            mid_str += str[i];
        }
        
        bool is_same = true;
        // 수정된 로직: 마지막 글자를 제외한 모든 글자를 검사
        // 중간에 마침표가 하나라도 있으면 같은 문장이 아님 (단, 맨 마지막 글자가 마침표인 건 허용)
        for (int i = 0; i < mid_str.size() - 1; i++) {
            if (mid_str[i] == '.') {
                is_same = false;
                break;
            }
        }
        
        // 2. 같은 문장에 속하는 경우 (중간을 ... 으로 대체)
        if (is_same) {
            for (int i = 0; i < 11; i++) { // 앞 11글자 (인덱스 0~10)
                res += str[i];
            }
            res += "...";
            for (int i = n - 11; i < n; i++) { // 뒤 11글자
                res += str[i];
            }
        }
        // 3. 같은 문장에 속하지 않는 경우 (중간을 ...... 으로 대체)
        else {
            for (int i = 0; i < 9; i++) { // 앞 9글자
                res += str[i];
            }
            res += "......";
            for (int i = n - 10; i < n; i++) { // 뒤 10글자
                res += str[i];
            }
        }
        
        cout << res;
    }
    
    return 0;
}
