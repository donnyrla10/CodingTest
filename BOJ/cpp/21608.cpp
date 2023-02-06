#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 22
using namespace std;

struct Student{
    int n;
    int fav[4];
};

struct Position{
    int x; int y;
    int near_empty;
    int near_fav;
};

int n, answer = 0;
int map[MAX][MAX];
vector<Student> st;
Student st_arr[MAX*MAX];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void input(){
    cin >> n;
    for(int i=0; i<n*n; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        st.push_back({a, {b, c, d, e}});
        st_arr[a].n = a;
        st_arr[a].fav[0] = b;
        st_arr[a].fav[1] = c;
        st_arr[a].fav[2] = d;
        st_arr[a].fav[3] = e;
    }
}

bool comp(Position a, Position b){
    if(a.near_fav >= b.near_fav){ //1번 조건
        if(a.near_fav == b.near_fav){ //1번 조건을 만족하는 곳이 여러 곳임
            if(a.near_empty >= b.near_empty){ //2번 조건
                if(a.near_empty == b.near_empty){ //2번 조건 만족하는 곳이 여러 곳임
                    if(a.x <= b.x){ //3번 조건
                        if(a.x == b.x){ //3번 조건 만족하는 곳이 여러 곳임
                            if(a.y < b.y){ //4번 최종 조건
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void settingPosition(){
    for(int i=0; i<st.size(); i++){
        vector<Position> pos;
        int st_num = st[i].n;
        
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(map[x][y] != 0) continue; //이미 방문한 곳 패스
                
                int near_fav = 0;
                int near_empty = 0;
                for(int k = 0; k<4; k++){ //인접 위치들 돌아가면서 체크
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; //범위 제한
                    if(map[nx][ny] == 0) near_empty++; //인접한 곳 빈 칸이면 증가
                    else{ //빈칸이 아니면
                        for(int j=0; j<4; j++){
                            if(map[nx][ny] == st[i].fav[j]){
                                near_fav++;
                                break;
                            }
                        }
                    }
                }
                pos.push_back({x, y, near_empty, near_fav});
            }
        }
        sort(pos.begin(), pos.end(), comp);
        int pos_x = pos[0].x;
        int pos_y = pos[0].y;
        map[pos_x][pos_y] = st_num; //해당 위치에 학생 넘버 할당
    }
}

int calculate(int x){
    switch (x){
        case 0: return 0;
        case 1: return 1;
        case 2: return 10;
        case 3: return 100;
        case 4: return 1000;
        default: return 0;
    }
}

void calculateSatisfy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int stn = map[i][j]; //해당 위치의 학생 넘버
            int fav = 0;
            for(int k=0; k<4; k++){
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                
                for(int l=0; l<4; l++){
                    if(map[nx][ny] == st_arr[stn].fav[l]){
                        fav++; break;
                    }
                }
            }
            answer += calculate(fav);
        }
    }
}

void solution(){
    settingPosition();
    calculateSatisfy();
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}

