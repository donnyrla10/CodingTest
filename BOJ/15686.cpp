#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
bool visit[13];
int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) { // O(n^2)
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)      house.push_back({i, j});
            if(arr[i][j] == 2) chicken.push_back({i, j});
        }
    }
    vector<int> permutation(chicken.size(), 1); //치킨집 개수만큼 1으로 채움
    fill(permutation.begin(), permutation.begin() + chicken.size() - m, 0); //2진수로 만든 치킨집 선택 경우의 수
    int sum = 100000000;
    do{
        int s = 0;
        for(auto h:house){ //집(1)에서 가장 가까운 치킨집과의 거리 구하기(s)
            int chickenDist = 100000000;
            for(int i=0; i<chicken.size(); i++){
                if(permutation[i] == 0) continue;
                chickenDist = min(chickenDist, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            s += chickenDist;
        }
        sum = min(s, sum); //최소 sum(치킨 거리) 구하기
    }while(next_permutation(permutation.begin(), permutation.end()));
    
    cout << sum << '\n';
    return 0;
}
