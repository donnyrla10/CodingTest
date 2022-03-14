#include <iostream>
#include <map>
using namespace std;
char sl, sr;
string str;
int ans, n, x, y;
map<char, pair<int, int>> keyboard;

//자음 - 왼손으로, 모음 - 오른손으로
//a 좌표 (x1, y1) b 좌표 (x2, y2)
//a에 위치한 손가락이 b로 이동하는 데에는 a와 b의 택시 거리 |x1-x2| + |y1-y2| 만큼의 시간이 걸린다
//각 키를 누르는 데에는 1의 시간이 걸린다
//두 손을 동시에 움직일 수 없다.
//해당 문자열을 출력하는데 걸리는 시간의 최솟값

void init(){
    keyboard['q'] = {0, 0}, keyboard['w'] = {0, 1}, keyboard['e'] = {0, 2}, keyboard['r'] = {0, 3},
    keyboard['t'] = {0, 4}, keyboard['y'] = {0, 5}, keyboard['u'] = {0, 6}, keyboard['i'] = {0, 7},
    keyboard['o'] = {0, 8}, keyboard['p'] = {0, 9}, keyboard['a'] = {1, 0}, keyboard['s'] = {1, 1},
    keyboard['d'] = {1, 2}, keyboard['f'] = {1, 3}, keyboard['g'] = {1, 4}, keyboard['h'] = {1, 5},
    keyboard['j'] = {1, 6}, keyboard['k'] = {1, 7}, keyboard['l'] = {1, 8}, keyboard['z'] = {2, 0},
    keyboard['x'] = {2, 1}, keyboard['c'] = {2, 2}, keyboard['v'] = {2, 3}, keyboard['b'] = {2, 4},
    keyboard['n'] = {2, 5}, keyboard['m'] = {2, 6};
}

void solution(){
    ans = n = str.size();
    for(char c : str){
        if(c == sl || c == sr) continue;
        x = keyboard[c].first, y = keyboard[c].second;
        if((!x && y>=0 && y<=4) || (x==1 && y>=0 && y<=4) || (x==2 && y>=0 && y<=3)){
            ans += abs(keyboard[sl].first - keyboard[c].first) + abs(keyboard[sl].second - keyboard[c].second);
            sl = c;
        }else{
            ans += abs(keyboard[sr].first - keyboard[c].first) + abs(keyboard[sr].second - keyboard[c].second);
            sr = c;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> sl >> sr >> str;
    init();
    solution();
    return 0;
}
