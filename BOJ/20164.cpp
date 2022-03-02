#include <iostream>
#include <string>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int n, ans_min=INF, ans_max=0;

int getOddCnt(int num){
    int cnt = 0;
    while(num>0){
        int digit = num % 10;
        if(digit % 2 != 0) cnt++;
        num /= 10;
    }
    return cnt;
}

void solution(int x, int cnt){
    //base case: len==1인 경우(0~9), 종료 - min, max update
    if(x<=9){
        ans_max = max(ans_max, cnt);
        ans_min = min(ans_min, cnt);
        return;
    }
    
    //두자리라면 2개로 나눠서 합을 구해 새로운 수로 생각(solution()재귀호출)
    if(x<=99){
        int newX = (x/10) + (x%10);
        solution(newX, getOddCnt(newX) + cnt);
        return;
    }
    
    //세자리 이상이면 임의의 위치에서 끊어서 3개의 수로 분할하고 3개를 더한 값을 새로운 수로 생각(solution()재귀호출)
    string strX = to_string(x);
    int strX_len = strX.length();
    for(int i=0; i<=strX_len-3; i++){
        for(int j=i+1; j<=strX_len-2; j++){
            string s1 = strX.substr(0, i+1);            //[0...i]
            string s2 = strX.substr(i+1, j-i);          //[i+1...j]
            string s3 = strX.substr(j+1, strX_len-1-j); //[j+1...]
            
            int newX = stoi(s1) + stoi(s2) + stoi(s3);
            solution(newX, getOddCnt(newX) + cnt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    solution(n, getOddCnt(n));
    cout << ans_min << ' ' << ans_max << '\n';
    return 0;
}
