#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n1, n2, t;
    string s1, s2, ans;
    cin >> n1 >> n2 >> s1 >> s2 >> t;
    
    reverse(s1.begin(), s1.end());
    //두개 합치기
    ans = s1 + s2;

    while(t--){
        for(int i=0; i<ans.length()-1; i++){
            if(s1.find(ans[i]) != string::npos && s2.find(ans[i+1]) != string::npos){ //s1에 없다면 -> npos
                //둘다 s1, s2에 있거나 반대의 경우. 즉, 같은 문자열에 있는 것은 아님
                swap(ans[i], ans[i+1]);
                i++;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}

