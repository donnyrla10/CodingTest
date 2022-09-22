#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#define MAX 200001
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;       //n: 키워드 개수, m: 글 개수
    string keyword;
    unordered_set<string> us;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> keyword;
        us.insert(keyword);
    }
    while(m--){
        string posting;
        cin >> posting;
        int pos = 0;
        while(pos<posting.size()){
            auto it = posting.find(',', pos); //pos 위치부터 시작해서 , 위치 찾기
            if(it == posting.npos){           //만약 , 없다면 (마지막 키워드)
                string sub = posting.substr(pos); //pos부터 끝까지 sub string
                if(us.find(sub) != us.end()) us.erase(sub); //us에 sub 키워드가 있다면 지우기
                break;
            }else{ //만약 , 있다면
                string sub = posting.substr(pos, it-pos);   //pos부터 ,직전까지 sub string
                if(us.find(sub) != us.end()) us.erase(sub); //us에 sub 키워드가 있다면 지우기
                pos = it + 1; //, 다음위치로 업데이트
            }
        }
        cout << us.size() << '\n';
    }
    return 0;
}
