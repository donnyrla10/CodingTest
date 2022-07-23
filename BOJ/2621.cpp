#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    int color[4];   //R, B, Y, G
    int number[11];
    
    for(int i=0; i<4; i++) color[i] = 0;
    for(int i=0; i<10; i++) number[i] = 0;
    
    char a;
    int b;
    int max = 0;
    for(int i=0; i<5; i++){
        cin >> a >> b;
        if(a == 'R') color[0]++;
        else if(a == 'B') color[1]++;
        else if(a == 'Y') color[2]++;
        else if(a == 'G') color[3]++;
        number[b] += 1;
        if(max < b) max = b;
    }
    
    //카드 모두 동일 색상인지 체크
    bool col = false;
    for(int i=0; i<5; i++) if(color[i] == 5) col = true;
    
    //숫자 연속성 체크
    int cnt = 0;
    for(int i=1; i<=9; i++){
        if(number[i] == 1){
            cnt++;
            if(cnt == 5){
                break; //5개 연속 끝남 이 for문 빠져나가서 끝내기
            }
        }else if(number[i] > 1){ //1보다 크면 숫자가 연속적인 것이 아님
            break; //이 for문 빠져나감
        }else{
            cnt = 0; //초기화
        }
    }
    
    //1. 모두 같은 색 && 숫자 연속적: 가장 높은 숫자 + 900
    if(cnt == 5 && col){
        answer = max + 900;
        cout << answer << '\n';
        return 0;
    }
    
    if(!col){
        for(int i=1; i<=9; i++){
            //2. 4장 숫자 같음 : 같은 숫자에 + 800
            if(number[i] == 4){ //카드 4장 모두 같은 숫자
                answer = i + 800;
                cout << answer << '\n';
                return 0;
            }
            //3. 3장 숫자 같음 && 다른 2장 숫자 같음 : 3장 같은 숫자 * 10 + 2장 같은 숫자 + 700
            else if(number[i] == 3){
                for(int j=1; j<=9; j++){
                    if(number[j] == 2){
                        answer = i * 10 + j + 700;
                        cout << answer << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    
    //4. 모두 색상 동일 && 연속적이지 않음 - 가장 큰 값 구하기
    if(col && cnt != 5){
        answer = max + 600;
        cout << answer << '\n';
        return 0;                   //끝내기
    }
    
    if(!col){
        //5. 카드 5장 색이 다르고 숫자 연속인 경우 : 가장 높은 숫자 + 500
        if(cnt == 5){
            answer = max + 500;
            cout << answer << '\n';
            return 0;
        }
        for(int i=1; i<=9; i++){
            //6. 3장 숫자 같음 : 숫자 + 400
            if(number[i] == 3){
                answer = i + 400;
                cout << answer << '\n';
                return 0;
            }
            
            //7. 2장 숫자 같음 && 다른 2장 숫자 같음 : 같은 숫자 중 큰 숫자 * 10 + 작은 수 + 300
            //8. 2장 숫자 같음: 숫자 + 200
            else if(number[i] == 2){
                for(int j=1; j<=9; j++){
                    if(i != j && number[j] == 2){
                        if(i > j) answer = i * 10 + j + 300;
                        else      answer = j * 10 + i + 300;
                        cout << answer << '\n';
                        return 0;
                    }
                }
                answer = i + 200;
                cout << answer << '\n';
                return 0;
            }
        }
    }
    
    //9. 나머지 : 가장 큰 숫자에 +100
    answer = max + 100;
    cout << answer << '\n';
    return 0;
}
