#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int addDigits(int num) {
    int sum = 0;
    
    while(num > 9){
        while(num != 0){
            sum += num % 10;
            num /= 10;
        }
        num = sum;
        sum = 0;
    }
    return num;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << addDigits(38) << '\n';
    cout << addDigits(0) << '\n';

    return 0;
}
