#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

string wheel[4];
int k;

void RotationWheel(int w, int d){
    int dir[4] = {};
    dir[w] = d;
    int index = w;
    //left
    while(index > 0 && wheel[index][6] != wheel[index-1][2]) {
        dir[index-1] = -dir[index];
        index--;
    }
    //right
    index = w;
    while(index < 3 && wheel[index][2] != wheel[index+1][6]) {
        dir[index+1] = -dir[index];
        index++;
    }
    
    for(int i=0; i<4; i++){
        if(dir[i] == 1){ //시계방향
            rotate(wheel[i].begin(), wheel[i].begin()+7, wheel[i].end());
        }else if (dir[i] == -1){
            rotate(wheel[i].begin(), wheel[i].begin()+1, wheel[i].end());
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0; i<4; i++) cin >> wheel[i];
    cin >> k;
    while(k--){
        int w, d;
        cin >> w >> d;
        RotationWheel(w-1, d);
    }
    int score = 0;
    for(int i=0; i<4; i++) if(wheel[i][0] == '1') score += (1 << i);
    cout << score << '\n';
    return 0;
}
