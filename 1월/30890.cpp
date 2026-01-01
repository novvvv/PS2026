#include <iostream>
using namespace std;

int main () {
    
    int X, Y; // 왼손 연주 횟수 2, 오른손 연주 횟수 3
    // 왼손 연주 횟수 4, 오른손 연주 횟수 2
    // GCD = 8
    // 왼손 박자 = GCD % X = 2
    // 오른손 박자 = GCD % Y = 4
    cin >> X >> Y;
    
    int GCD = X * Y; // 8
    int left_step = GCD / X;
    int right_step = GCD / Y;
    
    // GCD = 8
    int time = 1;
    while (time <= GCD) {
        // cout << "[Debug] time : " <<  time << endl;
        if (time % left_step == 0 && time % right_step == 0) cout << "3";
        else if (time % left_step == 0) cout << "1";
        else if (time % right_step == 0) cout << "2";
        time++;
    }
}
