#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int a;
ll dp[64][32];

ll go(int now, int cnt) {
    // 한알짜리를 다 뽑으면
    if(cnt == a) {
        return 1;
    }
    // 한알을 뽑은 수보다 반알을 뽑은 수가 많으면 안된다
    if(cnt < now - cnt) {
        return 0;
    }
    
    // 메모이제이션
    ll &ret = dp[now][cnt];
    if(ret != -1) {
        return ret;
    }

    ret = go(now+1, cnt+1) + go(now+1, cnt);
    return ret;

}


// 테이블 : dp[현재날짜][반알 or 한알] = 생성가능한 문자열 
// 점화식 : dp[이전날짜][반알 or 한알] = dp[현재날짜][한알] + dp[현재날짜][반알]

// 테이블 : dp[현재날짜][현재까지 뽑은 한알] = 경우의 수
// 점화식 : dp[이전날짜][이전날짜까지 뽑은 한알] = dp[현재날짜][이전날짜까지 뽑은 한알 + 1] + dp[현재날짜][이전날짜까지 뽑은 한알]
// 초기화 : 한알짜리를 다 뽑으면 남은건 반알밖에 없으므로 return 1, 한알을 뽑은 수보다 반알을 뽑은 수가 많은건 불가능 return 0
int main() {
    while(true) {
        memset(dp, -1, sizeof(dp));
        cin >> a;
        if(a == 0) {
            break;
        } 
        cout << go(1, 1) << "\n";
    }
}