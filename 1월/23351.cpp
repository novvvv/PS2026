#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,a,b; // 화분, 수분, 연속된 a개의 화분, b 수분 증가량
    cin >> n >> k >> a >> b;  // 6개의 화분, 3만큼의 수분을 머금고있다.
    vector<int> v(n, k);
    
    int d_day = 0;
    while (true) {
        sort(v.begin(), v.end());
        if (v[0] == 0) {
            break;
        }
        for (int i = 0; i < a; i++) {
            v[i] += b;
        }
        for (int i = 0; i < n; i++) {
            v[i] -=1;
        }
        d_day++;
    }
    cout << d_day;
    // 연속된 2개의 화분에 2만큼 물을 준다.
    // 수분은 1씩 감소하고 0이 된 화분은 죽는다.
    // 3 3 3 3 3 3
    
    
}

// 일직선으로 놓여진 N개의 화분에 캣닢이 하나씩 심어져 있다.
// 각 화분은 초기에 K만큼의 수분을 머금고, 아래와 같은 일이 순서대로 일어난다.
//  1. 랑이 집사가 연속된 A개의 화분에 물을 준다. (물을 준 화분의 수분은 B만큼 증가한다)
//  2. 모든 화분의 수분이 1씩 감소한다.
//  3. 수분이 0이 된 화분에 있는 캣닢은 죽는다.
//  .... 캣닢이 살아 있는 기간이 최대한 길어지도록 물을 줄 때, 첫 캣닢이 죽는 날짜는

