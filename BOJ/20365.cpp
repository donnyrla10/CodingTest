#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char arr[500001];
    int n, ans = 0, size = 0, R = 0, B = 0;
    cin >> n;
    
    int pivot = 0;
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        
        if(i == 0){ //첫번째 원소의 경우만
            arr[pivot] = c;
            size++;
            pivot++; //어디서부터 연속되었는지 체크
        }else if(i!=0 && arr[pivot-1] != c){ //첫번째 원소가 아니고 이전 문자와 같지 않다면 arr 에 추가
            arr[pivot] = c;
            size++;
            pivot++;
        }
    }
    
    for(int i=0; i<size-1; i++){
        if(arr[i] == 'B') B++;
        else              R++;
    }
    
    if(B > R) ans += 1 + B;
    else      ans += 1 + R;
    cout << ans << '\n';
    return 0;
}
