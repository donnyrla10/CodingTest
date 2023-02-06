#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string tmp = "";

void Game(string s, string t){
    if(s == t){
        cout << 1 << '\n';
        exit(0);
    }
    
    if(s.size() >= t.size()) return;
    
    if(t[t.size()-1] == 'A'){
        tmp = t;
        tmp.erase(tmp.size() - 1);
        Game(s, tmp);
    }
    if(t[0] == 'B'){
        tmp = t;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        Game(s, tmp);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    Game(s, t);
    cout << 0 << '\n';
    return 0;
}
