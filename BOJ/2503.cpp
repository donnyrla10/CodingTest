#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool arr[1000];
    int n, num, strike=0, ball=0, s, b;
    
    for(int i=123; i<999; i++) arr[i] = true;
    //arr에 가능한 숫자 정보 (서로다른수로 이루어진 3자리 수, 1~9 이므로 0 안됨)
    for(int i=123; i<999; i++){
        string s = to_string(i);
        if(s[0] == s[1] || s[1] == s[2] || s[2] == s[0] || s[0] == '0' || s[1] == '0' || s[2] == '0')
            arr[i] = false;
    }
    
    //입력받기
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num >> s >> b;
        string mh = to_string(num); //민혁이 추측한 수

        for(int j=123; j<999; j++){
            strike = 0;
            ball = 0; //초기화
            
            if(arr[j]){
                string tmp = to_string(j);
                
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){
                        //strike
                        if(x==y && mh[x] == tmp[y]) strike++;
                        if(x!=y && mh[x] == tmp[y]) ball++;
                    }
                }
                if(strike != s || ball != b) arr[j] = false;
            }
        }
    }
    int ans = 0;
    for(int i=123; i<999; i++) if(arr[i]) ans++;
    cout << ans << '\n';
    return 0;
}
