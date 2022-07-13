#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, maxv = "", minv = "";
    cin >> s;
    
    //max value
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'M'){ //M의 경우
            //연속 M 개수 카운팅
            int end = i;
            while(end < s.size()){
                if(s[end] == 'M') end++;
                else              break;
            }
            
            //10진수로 변환
            if(end == s.size()){ //모두 M인 경우
                for(int j=0; j<end-i; j++){
                    maxv += "1";
                }
            }else{ //다음 원소가 K인 경우
                maxv += "5";
                for(int j=0; j<end-i; j++){ //M의 개수만큼 0붙음
                    maxv += "0";
                }
            }
            i = end;
        }else{ //K의 경우
            maxv += "5";
        }
    }
    
    //min value - k를 하나로 자르기, M은 최대한 길게(K없이)
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'M'){
            int end = i;
            while(end < s.size()){
                if(s[end] == 'M') end++;
                else              break;
            }
            
            //10진수로 변환
            minv += '1';
            end--;
            for(int j=0; j<end-i; j++){ //M-1개만큼 0 붙이기
                minv += '0';
            }
            i = end;
        }else{
            minv += '5';
        }
    }
    cout << maxv << '\n' << minv << '\n';
    return 0;
}
