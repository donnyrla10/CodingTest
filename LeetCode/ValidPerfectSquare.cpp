#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//bool isPerfectSquare(int num) {
//    long long n = 1;
//    long long r = 1;
//    while(r <= num){
//        if(r == num) return true;
//        n++;
//        r = n * n;
//    }
//    return false;
//}

bool isPerfectSquare(int num) {
    int s = 1, e = num;
    while(s <= e){
        long long mid = s + (e-s)/2;
        if(mid*mid == num) return true;
        else if(mid*mid < num) s = mid+1;
        else                   e = mid-1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << isPerfectSquare(14) << '\n';
    return 0;
}
