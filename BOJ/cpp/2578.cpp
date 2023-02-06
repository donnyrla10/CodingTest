#include <iostream>
using namespace std;
int arr[26][26], ans=0;

int bingGo(){
    int bg = 0;
    
    //가로
    for(int i=1; i<=5; i++){
        int cnt = 0;
        for(int j=1; j<=5; j++){
            if(arr[i][j] == 0) cnt++;
        }
        if(cnt == 5) bg++;
    }
    
    //세로
    for(int j=1; j<=5; j++){
        int cnt = 0;
        for(int i=1; i<=5; i++){
            if(arr[i][j] == 0) cnt++;
        }
        if(cnt == 5) bg++;
    }
    
    //대각선(\)
    int cnt = 0;
    for(int i=1; i<=5; i++){
        if(arr[i][i] == 0) cnt++;
    }
    if(cnt == 5) bg++;
    
    //대각선(/)
    cnt = 0;
    for(int i=1; i<=5; i++){
        if(arr[i][6-i] == 0) cnt++;
    }
    if(cnt == 5) bg++;
    
    return bg;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for(int i=1; i<=5; i++) for(int j=1; j<=5; j++) cin >> arr[i][j];
    for(int i=1; i<=25; i++){
        int num;
        cin >> num;
        ans++;
        
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                if(num == arr[j][k]) {
                    arr[j][k] = 0;
                    if(bingGo() >= 3) {
                        cout << ans << '\n';
                        return 0;
                    }
                }

            }
        }
    }
    return 0;
}
