#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1대 주차 -> 1분에 한대당 A원
//2대 주차 -> 1분에 한대당 B원
//3대 주차 -> 1분에 한대당 C원

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    int cost = 0;
    int time[101] = {0};
    cin >> a >> b >> c;
    for(int i=0; i<3; i++){
        int s, e;
        cin >> s >> e;
        for(int j=s; j<e; j++) time[j]++;
    }
    for(int i=1; i<=100; i++){
        if(time[i] == 1) cost += time[i] * a;
        else if(time[i] == 2) cost += time[i] * b;
        else cost += time[i] * c;
    }
    cout << cost << '\n';
    return 0;
}
