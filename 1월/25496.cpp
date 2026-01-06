#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int p, n;
    cin >> p >> n; // p 현재 피로도, n 만들 수 있는 장신구
    vector<int> equips(n, 0);
    for (int i = 0; i < n; i++)
        cin >> equips[i];
    sort(equips.begin(), equips.end());
    
    int ptr = 0;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (p < 200) {
            p += equips[i];
            ans++;
        }
        else {
            break;
        }
    }
    
    cout << ans << endl;
    
}

// BOJ25496
// 어떻게 하면 효율적으로 많은 장신구를 제작할 수 있는가
// 장신구 N개, 장신구를 만들면 Ai만큼의 피로도 누적
// 피로도 200 미만인 경우, 장신구 제작 가능
// ... 현재 쌓인 피로도가 P일때 제작 가능한 장신구의 최대 개수

// 190 5
// 1 1 8 10 20
