//#include <iostream>
//using namespace std;
//int R, C, s_cnt, w_cnt, total_s=0, total_w=0;
//char yard[251][251];
//bool visited[251][251];
//int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//
//void input(){
//    cin >> R >> C;
//    for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin >> yard[i][j];
//}
//
//void dfs(int x, int y){
//    visited[x][y] = true;
//    if(yard[x][y] == 'o') s_cnt++;
//    else if(yard[x][y] == 'v') w_cnt++;
//    for(int i=0; i<4; i++){
//        int dx = x + dir[i][0];
//        int dy = y + dir[i][1];
//        if(visited[dx][dy]) continue;       //방문한 곳
//        if(yard[dx][dy] == '#') continue;   //'#'울타리로 이동 불가
//        if(dx < 1 || dy < 1 || dx > R-2 || dy > C-2) continue; //범위 바깥
//        dfs(dx, dy);
//    }
//}
//
//void solution(){
//    for(int x=1; x<R-1; x++){
//        for(int y=1; y<C-1; y++){
//            if(!visited[x][y] && yard[x][y] != '#'){
//                s_cnt = w_cnt = 0; //초기화(dfs 들어가기전에)
//                dfs(x, y);
//                s_cnt > w_cnt ? total_s += s_cnt: total_w += w_cnt; //전체 카운팅 업뎃
//            }
//        }
//    }
//    cout << total_s << ' ' << total_w << '\n';
//}
//
//int main(){
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    input();
//    solution();
//    return 0;
//}
