#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    char num[3] = {'1', '2', '4'};
    
    while(n){
        int i = (n-1) % 3;
        answer += num[i];
        n = (n-1) / 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution(1) << '\n';
//    cout << solution(2) << '\n';
//    cout << solution(3) << '\n';
//    cout << solution(4) << '\n';
//    cout << solution(5) << '\n';
//    cout << solution(6) << '\n';
//    cout << solution(7) << '\n';
//    cout << solution(8) << '\n';
//    cout << solution(9) << '\n';
    cout << solution(10) << '\n';
    cout << solution(11) << '\n';
    return 0;
}
