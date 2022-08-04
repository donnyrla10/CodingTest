#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 10000
using namespace std;
int arr[MAX], n;
vector<int> v;

//bool prev_permutation(){
//    int i = n-1;
//    while(i>0 && arr[i-1] < arr[i]) --i;
//    if(i<=0) return false;                  //완전 오름차순인 경우: 첫번째 순열
//
//    int j = n-1;
//    while(arr[i-1] < arr[j]) --j;
//    swap(arr[i-1], arr[j]);
//
//    for(int k=i, h=n-1; k<h; ++k, --h) swap(arr[k], arr[h]);
//    return true;
//}
//
//int main(){
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> n;
//    for(int i=0; i<n; i++) cin >> arr[i];
//
//    //다음 순열이 존재하는가? - 출력
//    if(prev_permutation()){
//        for(int i=0; i<n; i++) cout << arr[i] << ' ';
//        cout << '\n';
//    }else{
//        cout << "-1\n";
//    }
//    return 0;
//}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    if(prev_permutation(v.begin(), v.end())){
        for(int i=0; i<n; i++) cout << v[i] << ' ';
        cout << '\n';
    }else{
        cout << "-1\n";
    }
    return 0;
}
