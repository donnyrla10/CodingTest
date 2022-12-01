#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
#include <list>
#include <map>
using namespace std;

int num[10];

bool zero(string str) {
    for(auto s: str) if(s != '0') return false;
    return true;
}

string solution(string X, string Y) {
    string answer = "";
    for(int i=0; i<X.size(); i++) num[X[i] - '0']++;
    for(int i=0; i<Y.size(); i++) {
        if(num[Y[i] - '0'] >= 1) {
            answer += Y[i];
            num[Y[i] - '0']--;
        }
    }
    if(answer.size() == 0) return "-1";
    if(zero(answer)) return "0";
    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution("12321", "42531") << '\n';
    return 0;
}
