#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    int x1, y1, r1, x2, y2, r2;
    cin >> t;
    
    
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        int condi1 = (r1-r2) * (r1-r2);
        int condi2 = (r1+r2) * (r1+r2);
        // 1. 중심이 같다.
        if (dist == 0) {
            if (condi1 == 0) cout << -1 << endl;
            else cout << 0 << endl;
        }
        
        // 2. 한 점에서 만난다.
        else if (dist == condi1 || dist == condi2) {
            cout << 1 << endl;
        }
        
        // 3. 두 점에서 만난다.
        else if (condi1 < dist && dist < condi2) {
            cout << 2 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    
    
}


// 자신의 터렛 위치 - 현재 적까지의 거리 계산
// 조규현의 좌표 (x1, y1) 백승환의 좌표 (x2, y2)
// 조규현이 계산한 류재명과의 거리 r1
// 백승환이 계산한 류재명과의 거리 r2
// 류재명이 있을 수 있는 좌표의 수

// (0 0) 13
// (40 0) 37

// r = 1 (끝점 4개) (0,1) (0,-1) (1,0) (-1,0)
// r = 2 (끝점 4개) + (r=1) + 4
// r = 3
