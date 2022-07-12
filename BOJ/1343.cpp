#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, a;
    int num = 0;
    cin >> s;
    int len = s.size();

    int i = 0;
    while(i < len){
        if(s[i] == '.'){
            if(num > 0){
                if(num %2!=0){ //홀수면 바로 -1 리턴
                    cout << "-1\n";
                    return 0;
                }
                for(int i=0; i<num/4; i++){
                    a += "AAAA";
                }
                num %= 4;
                for(int i=0; i<num/2; i++){
                    a += "BB";
                }
                num = 0; //초기화
            }
            a += '.';
        }else{
            num++;
        }
        i++;
    }
    
    if(num % 2 != 0){
        cout << "-1\n";
        return 0;
    }
    for(int i=0; i<num/4; i++){
        a += "AAAA";
    }
    num %= 4;
    for(int i=0; i<num/2; i++){
        a += "BB";
    }
    
    cout << a << '\n';
    return 0;
}
