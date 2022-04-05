#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end()); //정렬
    while(budget >= 0 && answer <= d.size()){
        budget -= d[answer++];
    }
    return --answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution({1, 3, 2, 5, 4}, 9) << '\n'; //3
    cout << solution({2, 2, 3, 3}, 10) << '\n';   //4
    return 0;
}

