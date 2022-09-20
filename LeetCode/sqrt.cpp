#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int mySqrt(int x) {
    int n = 1;
    while(n*n <= x){
        n++;
    }
    return n-1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << mySqrt(4) << '\n';
    cout << mySqrt(8) << '\n';
    return 0;
}
