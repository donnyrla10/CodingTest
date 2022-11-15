#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
using namespace std;

//블록 사이에 빗물이 고인다.
//빗물의 총량은?

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w, rain = 0;
    int block[501];
    cin >> h >> w;
    for(int i=0; i<w; i++) cin >> block[i];
    for(int i=1; i<w-1; i++){
        int left = 0, right = 0;
        for(int j=0; j<i; j++)     left = max(left, block[j]);
        for(int j=i+1; j<w; j++) right = max(right, block[j]);
        rain += max(0, min(left, right) - block[i]);
    }
    cout << rain << '\n';
    return 0;
}
