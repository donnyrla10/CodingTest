#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int monitoringSpace = 0;
int space = 0;
int cctvCnt = 0;
int office[9][9]; //0으로 초기화
int tmpOffice[9][9];
vector<int> cctvCase; //시시티비의 순서에 따른 시시번호의 방향
vector<int> cctv; //오피스에 있는 시시티비 번호
vector<pair<int, int>> cctvPos; //시시티비 좌표
//0: 빈칸, 1~5: CCTV, 6: 벽
//감시할 수 있는 영역 (#)

void cctv01(int d, int x, int y){
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dx = x + dir[d][0]; //다음 위치
    int dy = y + dir[d][1];
    while(0<=dx && dx<n && 0<=dy && dy<m && tmpOffice[dx][dy] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx][dy] == 0) tmpOffice[dx][dy] = -1; //#
        dx = dx + dir[d][0]; //update
        dy = dy + dir[d][1]; //update
    }
}

void cctv02(int d, int x, int y){
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dx1 = x + dir[d][0]; //다음 위치
    int dx2 = x + dir[d+2][0];
    int dy1 = y + dir[d][1];
    int dy2 = y + dir[d+2][1];
    //1
    while(0<=dx1 && dx1<n && 0<=dy1 && dy1<m && tmpOffice[dx1][dy1] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx1][dy1] == 0) tmpOffice[dx1][dy1] = -1; //#
        dx1 = dx1 + dir[d][0]; //update
        dy1 = dy1 + dir[d][1]; //update
    }
    //2
    while(0<=dx2 && dx2<n && 0<=dy2 && dy2<m && tmpOffice[dx2][dy2] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx2][dy2] == 0) tmpOffice[dx2][dy2] = -1; //#
        dx2 = dx2 + dir[d+2][0]; //update
        dy2 = dy2 + dir[d+2][1]; //update
    }
}

void cctv03(int d, int x, int y){
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int dx1 = x + dir[d][0]; //다음 위치
    int dx2 = x + dir[(d+1)%4][0];
    int dy1 = y + dir[d][1];
    int dy2 = y + dir[(d+1)%4][1];
    //1
    while(0<=dx1 && dx1<n && 0<=dy1 && dy1<m && tmpOffice[dx1][dy1] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx1][dy1] == 0) tmpOffice[dx1][dy1] = -1; //#
        dx1 = dx1 + dir[d][0]; //update
        dy1 = dy1 + dir[d][1]; //update
    }
    //2
    while(0<=dx2 && dx2<n && 0<=dy2 && dy2<m && tmpOffice[dx2][dy2] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx2][dy2] == 0) tmpOffice[dx2][dy2] = -1; //#
        dx2 = dx2 + dir[(d+1)%4][0]; //update
        dy2 = dy2 + dir[(d+1)%4][1]; //update
    }
}

void cctv04(int d, int x, int y){
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int dx1 = x + dir[d][0]; //다음 위치
    int dx2 = x + dir[(d+1)%4][0];
    int dx3 = x + dir[(d+2)%4][0];
    int dy1 = y + dir[d][1];
    int dy2 = y + dir[(d+1)%4][1];
    int dy3 = y + dir[(d+2)%4][1];
    
    //1
    while(0<=dx1 && dx1<n && 0<=dy1 && dy1<m && tmpOffice[dx1][dy1] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx1][dy1] == 0) tmpOffice[dx1][dy1] = -1; //#
        dx1 = dx1 + dir[d][0]; //update
        dy1 = dy1 + dir[d][1]; //update
    }
    //2
    while(0<=dx2 && dx2<n && 0<=dy2 && dy2<m && tmpOffice[dx2][dy2] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx2][dy2] == 0) tmpOffice[dx2][dy2] = -1; //#
        dx2 = dx2 + dir[(d+1)%4][0]; //update
        dy2 = dy2 + dir[(d+1)%4][1]; //update
    }
    //3
    while(0<=dx3 && dx3<n && 0<=dy3 && dy3<m && tmpOffice[dx3][dy3] != 6) { //범위내 && 벽이 아닌 경우
        if(tmpOffice[dx3][dy3] == 0) tmpOffice[dx3][dy3] = -1; //#
        dx3 = dx3 + dir[(d+2)%4][0]; //update
        dy3 = dy3 + dir[(d+2)%4][1]; //update
    }
}

void cctv05(int x, int y){
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i=0; i<4; i++){
        int dx = x + dir[i][0]; //다음 위치
        int dy = y + dir[i][1];
        while(0<=dx && dx<n && 0<=dy && dy<m && tmpOffice[dx][dy] != 6) { //범위내 && 벽이 아닌 경우
            if(tmpOffice[dx][dy] == 0) tmpOffice[dx][dy] = -1; //#
            dx = dx + dir[i][0]; //update
            dy = dy + dir[i][1]; //update
        }
    }
}

int countingSpace(){
    int result = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(tmpOffice[i][j] == -1) result++;
    return result;
}

void makeCase(int cnt){ //각 cctv의 방향 정하기
    if(cnt == cctvCnt){ //모든 cctv의 방향 설정함
        //cctvCase를 활용해서 각 cctv의 감시부분 채우기
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) tmpOffice[i][j] = office[i][j];
        for(int i=0; i<cctvCnt; i++){
            switch (cctv[i]) {
                case 1:
                    cctv01(cctvCase[i], cctvPos[i].first, cctvPos[i].second); break;
                case 2:
                    cctv02(cctvCase[i], cctvPos[i].first, cctvPos[i].second); break;
                case 3:
                    cctv03(cctvCase[i], cctvPos[i].first, cctvPos[i].second); break;
                case 4:
                    cctv04(cctvCase[i], cctvPos[i].first, cctvPos[i].second); break;
                case 5:
                    cctv05(cctvPos[i].first, cctvPos[i].second); break;
                default: break;
            }
        }
        //채워진 감시 부분을 제외한 부분 카운팅 -> 최댓값 업데이트
        monitoringSpace = max(monitoringSpace, countingSpace());
        return;
    }
    
    for(int i=0; i<4; i++){ //4방향
        if(cctv[cnt] == 2 && (i == 2 || i == 3)) continue; //cctv2번은 2가지 방향만
        if(cctv[cnt] == 5 && (i == 1 || i == 2 || i == 3)) continue; //cctv5번은 1가지 방향만
        cctvCase.push_back(i);
        makeCase(cnt + 1);
        cctvCase.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> office[i][j];
            if(office[i][j] == 0) space++;
            else if(office[i][j] >= 1 && office[i][j] <= 5) {
                cctv.push_back(office[i][j]);
                cctvPos.push_back({i, j});
                cctvCnt++;
            }
        }
    }
    makeCase(0);
    cout << space - monitoringSpace << '\n';
    return 0;
}
