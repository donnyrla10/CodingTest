#include <iostream>
#include <algorithm>
using namespace std;

//1. 금메달 수 더 많은 나라
//2. 금메달 수 같으면 은메달 수가 더 많은 나라
//3. 금, 은메달 수가 같으면 동메달 수가 더 많은 나라

struct Country{
    int num;
    int gold;
    int silver;
    int bronze;
};

bool compare(Country c1, Country c2){
    if(c1.gold == c2.gold){
        if(c1.silver == c2.silver) return c1.bronze > c2.bronze;
        return c1.silver > c2.silver;
    }
    return c1.gold > c2.gold;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, answer = 0;
    Country arr[1001];
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int country, gold, silver, bronze;
        cin >> country >> gold >> silver >> bronze;
        arr[i].num = country;
        arr[i].gold = gold;
        arr[i].silver = silver;
        arr[i].bronze = bronze;
    }
    
    sort(arr, arr+n, compare);
    
    int want = 0;
    for(int i=0; i<n; i++){
        if(arr[i].num == k) {
            want = i;
            break; //내가 구하고 싶은 나라 인덱스 - 정렬했으니까 달라졋음
        }
    }
    
    for(int i=0; i<=want; i++){
        if(arr[i].gold == arr[want].gold && arr[i].silver == arr[i].silver && arr[i].bronze == arr[want].bronze) break;
        answer++;
    }
    cout << answer+1 << '\n';
    return 0;
}
