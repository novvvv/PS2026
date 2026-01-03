#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k;
    string s;
    
    cin >> k >> s;
    
    vector<int> groups;
    int cur_cnt = 1;
    
    for (int i = 1; i < k; i++) {
        if (s[i] == s[i-1]) {
            cur_cnt++;
        }
        else {
            groups.push_back(cur_cnt);
            cur_cnt = 1;
        }
    }
    groups.push_back(cur_cnt);
    
    int max_len = 0;
    
    if (groups.size() >= 2) {
        for(int i = 0; i < groups.size() - 1; i++) {
            int cur_len = 2 * min(groups[i], groups[i+1]);
            max_len = max(max_len, cur_len);
        }
    }
    
    cout << max_len << '\n';
    
}

//

// 문자 N과 S
// N의 개수와 S의 개수는 동일하다.
// NS, NNSS, SSSNNN
// 문자열의 앞쪽 절만을 구성하는 문자는 모두 N또는 S이다.
// 가장 긴 부분 막대 자석 문자열은?

