#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, candidate[22];
vector<pair<int, int>> frame; //first: 추천받은 학생의 고유 수, second: 추천받은 횟수
bool flag;

//일정 기간 동안 전체 학생의 !추천!에 의해 정해진 수만큼 선정.
//추천된 학생의 사진을 게시할 수 있는 사진틀을 후보 수만큼 만들었음.
//추천받은 학생 사진을 사진틀에 게시하고 추천받은 횟수를 표시하는 규칙은

//1.추천 전, 모든 사진틀은 비어있음.
//2.특정 학생을 추천하면, 추천받은 학생의 사진은 반드시 사진틀에 게시
//3.비어있는 사진틀이 없으면 현재까지 추천받은 횟수가 가장 적은 학생의 사진 삭제
//  &&새롭게 추천받은 학생의 사진 게시 (가장 적은 학생의 수 2명 이상 -> 가장 오래된 사진 삭제)
//4.현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우, 추천 받은 횟수만 증가
//5.사진틀에 게시된 사진이 삭제되는 경우, 해당 학생이 추천받은 횟수는 0

//사진틀의 개수(후보 수)와 전체 학생의 추천 결과가 순서대로 주어졌을 때, 최종 후보는?

void alreadyCandidate(int c){
    for(int i=0; i<frame.size(); i++){   //이미 추천받은 학생들을 쭉 돌면서 확인하기
        if(frame[i].first == c) {        //추천받은 학생의 고유 수(first) == 입력받은 학생의 수
            frame[i].second++;           //있으면 추천받은 횟수 추가
            flag = true;
            break;
        }
    }
}

void solution(int cand){
    flag = false;

    //추천받은 적이 이미 있다면
    alreadyCandidate(cand);
    
    //추천받은 적이 없다면
    if(!flag){
        //1. 사진틀에 개시(빈 사진틀이 있다면)
        if(frame.size() < n) frame.push_back({cand, 1});   //추천 학생 이름 추가하기
        else if(frame.size() == n){
            int _min = 0x7fffffff;
            for(int i=0; i<frame.size(); i++) //추천받은 최소 횟수 찾기
                _min = min(_min, frame[i].second);
            for(int i=0; i<frame.size(); i++){
                if(_min == frame[i].second){
                    frame.erase(frame.begin()+i); //해당 원소 삭제
                    break;
                }
            }
            //가장 오래되고 추천수가 작은 학생 삭제했으면, 내꺼 넣기!
            frame.push_back({cand, 1});
        }
    }
}

bool comp(pair<int, int> v1, pair<int, int> v2){
    return v1.first < v2.first;
}

void input(){
    cin >> n >> m;              //n: 사진틀 개수(후보 수) m: 전체 학생의 총 추천 횟수
    for(int i=0; i<m; i++){
        int s;
        cin >> s;           //추천받은 학생을 나타내는 번호
        solution(s);
    }
    
    //최종 후보 추천받은 횟수가 많은 순서대로 정렬
    sort(frame.begin(), frame.end(), comp);
    
    //최종 후보는? (n개만 나와야 됨)
    for(int i=0; i<frame.size(); i++)
        cout << frame[i].first << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}
