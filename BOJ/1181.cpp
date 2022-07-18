#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string arr[20001];
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n, comp);
    
    string last = "";
    for(int i=0; i<n; i++) {
        if(last == arr[i]) continue;
        cout << arr[i] << '\n';
        last = arr[i];
    }
    return 0;
}
