#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int arr[101][101] = {0, };

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m; // n개의 불투명한 종이, m개 이하의 종이가 올려져 있으면 그림이 보인다.
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                arr[y][x]++;
            }
        }
        
    }
    
    int ans = 0;
    for (int y = 0; y < 101; y++) {
        for (int x = 0; x < 101; x++) {
            if (arr[y][x] > m) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    
    
}

// BOJ 1531
// 1x1 크기 모자이크 100x100그림
// N개의 불투명한 종이로 그림을 가린다.
// 현재 부분 위에 M개 이하의 종이가 올려져 있으면 그림은 그 부분에서 보이게 된다.
//  - 그림의 크기는 100x100 N개의 종이는 왼쪽 아래 모서리 좌표와 오른쪽 위 모서리 좌표가 입력으로 들어온다.
//  - 종이가 가리는 영역은 두 모서리 좌표도 포함된다
//  -- (1,1)부터 (2,2)를 가린다고 치면 총 4개의 그림이 가려진다 (1,1) (1,2) (2,1) (2,2)
