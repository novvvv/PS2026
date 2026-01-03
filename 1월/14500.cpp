#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, m, global_ret = 0;
int board[501][501];
bool is_visit[501][501];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool is_valid(int y, int x) {
    // 범위에서 벗어남
    if (y < 0 || y >= n || x < 0 || x >= m) {
        return false;
    }
    return true;
}

// : ㅗ ㅓ ㅏ ㅜ
const int exception_case[4][4][2] = {
    {{1,0}, {0,1}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {1,1}, {0,2}},
    {{1,0}, {0,1}, {1,1}, {2,1}},
    {{0,0}, {1,0}, {1,1}, {2,0}}
};

void exception_case_search (int y, int x) {
    int local_ret = 0;
    for (int i = 0; i < 4; i++) {
        int cur = 0;
        for (int j = 0; j < 4; j++) {
            int ny = y + exception_case[i][j][0];
            int nx = x + exception_case[i][j][1];
            if (!is_valid(ny, nx)) {
                cur = 0; break;
            }
            else {
                cur += board[ny][nx];
            }
        }
        local_ret = max(local_ret, cur);
    }
    global_ret = max(global_ret, local_ret);
}

// depth가 4이고, 방문한 숫자들의 합을 확인한다.
int dfs(int y, int x, int depth) {
    
    if (depth == 3) return board[y][x];
    int local_ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (is_valid(ny, nx) && !is_visit[ny][nx]) {
            is_visit[ny][nx] = true;
            local_ret = max(local_ret, board[y][x] + dfs(ny, nx, depth + 1));
            is_visit[ny][nx] = false;
        }
    }
    return local_ret;
    
}

void solve() {
    int local_ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // dfs
            is_visit[i][j] = true;
            local_ret = max(local_ret, dfs(i, j, 0));
            is_visit[i][j] = false;
            
            // excep
            exception_case_search(i, j);
            
        }
    }
    global_ret = max(global_ret, local_ret);
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    solve();
    cout << global_ret << endl;
    
}

// 모든 도형들이 4칸으로 이루어져 있다는 특징에서 보드판의 모든 정점에서 깊이를 4로 제한힌 DFS를 돌려 이들의 합을 얻어 비교한다.
// 하지만 ㅗ 블럭은 모든 칸을 방문하기 위해서는 한 번 뒤로 돌아간뒤 방문한 칸을 다시 방문해야 하기에 DFS로 해결이 불가능하다.
// 따라서 ㅗ 모양의 블럭은 별도로 처리해 주어야 한다.
