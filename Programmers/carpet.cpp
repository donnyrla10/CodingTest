#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> divisor;
vector<int> yy;

void Divisor(int t, bool tt){
    if(tt){
        for(int i=1; i<=t; i++){
            if(t%i == 0) {
                divisor.push_back(i);
                if(i*i == t) divisor.push_back(i); //한번 더 넣기
            }
        }
        sort(divisor.begin(), divisor.end());
    }else{
        for(int i=1; i<=t; i++){
            if(t%i == 0) {
                yy.push_back(i);
                if(i*i == t) yy.push_back(i); //한번 더 넣기 (3*3==9인 경우)
            }
        }
        sort(yy.begin(), yy.end());
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tt = brown + yellow;
    Divisor(tt, true);
    Divisor(yellow, false);
    
    for(int i=0; i<divisor.size()/2; i++){
        int h = divisor[i];
        int w = divisor[divisor.size()-1-i];
        if(h <= 2 || w <= 2) continue; //이건 가운데에 들어갈 수 있는게 없음
        
        for(int j=0; j<yy.size()/2; j++){
            int yh = yy[j];
            int yw = yy[yy.size()-j-1];
            if((yh+2 <= h && yw+2 <= w) || (yh+2 <= w && yw+2 <= h)) {
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }
        }
    }
    return answer;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ans = solution(10, 2);
//    vector<int> ans = solution(8, 1);
//    vector<int> ans = solution(24, 24);
    for(auto i:ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
