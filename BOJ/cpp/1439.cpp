#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int one=0, two=0;
    bool f1 =false, f2 = false;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            if(f2) f2 = false;
            if(!f1){ //0의 그룹 시작 부분 flag 꽂기
                one++;
                f1 = true;
            }
        }else{
            //0의 그룹 flag가 꽂혀있는데 1이 들어오면 0 끝남
            if(f1) f1 = false; //flag 뽑기
            if(!f2){
                two++;
                f2 = true;
            }
        }
    }
    cout << min(one, two) << '\n';
    return 0;
}
