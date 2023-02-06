#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, rowCnt = 0, colCnt = 0;
    char arr[101][101];
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> arr[i][j];
    
    //가로
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[i][j] == '.'){
                cnt++;
            }else{
                if(cnt >= 2) rowCnt++;
                cnt = 0;

            }
        }
        if(cnt >= 2) rowCnt++;
    }
    
    //세로
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[j][i] == '.'){
                cnt++;
            }else{
                if(cnt >= 2) colCnt++;
                cnt = 0;
            }
        }
        if(cnt >= 2) colCnt++;
    }
    cout << rowCnt << ' ' << colCnt << '\n';
    return 0;
}
