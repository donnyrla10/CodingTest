#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1, s2, ans = "";
    int start[3], end[3]; //hour, minute, second
    cin >> s1 >> s2;

    int index = 0, index2 = 0;
    for(int i=0; i<7; i+=3){
        start[index++] = (s1[i]-'0')*10 + (s1[i+1]-'0');
        end[index2++] = (s2[i]-'0')*10 + (s2[i+1]-'0');
    }
    
    if(end[0] == start[0] && end[1] == start[1] && end[2] == start[2]){
        cout << "24:00:00" << '\n';
        return 0;
    }
    
    //초
    if(end[2] < start[2]){ //만약 시작시간보다 크다면
        end[2] += 60; //60초 더해주기
        end[1] -= 1;
    }
    int an = end[2] - start[2];
    if(an < 10) ans = ":0" + to_string(an);
    else        ans = ":" + to_string(an);
    
    //분
    if(end[1] < start[1]){ //만약 시작시간보다 크다면
        end[1] += 60; //60초 더해주기
        end[0] -= 1;
    }
    an = end[1] - start[1];
    if(an < 10) ans = ":0" + to_string(an) + ans;
    else        ans = ":" + to_string(an) + ans;
    
    //시
    if(end[0] < start[0]){ //만약 시작시간보다 크다면
        end[0] += 24; //24 더해주기
    }
    an = end[0] - start[0];
    if(an < 10) ans = "0" + to_string(an) + ans;
    else        ans = to_string(an) + ans;
    
    cout << ans << '\n';
    return 0;
}
