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

int solution(vector<int> ingredient) {
    int answer = 0;
    string str = "";
    int len = 0;
    for(int i=0; i<ingredient.size(); i++){
        str += ingredient[i] + '0';
        len = str.size();
        if(str.size() >= 4) {
            if(str[len-1] == '1' && str[len-2] == '3' && str[len-3] == '2' && str[len-4] == '1'){
                answer++;
                str.pop_back();
                str.pop_back();
                str.pop_back();
                str.pop_back();
            }
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({2, 1, 1, 2, 3, 1, 2, 3, 1}) << '\n';
    return 0;
}
