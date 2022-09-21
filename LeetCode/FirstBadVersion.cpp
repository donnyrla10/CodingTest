#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//이 부분은 실제론 없는 부붑 -> 문제에서 주어짐ㅠ
bool isBadVersion(int x){
    return true;
}

int firstBadVersion(int n) {
    int l=1, r=n;
    while(l<=r){
        int m = l+(r-l)/2;
        if(isBadVersion(m)) r = m-1;
        else                l = m+1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << firstBadVersion(5) << '\n';
    return 0;
}
