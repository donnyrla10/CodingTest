#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//그룹 단어란 단어에 존재하는 모든 문자에 대해, 각 문자가 연속해서 나타나는 경우만을 말한다.
//ccazzzzbb는 c, a, z, b가 연속해서 나타나서 그룹 단어가 맞고
//aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아님

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, ans = 0;
    bool f;
    int alph[26];
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;
        f = false;
        for(int i=0; i<26; i++) alph[i] = -1; //initailize

        for(int i=0; i<s.size(); i++){
            int index = s[i] - 'a';
            if(alph[index] == -1) alph[index] = i; //현재 문자의 인덱스 넣기
            else if(alph[index] != -1 && alph[index] + 1 != i) { //처음 나오는 것도 아니고, 연속된 문자가 아닌 경우
                f = true; break;
            }else alph[index] = i;
        }
        if(!f) ans++;
        for(int i=0; i<26; i++) alph[i] = -1; //initailize
    }
    
    cout << ans << '\n';
    return 0;
}
