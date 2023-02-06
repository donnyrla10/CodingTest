#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num[26] = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
    string s;
    int cnt = 0;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        cnt += num[s[i] - 'A'];
        if(cnt > 10) cnt %= 10;
    }
    if(cnt % 2 == 0) cout << "You're the winner?\n";
    else             cout << "I'm a winner!\n";
    return 0;
}
