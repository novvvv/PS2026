#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    vector<int> dish(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> dish[i];
    }
    
    int sang = 0, park = 0;
    sort(dish.begin(), dish.end());
    bool flag = true;
    while(!dish.empty()) {
        if (flag) {
            park += dish.back();
            dish.pop_back();
            flag = false;
        }
        else {
            sang += dish.front();
            dish.erase(dish.begin());
            flag = true;
        }
    }
    
    cout << sang << " " << park << endl;
    
}

// * Condition *
// i번째 접시에는 ai개의 감자튀김이 있다.
// - 책상 위에 남아있는 접시 하나를 고르고, 접시와 그 위에 놓인 모든 감자튀김을 가져간다
// - 책상 위의 접시가 모두 사라질 때까지 반복한다.
// - 맨 처음 접시를 가져가는 사람은 박 모 씨다.
// - 박 모씨는 가져가는 감자튀김 양을 최대화하고
// - 성우는 가져가는 감자튀김 양을 최소화 한다.
// - 두 사람이 항상 최선의 행동을 한다고 가정할 때, 박 모씨와 성우가 가져가는 감자튀김의 양은?
