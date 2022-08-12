#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string convertToTitle(int columnNumber) {
    string answer = "";
    while(columnNumber){
        answer += (columnNumber - 1) % 26 + 'A';
        columnNumber = (columnNumber - 1) / 26;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << convertToTitle(52) << '\n';
    return 0;
}
