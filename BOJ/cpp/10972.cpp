#include <iostream>
#include <algorithm>
#include <string>
#define MAX 10000
using namespace std;
int arr[MAX], n;

bool next_permutation(){
    //i: 뒤에서부터 시작되는 가장 긴 증가 수열의 마지막 인덱스
    int i = n-1;
    while(i>0 && arr[i-1] > arr[i]) --i;
    if(i<=0) return false;                  //내림차순인 경우: 마지막 순열
    
    //j: i-1<j, arr[i-1]<a[j]인 수
    //i번째 수 바로 앞 수보다 큰 수 찾기
    int j = n-1;
    while(arr[i-1] > arr[j]) --j;
    
    //i번째 수와 J번째 수 바꾸기
    swap(arr[i-1], arr[j]);
    
    //i번째 수부터 마지막까지 모두 뒤집기
    for(int k=i, h=n-1; k<h; ++k, --h) swap(arr[k], arr[h]);
    
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    //다음 순열이 존재하는가? - 출력
    if(next_permutation()){
        for(int i=0; i<n; i++) cout << arr[i] << ' ';
        cout << '\n';
    }else{
        cout << "-1\n";
    }
    return 0;
}
