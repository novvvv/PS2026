#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a; // 게임 진행 사람
    int t; // 구하고자 하는 번째 T
    int cmd; // 구호 뻔 : 0, 데기 : 1
    // 8 , 2 , 0 -> 2번째 뻔은? 뻔, 데기, 뻔 (2)
    // 4, 6, 1, -> 6번째 데기를 부른 사람은?
    // [뻔, 데기, 뻔, 데기], 뻔, 뻔, 뻔, 뻔(3)
    
    cin >> a >> t >> cmd;
    int i = 0;
    int bbun = 0, daegi = 0;
    string str = "";
    
    for (int i = 0; i <= 1000; i++) {
        str += "0101";
        string news = "";
        for (int j = 0; j <= i + 1; j++) {
            news += "0";
        }
        str += news;
        
        news = "";
        for (int j = 0; j <= i + 1; j++) {
            news += "1";
        }
        str += news;
    }
    
    // t번째 flag를 구하라
    int cnt = 0;
    int tempidx = -1;
    // 데기
    if (cmd == 0) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0') {
                cnt++;
                if (cnt == t) {
                    tempidx = i;
                    break;
                }
            }
        }
    }
    
    if (cmd == 1) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                cnt++;
                if (cnt == t) {
                    tempidx = i;
                    break;
                }
            }
        }
    }
    
    cout << tempidx % a;
    
}

// n-1회차
// Cycle : 뻔 - 데기 - 뻔 - 데기 - 뻔 (x n번) - 데기 (x n번)
// 반 시계 방향으로 번데기 게임 진행
// T번째 "뻔" 혹은 "데기"를 외치는 사람은 위 원에서 몇 번 사람인가

// 7명이 있고 16번째 등장하는 "뻔"을 부른 사람 번혼는 7 16 0
// 4명이 있고 6번째 등장하는 "데기"를 부른 사람 번호는 4 6 1 -> 반 시계 방향으로 3번째 있는 사람???
// [뻔 데기 뻔 데기] [뻔 뻔 데기 데기]
