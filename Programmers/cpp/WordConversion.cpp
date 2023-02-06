#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int answer = 101;

void DFS(string begin, string target, vector<string> words, vector<bool>& used, int cnt){
    for(int i=0; i<words.size(); i++){
        int dif = 0;
        for(int j=0; j<words[i].length(); j++)
            if(!used[i] && words[i][j] != begin[j]) dif++;
        if(dif == 1){ //글자수 차이가 1인 단어!
            if(target == words[i] && answer > cnt + 1){ //target 단어와 동일!
                answer = cnt + 1; //최솟값 업데이트
                return;
            }
            used[i] = true;
            DFS(words[i], target, words, used, cnt+1); //바뀐 begin word로 DFS 탐색
            used[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> used(words.size(), false);
    DFS(begin, target, words, used, 0);
    if(answer == 101) return 0;
    return answer;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';
//    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';
    return 0;
}
