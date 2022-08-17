#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool checkIfExist(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr.size(); j++){
            if(arr[i]*2 == arr[j] && i != j) return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << checkIfExist({-2,0,10,-19,4,6,-8}) << '\n';
    return 0;
}


//-19, -8, -2, 0, 4, 6, 10
//
