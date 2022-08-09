#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++){
        size_t pos = phone_book[i+1].find(phone_book[i]);
        if(pos == 0) return false;
//        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())) return false;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({"119", "97674223", "1195524421"}) << '\n'; //false
//    cout << solution({"123","456","789"}) << '\n';    //true
//    cout << solution({"12","123","1235","567","88"}) << '\n'; //false
    
    return 0;
}
