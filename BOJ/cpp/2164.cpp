#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    queue<int> card;
    cin >> n;
    for(int i=1; i<=n; i++) card.push(i);
    while(card.size()-1){
        card.pop(); //제일 위에 있는 카드를 바닥에 버린다.
        card.push(card.front()); //제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다
        card.pop();
    }
    cout << card.front() << '\n';
    return 0;
}
