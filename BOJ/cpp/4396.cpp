#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    char Arr[11][11];
    char Brr[11][11];
    vector<pair<int, int>> bombIndex;
    bool bomb = false;
    int dir[8][2] = {{1, 0}, {0,1}, {-1,0}, {0, -1}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> Arr[i][j];
            if(Arr[i][j] == '*') bombIndex.push_back({i,j});
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> Brr[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c = Brr[i][j];
            if(c == 'x'){
                if(Arr[i][j] == '*') bomb = true;
                int cnt = 0;
                for(int d=0; d<8; d++){
                    int dx = i + dir[d][0];
                    int dy = j + dir[d][1];
                    if(0<=dx&&dx<n&&0<=dy&&dy<n){ //범위 내
                        if(Arr[dx][dy] == '*') cnt++;
                    }
                }
                Brr[i][j] = cnt + '0';
            }
        }
    }
    
    if(bomb){
        for(int i=0; i<bombIndex.size(); i++){
            int x = bombIndex[i].first;
            int y = bombIndex[i].second;
            Brr[x][y] = '*';
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << Brr[i][j];
        cout << '\n';
        
    }
    return 0;
}
