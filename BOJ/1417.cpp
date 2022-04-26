#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//국회의원 후보 n명
//마을의 주민 M명의 마음 모두 읽음
//다른 모든 사람의 득표수보다 많은 득표수를 가질 때, 그 사람이 국회의원에 당선
//매수해야 하는 사람의 최솟값 출력하기

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=0, dasom;
    vector<int> cand;
    
    cin >> n;
    cin >> dasom;
    
    n--;
    while(n--){
        int p;
        cin >> p;
        if(p>=dasom) cand.push_back(p);
    }
    
    sort(cand.begin(), cand.end(), comp);

    while(!cand.empty() && cand[0] >= dasom){
        ans++;
        dasom++;
        cand[0]--;
        sort(cand.begin(), cand.end(), comp);
    }
    
    cout << ans << '\n';
    return 0;
}
