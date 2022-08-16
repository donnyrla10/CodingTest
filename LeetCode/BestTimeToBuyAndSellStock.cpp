#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices) {
    int sell=0;
    int answer = 0;
    int minn = 10001; //min
    
    for(int i=0; i<prices.size(); i++){
        if(minn > prices[i]){
            sell = *max_element(prices.begin()+i, prices.end());
            minn = prices[i];
            answer = max(answer, sell-minn);
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << maxProfit({7,1,5,3,6,4}) << '\n';
    cout << maxProfit({2,1}) << '\n';
    return 0;
}


//1.
