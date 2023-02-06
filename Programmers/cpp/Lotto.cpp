#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//로또는 1부터 45까지의 숫자 중 6개를 찍어서 맞히는 복권
//1위: 6개, 2위: 5개, 3위: 4개, 4위: 3개, 5위: 2개, 6위: 1개 or 0개

//알아볼 수 없는 번호는 0
//ex
//구매한 로또 번호 6개 : 44, 1, 0, 0, 31, 25
//당첨된 로또 번호 6개 : 31, 10, 45, 1, 6, 19
//순서와 상관없이 구매한 로또에 당첨번호와 일치하는 번호가 있으면 맞힌걸로 인정
//알아볼 수 없는 두 개의 번호를 각각 10, 6이라고 하면 3등에 당첨될 수 있음. 다른 숫자로 만들어서 당첨될수도 있지만 2등이상은 불가
//알아볼 수 없는 두 개의 번호를 각각 11, 7이라고 하면 5등에 당첨될 수 있음. 다른 방법도 존재하지만 6등은 불가

//출력: 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아서 리턴

int ranking(int n){
    switch(n){
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3: return 4;
        case 2: return 5;
        default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct = 0, zero=0;
    
    for(int i=0; i<6; i++){
        int n = lottos[i];
        if(n == 0) zero++;
        else{
            auto it = find(win_nums.begin(), win_nums.end(), n); //구매한 로또 번호가 당첨된 로또 번호 중 하나인지 체크
            if(it != win_nums.end()) { //동일한 값이 있다면
                correct++;
            }
        }
    }
    
    answer.push_back(ranking(correct + zero));
    answer.push_back(ranking(correct));
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19});
    solution({0, 0, 0, 0, 0, 0}, {38, 19, 20, 40, 15, 25});
    solution({45, 4, 35, 20, 3, 9}, {20, 9, 3, 45, 4, 35});
    return 0;
}

