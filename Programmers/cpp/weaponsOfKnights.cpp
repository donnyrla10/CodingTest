#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int calDivisor(int x){
    int cnt = 0;
    for(int i=1; i*i<=x; i++) {
        if(x % i == 0) {
            if(i*i == x) cnt += 1;
            else cnt += 2;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 1;
    for(int i=2; i<=number; i++){ //기사단원
        int divisor = calDivisor(i);
        answer += limit >= divisor ? divisor : power;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution(5, 3, 2) << '\n'; //10
    cout << solution(10, 3, 2) << '\n'; //21
    return 0;
}
