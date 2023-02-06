#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d, k, c;
    int sushi[30001];
    bool check[30001] = {false};
    bool coupon = false;
    int ans = -1;
    int cnt = 0;
    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++) cin >> sushi[i];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){         //k개 먹음
            int cur = sushi[(i+j)%n];
            if(cur == c) coupon = true; //쿠폰 초밥을 먹음
            if(!check[cur]){            //먹은 적 없는 초밥 종류
                cnt++;                  //초밥 종류 카운팅
                check[cur] = true;      //먹은 적 있는 초밥으로 변경
            }
        }
        if(!coupon) ans = max(ans, cnt+1); //쿠폰 초밥을 먹지 않은 경우
        else        ans = max(ans, cnt);   //쿠폰 초밥을 먹은 경우
        
        //초기화
        coupon = false;
        cnt = 0;
        for(int i=1; i<=d; i++) check[i] = false;
    }
    cout << ans << '\n';
    return 0;
}
