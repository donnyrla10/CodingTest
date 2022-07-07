#include <iostream>
using namespace std;
string answer;
int n, m;
int value[100000];
string title[100000];

int binarySearch(int k){
    int left = 0, right = n-1;
    int mid = 0;
    while(left<=right){
        mid = (left+right)/2;
        if(k <= value[mid]) right = mid-1;
        else                left = mid+1;
    }
    if(k > value[mid]) return mid+1;
    else               return mid;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> title[i] >> value[i];
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        cout << title[binarySearch(k)] << '\n';
    }
    return 0;
}
