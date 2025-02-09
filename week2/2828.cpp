#include <bits/stdc++.h>
using namespace std;

int n, m;
int j;
int apple;
int l, r;

int ret;

int main() {
    cin >> n >> m;
    cin >> j;

    l = 0;
    r = m;

    for(int i = 0; i < j; i++) {
        cin >> apple;

        // 바구니가 사과보다 왼쪽일때 apple - r
        if(apple > r) {
            ret += apple - r;
            r = apple;
            l = r - m;
        }
        // 바구니가 사과보다 오른쪽일때 l - apple + 1
        else if(apple <= l) {
            ret += l - apple + 1;
            l = apple - 1;
            r = l + m;
        }
        // 바구니가 사과 위치일때
        else if(apple > l && apple <= r) {
            
        } 
        
    }
    
    cout << ret << "\n";
}