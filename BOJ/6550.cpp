#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    
    while(cin >> s >> t){
        int lens = s.size();
        int lent = t.size();
        bool flag = false;
        int index = 0;
        
        for(int i=0; i<lent; i++){
            if(s[index] == t[i]) index++;
            if(index == lens){
                flag = true;
                break;
            }
        }
        if(flag) cout << "Yes\n";
        else     cout << "No\n";
    }
    
    return 0;
}
