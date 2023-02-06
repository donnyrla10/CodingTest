#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(auto c : clothes) m[c[1]]++;
    for(auto it = m.begin(); it != m.end(); it++) answer *= it->second + 1;
    return answer-1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}) << '\n'; //5
//    cout << solution({{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_maskup", "face"}}) << '\n'; //3
    cout << solution({{"a", "headgear"}, {"b", "headgear"}, {"c", "eyewear"}, {"d", "eyewear"}, {"e", "face"}, {"f", "face"}}) << '\n'; //26
    return 0;
}
