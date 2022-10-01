#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    map<string, int> ma;
    string name[100001];
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        ma[s] = i;
        name[i] = s;
    }
    for(int i=1; i<=m; i++){
        string s;
        cin >> s;
        if(s[0] >= '1' && s[0] <= '9'){ //숫자
            cout << name[stoi(s)] << '\n';
        }else{
            cout << ma[s] << '\n';
        }
    }
    return 0;
}

//문자열을 key로 하는 ma  (map) -> value는 int
//숫자를 key로 하는 name (arr) -> value는 string
