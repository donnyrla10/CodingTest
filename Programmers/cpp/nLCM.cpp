#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b){ //a>b
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1; i<arr.size(); i++){
        answer = lcm(answer, arr[i]);
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({1,2,3}) << '\n';
//    cout << solution({2,6,8,14}) << '\n';
    return 0;
}
