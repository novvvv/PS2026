#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check_palin(string s) {

    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
    
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while(cin >> str) {
        
        if (str == "0") break;
        
        int integer_str = stoi(str); // str "100000" to integer 100000
        int original_len = str.length();
        bool is_palin = false;
        int cnt = 0;
        
        int num = stoi(str);
        while (true) {
            
            string cur_str = to_string(num);
            // leading Zero
            while (cur_str.length() < original_len) {
                cur_str = "0" + cur_str;
            }
            
            if (check_palin(cur_str)) {
                cout << cnt << endl;
                break;
            }
            num++;
            cnt++;
        }
        
    }
    
}

// BOJ 4096
// [point] stoi는 integer type의 범위를 초과할 수 있다.
// [point[ to_string는 stoi기반 함수이기에 앞에 0이있으면 잘라버린다.
