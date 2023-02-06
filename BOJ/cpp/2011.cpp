#include <iostream>
#include <string>
#define num 5002
#define mod 1000000
using namespace std;
int dp[num];
string code;

//1. 한자리 숫자로 나타낼 수 있는 경우 (0이 아니면 모두 가능: 1~9)
//2. 두자리 숫자로 나타낼 수 있는 경우 (그 전 문자를 포함해서 두자리 숫자로 나타낼 수 있는 경우) -> 함수로 체크
//  i: 일의 자리, i-1: 십의 자리
//  2-1. 십의자리수까지있는 숫자라면
//  2-2. 그 이상의 수라면

bool check(char ten, char one){
    if(ten == '0') return false;    //십 자리가 0이면 false
    if(ten == '1') return true;     //십 자리가 1이면 true (2의 경우는 27 이상이면 안되므로 넘김)
    if(ten >= '3') return false;    //십 자리가 3이상이면 false (26까지)
    return one <= '6';              //ten=2 && one<=6 인 경우 가능(true)
}

void solution(){
    int n = code.size();
    if(code[0] != '0') dp[0] = 1; //초기값
    
    for(int i=1; i<n; i++){
        //1. 한자리 숫자로 나타낼 수 있는 경우
        if(code[i] != '0') dp[i] = dp[i-1];
        
        //2. 두자리 숫자로 나타낼 수 있는 경우
        if(check(code[i-1], code[i])){
            if(i>=2) dp[i] = dp[i] + dp[i-2]; //두자릿수이므로 i-2
            else     dp[i]++;
            dp[i] %= mod;
        }
    }
    
    cout << dp[n-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> code;
    solution();
    return 0;
}
