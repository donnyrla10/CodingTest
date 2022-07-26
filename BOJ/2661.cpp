#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
bool finish = false;

bool isBad(string s){
    int size = s.size();
    int len = s.size()-1;
    for(int i=1; i<=size/2; i++){
        string s1 = s.substr(len-i, i);
        string s2 = s.substr(len, i);
        if(s1 == s2) return true;
        len--;
    }
    return false;
}

void DFS(int cnt, string result){
    if(finish) return;  //끝났으면 패스
    if(isBad(result)) return; //나쁜 수열이므로 바로 패스
    if(cnt == n){ //N자리 수열 완성
        cout << result << '\n';
        finish = true;
        return;
    }
    DFS(cnt+1, result + '1');
    DFS(cnt+1, result + '2');
    DFS(cnt+1, result + '3');
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    DFS(0, "");
    return 0;
}
