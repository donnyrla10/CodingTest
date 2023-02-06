#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//비교 함수
int check(char base, char fr) {
    if (base == 'S') {//가위
        if (fr == 'S') return 1;
        if (fr == 'P') return 2;
        if (fr == 'R') return 0;
    }
    if (base == 'P') {//보
        if (fr == 'S') return 0;
        if (fr == 'P') return 1;
        if (fr == 'R') return 2;
    }
    if (base == 'R') {//바위
        if (fr == 'S') return 2;
        if (fr == 'P') return 0;
        if (fr == 'R') return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r,n;
    cin >> r;
    vector<char>sg(r);
    for (int i = 0; i < r; i++) cin >> sg[i];
    cin >> n;
    vector<vector<char>>friends(n,vector<char>(r));
    for (int i = 0; i < n; i++) for (int j = 0; j < r; j++) cin >> friends[i][j];

    int score = 0, max_score = 0;
    for (int j = 0; j < r; j++) {
        int win[3] = { 0,0,0 };
        for (int i = 0; i < n; i++) {
            win[0] += check('S', friends[i][j]);
            win[1] += check('P', friends[i][j]);
            win[2] += check('R', friends[i][j]);

            score += check(sg[j], friends[i][j]);
        }
        max_score += max(win[0], max(win[1], win[2]));
    }
    cout << score << '\n' << max_score << '\n';;
        
}
