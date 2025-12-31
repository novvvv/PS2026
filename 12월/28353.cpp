#include <iostream>
#include <string>
#include <numeric>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int n, k; // n마리 고양이, 버틸 수 있는 무게 K
    cin >> n >> k;
    vector<int> cats(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cats[i];
    }
    sort(cats.begin(), cats.end());
    
    
    // 2, 4, 8, 11, 16
    // 3, 4, 5, 6, 7, 9
    int left_ptr = 0, right_ptr = n - 1;
    int ans = 0;
    while (left_ptr < right_ptr) {
        if (cats[left_ptr] + cats[right_ptr] <= k) {
            ans ++;
            right_ptr--;
            left_ptr++;
        }
        else {
            right_ptr--;
        }
    }
    
    cout << ans << endl;

        
}

// N마리의 고양이
// i번째 고양이의 무게는 wi
// 찬우와 친구들은 정확히 2마리를 데리고 있으면 행복해짐
// 두 고양이의 무게의 합이 K를 넘으면 버티지 못한다.
// 각 고양이의 무게와, 한명이 버틸 수있는 최대 무게가 주어짐 최대 몇명 행복?
