#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(1){
        string s;
        cin >> s;
        if(s == "end") break;
        int vowel_cnt = 0;
        int vowel_index = -1;
        int cons_index = -1;
        int v_seq = 0, c_seq = 0;
        bool flag = false;
        for(int i=0; i<s.size(); i++){
            //3. 같은 글자 연속 두 번 안됨 ee, oo는 허용
            if((s[i] != 'o' && s[i] != 'e') && (s[i] == s[i+1]) && i < s.size()-1){
                cout << "<" << s << "> is not acceptable.\n"; flag = true; break;
            }
            
            //1. 모음 개수 카운팅 + 2. 모음 자음 연속 체크
            if(isVowel(s[i])) {
                vowel_cnt++;
                c_seq = 0;
                cons_index = -1;
                if((vowel_index != -1 && vowel_index + 1 == i) || vowel_index == -1){ //연속이라면 cnt++;
                    v_seq++;
                    vowel_index = i; //마지막 모음 인덱스
                }
                if(v_seq >= 3) {
                    cout << "<" << s << "> is not acceptable.\n"; flag = true; break;
                }
            }else{
                v_seq = 0;
                vowel_index = -1;
                if((cons_index != -1 && cons_index + 1 == i) || cons_index == -1){ //연속이라면 cnt++;
                    c_seq++;
                    cons_index = i; //마지막 자음 인덱스
                }
                if(c_seq >= 3) {
                    cout << "<" << s << "> is not acceptable.\n"; flag = true; break;
                }
            }
        }
        //모음 개수 판별
        if(!flag){
            if(vowel_cnt == 0) cout << "<" << s << "> is not acceptable.\n";
            else               cout << "<" << s << "> is acceptable.\n";
        }
    }
    return 0;
}
