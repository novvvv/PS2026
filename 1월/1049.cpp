#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m; // 기타줄, 브랜드
    vector<int> brand_line_price_6;
    vector<int> brand_line_price_1;
    
    for (int i = 0; i < m; i++) {
        int line6, line1;
        cin >> line6 >> line1;
        brand_line_price_6.push_back(line6);
        brand_line_price_1.push_back(line1);
    }
    
    int price = 0;
    
    // case1 : 끊어진 기타줄의 수가 6개 이하인 경우
    if (n <= 6) {
        
        int min_line_1 = *min_element(brand_line_price_1.begin(), brand_line_price_1.end()); // 1개 묶음 중 가장 싼 브랜드
        int min_line_6 = *min_element(brand_line_price_6.begin(), brand_line_price_6.end()); // 6개 묶음 중 가장 싼 브랜드
        
        // case1.1) 1개 묶음이 6개 묶음보다 싼 케이스를 찾아서 모두 구매한다.
        if (min_line_1 * n < min_line_6) {
            price = min_line_1 * n;
        }
        
        // case1.2) 6개 묶음으로 사는게 1개로 n번 구매하는것보다 싸다면 6개 묶음으로 구매한다.
        else {
            price = min_line_6;
        }
        
    }
    
    // case2 : 끊어진 기타줄의 수가 6개를 초과하는 경우
    else {
        //      case2.1) 1개 묶음이 6개 묶음보다 싼 케이스가 있다면 찾아서 모두 구매한다.
        //      case2.2) 6개 묶음으로 x개만큼 구매하고 나머지는 낱개중 가장 싼 브랜드로 구매한다.
        
        int min_line_1 = *min_element(brand_line_price_1.begin(), brand_line_price_1.end()); // 1개 묶음 중 가장 싼 브랜드
        int min_line_6 = *min_element(brand_line_price_6.begin(), brand_line_price_6.end()); // 6개 묶음 중 가장 싼 브랜드
        
        // case2.1) 1개 가격으로 6개를 사는것이 6개 묶음으로 사는것 보다 싼 브랜드가 있다면 1개 가격으로 모두 구매한다.
        if (min_line_1 * 6 < min_line_6) {
            price = min_line_1 * n;
        }
        
        // case2.2) 6개묶음이 가장 싼 브랜드로 (n/6)만큼 구매하고 나머지(n%6)는 낱개중 가장 싼 브랜드로 구매한다.
        else {
            // case2.2.1) 단, 6개 묶음으로 모두 구매하는것이 싸다면 모두 구매한다.
            if (min_line_6 * ((n/6)+1) < min_line_6 * (n/6) + min_line_1 * (n%6)) {
                price = min_line_6 * ((n/6)+1);
            }
            // case2.2.2)
            else {
                price = min_line_6 * (n/6) + min_line_1 * (n%6);
            }
        }
    }
    
    cout << price << endl;
    
    
    // case1
    // 6개 이하인 경우 (n개)
    //      case1.1) 1개 묶음이 6개 묶음보다 싼 케이스를 찾아서 모두 구매한다.
    //      case1.2) 6개 묶음으로 사는게 n개를 낱개로 구매하는 경우보다 싸다면 6개 묶음중 가장 싼 브랜드로 구매한다.
    
    // case2
    // 6개 이상인 경우

    // 15 1
    // 100 40
    
    // 320 오류 300(정답)
    
    // 17 1
    // 12 3 오류 39(정답)
}


// 6줄 패키지 or 1개 또는 그 이상의 줄을 낱개로 구매
// 끊어진 기타줄의 개수 N개
// 기타줄 브랜드 M개
// 각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격, 낱개로 살 떄의 가격이 주어진다.

// 줄 4개가 끊어짐
// 브랜드1 , 6개 : 12원, 1개 : 3원
// 브랜드2 , 6개 : 15원, 1개:  4원


// 줄 10개가 끊어짐
// 브랜드1 , 6개 : 20원, 1개 : 8원
// 브랜드2 , 6개 : 40원, 1개 : 7원
// 브랜드3 , 6개 : 60원, 1개 : 4원
