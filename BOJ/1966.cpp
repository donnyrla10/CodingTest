#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        int cnt = 0;
        queue<pair<int, int>> doc; //index, prio
        priority_queue<int> pq;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            doc.push({i, a});
            pq.push(a);
        }
        
        while(!doc.empty()){
            int index = doc.front().first;
            int value = doc.front().second;
            doc.pop();
            if(pq.top() == value){ //doc 맨 앞에 있는 문서의 우선순위가 가장 높은거라면
                pq.pop();
                cnt++; //몇번째인지 카운팅
                if(index == m){ //이 문서의 번호와 몇번째로 인쇄되는지 궁금한 문서 번호가 동일하다면
                    cout << cnt << '\n';
                    break;
                }
            }else{
                doc.push({index, value}); //우선순위가 가장 높지 않으므로 뒤에 넣어준다
            }
        }
    }
    return 0;
}
