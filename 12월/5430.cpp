#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    string cmd, integer_string; // 1 <= cmd <= 100,000
    bool is_reverse = false;
    
    // 배열에 들어있는 수 n개 1 <= n <= 100,000
    for (int i = 0; i < t; i++) {
        
        deque<int> deq;
        
        cin >> cmd;
        cin >> n;
        cin >> integer_string;
        
        // to_dec
        string cur_int = "";
        for (int ch = 0; ch < integer_string.size(); ch++) {
            
            if (isdigit(integer_string[ch])) {
                cur_int += integer_string[ch];
                int nxt_ch = ch + 1;
                if (isdigit(integer_string[nxt_ch])) {
                    continue;
                }
                if (is_reverse) {
                    deq.push_front(stoi(cur_int));
                }
                else {
                    deq.push_back(stoi(cur_int));
                }
                cur_int = "";
            }
            
        }
        
        bool is_error = false;
        for (int j = 0; j < cmd.size(); j++) {
            
            // O(N)
            if (cmd[j] == 'R') {
                
                if (is_reverse) is_reverse = false;
                else is_reverse = true;
                /* deque<int> temp_deq;
                temp_deq = current_deq;
                current_deq = reverse_deq;
                reverse_deq = temp_deq; */
                
            }
            
            else if (cmd[j] == 'D') {
                if (deq.empty()) {
                    cout << "error" << '\n';
                    is_error = true;
                    break;
                }
                else {
                    if (is_reverse) {
                        deq.pop_back();
                    }
                    else {
                        deq.pop_front();
                    }
                }
            }
            
        }
        
        if (!is_error) {
            cout << "[";
            while(!deq.empty()) {
                
                if (!is_reverse) {
                    cout << deq.front();
                    deq.pop_front();
                    if (!deq.empty()) {
                        cout << ",";
                    }
                }
                
                else {
                    cout << deq.back();
                    deq.pop_back();
                    if(!deq.empty()) {
                        cout << ",";
                    }
                }
            }
            cout << "]" << '\n';
        }
        
        else {
            is_error = false;
            continue;
        }
        
    }
    
    
}

// * Learn _ integer 다루기 *
// isdigit & Ascii & stoi


// * Condition *
// 새로운 언어 AC
// AC는 정수 배열에 연산을 하기 위해서 만든 언어
// R(뒤집기) D(버리기)가 존재
// R - 배열에 있는 수의 순서를 뒤집는 함수
// D - 첫 번째 수를 버리는 함수
// 배열이 비어있는데 D를 사용한다? -> 에러
// 함수는 조합해서 한 번에 사용 가능 RDD -> 배열을 디집고 처음 두 수를 버려라

// * Think *
// R - reverse O(N) ?
// D - O(1) Vector X

// Worst n = 100,000 & p = 100,000
// 100,000(p) * 100,000 * t(100) -> Time Over

