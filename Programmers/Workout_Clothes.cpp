#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int answer = 0;
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {1,3,5};
    vector<int> student(n+1, 0); //n명을 0으로 초기화
    
    for(auto i : lost)    student[i]--;
    for(auto i : reserve) student[i]++;
    
    for(int i=1; i<=n; i++){
        if(student[i] == -1){ //체육복이 없는 학생
            if(student[i-1] == 1){ //앞 학생이 체육복 여벌이 있다면
                student[i-1]--;
                student[i]++;
            }else if(student[i+1] == 1){
                student[i+1]--;
                student[i]++;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
        if(student[i] != -1) answer += 1;
    
    cout << answer << '\n';
}
