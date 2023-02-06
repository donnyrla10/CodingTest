//없는 숫자 더하기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    bool flag = false;
    int answer = 0;
    int j;
    for(int i=0; i<=9; i++){
        flag = false;
        for(j=0; j<numbers.size(); j++){
            if(numbers[j] == i) {
                flag = true;
            }
        }
        if(!flag) answer += i;
    }
    return answer;
}
