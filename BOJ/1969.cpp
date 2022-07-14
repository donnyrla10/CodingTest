#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<char, int> p1, pair<char, int> p2){
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, hd = 0;
    string s[1001], minString = "";
    vector<pair<char, int>> v;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> s[i];
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            bool flag = false;
            for(int k=0; k<v.size(); k++){
                if(s[j][i] == v[k].first){
                    v[k].second++; flag = true;
                }
            }
            if(!flag) v.push_back({s[j][i], 1});
        }
        sort(v.begin(), v.end(), comp);
        minString += v[0].first;
        for(int i=1; i<v.size(); i++)
            hd += v[i].second;
        v.clear();
    }
    
    cout << minString << '\n' << hd << '\n';
    return 0;
}
