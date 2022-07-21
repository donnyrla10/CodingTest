#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; //index, prio
    priority_queue<int> pq;
    
    for(int i=0; i<priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int index = q.front().first;
        int prio = q.front().second;
        q.pop();
        
        if(pq.top() == prio){ //이 문서가 가장 우선순위가 높다면
            pq.pop();
            answer++;
            if(index == location) break; //원하는 문서의 출력 순서 나왔으니 끝내기
        }else{ // 이 문서보다 더 높은 우선순위가 있다면
            q.push({index, prio});
        }
    }
    return answer;
}
