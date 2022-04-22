#include <iostream>
#include <algorithm>
using namespace std;
int card[22];

void solution(int s, int e){
    int mid = (e+s-1)/2;
    for(int i=s; i<=mid; i++){
        swap(card[i], card[e-i+s]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=1; i<=20; i++) card[i] = i;
    for(int i=0; i<10; i++){
        int a, b;
        cin >> a >> b;
        solution(a, b);
    }
    for(int i=1; i<=20; i++) cout << card[i] << ' ';
    cout << '\n';
    return 0;
}
