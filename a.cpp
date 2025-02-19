#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct A {
    int t;
    int a;
    int h;
};
vector<A> v;
int temp1, temp2, temp3;

ll max_h = 1e18;
int n, atk;
// ti가 1인 경우 공격력이 ai이고 생명력이 hi인 몬스터가 있음을 나타내고, 
// ti가 2인 경우 용사의 공격력 HATK를 ai만큼 증가시켜주고 용사의 현재 생명력 HCurHP를 hi만큼 회복시켜주는 포션이 있음


bool check(ll mid) {

    ll temp_atk = atk;
    ll temp_mid = mid;
    
    for(int i = 0; i < n; i++) {
        // 몬스터 있음
        if(v[i].t == 1) {
            ll attackCnt = v[i].h / temp_atk;
            if(v[i].h % temp_atk != 0) {
                attackCnt++;
            }
            ll attackedCnt = attackCnt - 1;
            temp_mid -= attackedCnt * v[i].a;
            if(temp_mid <= 0) {
                return false;
            }
        }
        // 포션 있음
        else {
            temp_atk += v[i].a;
            temp_mid += v[i].h;
            if(temp_mid > mid) {
                temp_mid = mid;
            }
        }
    }
    return true;
}


int main() {
    cin >> n >> atk;
    for(int i = 0; i < n; i++) {
        cin >> temp1 >> temp2 >> temp3;
        v.push_back(A{temp1, temp2, temp3});
    }

    ll l = 1;
    ll r = 1e18;
    ll mid;

    while(l <= r) {
        mid = (l + r) / 2;
        if(check(mid) == true) {
            r = mid - 1;
            max_h = min(max_h, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << max_h << "\n";
}