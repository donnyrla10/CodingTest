#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w, cloud[102][102], time=0;
    vector<pair<int, int>> c;
    
    cin >> h >> w;
    
    for(int i=1; i<=h; i++) for(int j=1; j<=w; j++) {
        char clo;
        cin >> clo;
        if(clo == 'c'){
            c.push_back({i, j});
            cloud[i][j] = 0;
        }else{
            cloud[i][j] = -1;
        }
    }
    
    while(!c.empty()){
        time++;
        //동쪽으로 구름들 이동
        for(int i=0; i<c.size(); i++) {
            c[i].second++;
            if(c[i].second > w) {
                c.erase(c.begin() + i); //범위를 넘어서면 삭제하기
                i--;
            }
            else{
                if(cloud[c[i].first][c[i].second] == -1) cloud[c[i].first][c[i].second] = time;
            }
        }
    }
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout << cloud[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
