#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> m;
    for(auto i: completion){
        m[i] += 1;
    }
    
    for(auto j: participant){
        m[j] -= 1;
        if(m[j] < 0) answer = j;
    }
    
    return answer;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"});
//    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"mislav", "stanko", "ana"});
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"});

    return 0;
}
