#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
using namespace std;

int n, m, ans = 0;
int arr[505][505];
pair<int, int> t[19][4] = {
    //case1
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, //좌표 찍음
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    //case2
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    //case3
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    //case4
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    //case5
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
    {{0, 1}, {1, 1}, {1, 0}, {1, 2}}
};

int solution(int x, int y){
    int maxV = 0;
    for(int i=0; i<19; i++){
        int sum = 0;
        for(int j=0; j<4; j++) sum += arr[x + t[i][j].first][y + t[i][j].second];
        maxV = max(maxV, sum);
    }
    return maxV;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) ans = max(ans, solution(i, j));
    cout << ans << '\n';
    return 0;
}
