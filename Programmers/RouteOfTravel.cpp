#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS(string start, vector<vector<string>> tickets, vector<string>& answer, vector<bool>& visited, int use){
    answer.push_back(start);
    if(use == tickets.size()) return true; //사용하지 않는 항공권은 없다. 다 사용하면 리턴
    
    for(int i=0; i<tickets.size(); i++){
        if(visited[i] == false && tickets[i][0] == start){
            visited[i] = true;
            bool t = DFS(tickets[i][1], tickets, answer, visited, use+1);
            if(t) return true;  //t==true라는 것은, 이전 DFS에서 끝났기 때문임.. DFS 빠져나옴
            visited[i] = false; //항공권 사용 취소. 다른 경로 찾아봄
        }
    }
    answer.pop_back();          //경로가 끊겼으므로 마지막 지역 pop
    return false;               //DFS 빠져나옴
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, answer, visited, 0);
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> a = solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
    for(int i=0; i<a.size(); i++) cout << a[i] << ' ';
    cout << '\n';
    
    return 0;
}
