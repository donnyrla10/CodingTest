#include <iostream>
#include <algorithm>
using namespace std;

//buttons
//1. 화살표 한칸 아래로 내리기 (i -> i+1)
//2. 화살표 위로 한칸 올리기 (i -> i-1)
//3. 선택한 채널을 한 칸 아래로 내리기 (i <-> i+1 swapping, 화살표는 i+1가리킴)
//4. 선택한 채널을 위로 한 칸 올리기 (i <-> i-1 swapping, 화살표는 i-1가리킴)
//채널리스트 범위 넘어가지지 않음 (무시)

//KBS1, KBS2 로 순서 바꾸는 방법 구하기

//현재 화살표가 가리키는 채널이 KBS들이 아니면 내려가기

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string arr[101];
    int kbs1 = 0;
    int kbs2 = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        if(arr[i] == "KBS1") kbs1 = i; //4
        if(arr[i] == "KBS2") kbs2 = i; //3
    }
    
    int b = kbs1 - 1; //맨 위에서 kbs1까지 내려가는데 드는 횟수
    
    for(int i=1; i<=b; i++) cout << 1;
    for(int i=1; i<=b; i++) cout << 4;     //KBS1 맨 위로 올리기
    
    if(kbs1 > kbs2) kbs2++; //KBS2가 KBS1보다 아래였다면, 위 코드로 인해서 더 위로 올라감. 그러므로 kbs2의 인덱스에 +1 해줘야 한다. 한 문자열이 더 추가되었으므로
    
    b = kbs2 - 1;     //맨 위에서 kbs2까지 내려가는데 드는 횟수
    for(int i=1; i<=b; i++) cout << 1;
    for(int i=1; i<b; i++)  cout << 4;      //KBS2 맨 위 바로 "아래"까지 올리기
    return 0;
}
