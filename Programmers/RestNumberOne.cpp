#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int x = n-1;
    while(x > 0){
        if(n%x==1) answer = x;
        x--;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(10) << '\n';
    cout << solution(12) << '\n';
    return 0;
}
