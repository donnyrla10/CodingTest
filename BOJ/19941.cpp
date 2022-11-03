#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//위치에서 거리가 K 이하인 햄버거만 먹을 수 있다
//햄버거를 먹을 수 있는 사람의 최대 수는?
//->왼쪽에 있는거 먼저 먹기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    int cnt = 0;
    string s;
    cin >> n >> k;
    cin >> s;
    for(int i=0; i<n; i++){
        if(s[i] != 'P') continue;
        for(int j=i-k; j<=i+k; j++){
            if(0<=j && j<n && s[j] == 'H'){
                s[j] = '-';
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
