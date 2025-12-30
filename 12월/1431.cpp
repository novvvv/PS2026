#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool comp(string a, string b);

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<string> serials(n, "");
    for (int i = 0; i < n; i++) {
        cin >> serials[i];
    }
    
    sort(serials.begin(), serials.end(), comp);
    
    for (int i = 0; i < n; i++) {
        cout << serials[i] << '\n';
    }
        
}

bool comp(string a, string b) {
    
    // * condition 1 *
    // 길이가 더 작은 문자열이 앞으로 와야 한다.
    if (a.size() != b.size()) {
        // a의 사이즈가 b의 사이즈보다 작음
        return a.size() < b.size();
    }
    
    // * condition 2 *
    // 모든 자리수의 합을 비교해 작은 합이 먼저 와야한다.
    else if (a.size() == b.size()) {
        
        int a_digit_sum = 0, b_digit_sum = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (isdigit(a[i])) a_digit_sum += a[i] - '0';
            if (isdigit(b[i])) b_digit_sum += b[i] - '0';
        }
        
        // a의 합이 b보다 작다
        if (a_digit_sum != b_digit_sum)
            return a_digit_sum < b_digit_sum;
        
    }
    
    // * condition 3 *
    // 사전순
    return a < b;
    
}

// * sort custorm *
// return true : 지금 순서가 맞으니 바꾸지 않음
// return false : 지금 순서가 틀렸으니 바꿔야함
// tip : 정렬되어야 하는 순서를 비교 연산식으로 리턴하는 것이 간결하다.


// * solve *
// - A-Z 알파벳, 0-9 숫자
// - A와 B의 길이가 다르면 짧은것이 먼저 온다.
// - 길이가 같다면 A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해 작은 합이 먼저
// - 1,2번 둘 조건으로 비교할 수 없으면 사전순. 숫자가 알파벳보다 사전순으로 작음
