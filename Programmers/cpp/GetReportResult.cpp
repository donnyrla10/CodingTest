#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

//각 유저는 한 번에 한 명의 유저를 신고할 수 있다.
//신고 횟수에 제한 없음. 서로 다른 유저를 계속 신고할 수 있다
//한 유저를 여러 번 신고할 수 있지만, 동일 유저에 대한 신고횟수는 1회로 처리
//k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송
//유저가 신고한 모든 내용을 취합해 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일 발송

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> name;
    vector<string> byWhom[id_list.size()];
    int cnt[id_list.size()];
    for(int i=0; i<id_list.size(); i++) {
        cnt[i] = 0;
        answer.push_back(0);
    }
    
    //1. report 배열 돌면서 유저 당 신고된 횟수 카운팅 (같은 유저한테 신고당했으면 1번으로 처리)
    //byWhom -> index = id_list's index(신고당한 사람 number), second = 횟수
    //만약 이미 first에 동일한 사람이 들어있다면 second 증가하지 않음
    for(int i=0; i<report.size(); i++){
        //split names
        string str = report[i];
        istringstream ss(str);
        string buffer;
        while(getline(ss, buffer, ' ')){
            name.push_back(buffer);
        }
        
        //신고당한 사람 index 구하기
        auto it = find(id_list.begin(), id_list.end(), name[1]);
        int index = it - id_list.begin();
        
        //만약 유저가 이미 신고했다면
        auto it2 = find(byWhom[index].begin(), byWhom[index].end(), name[0]);
        if(it2 == byWhom[index].end()) { //만약 유저가 신고한 적이 없다면
            byWhom[index].push_back(name[0]);
            cnt[index]++;
        }
        
        name.clear(); //초기화
    }
    
    //byWhom[0] = "apeach"
    //byWhom[1] = "muzi", "apeach"
    //byWhom[2] =
    //byWhom[3] = "frodo", "muzi"
    
    //2. cnt 배열 돌면서
    for(int i=0; i<id_list.size(); i++){
        if(cnt[i] >= k){
            for(auto j = byWhom[i].begin(); j != byWhom[i].end(); j++){
                auto k = find(id_list.begin(), id_list.end(), *j);
                int in = k-id_list.begin();
                answer[in]++;
            }
        }
    }
    
    for(auto it = answer.begin(); it != answer.end(); it++){
        cout << *it << ' ';
    }
    cout << '\n';
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2);
    return 0;
}
