#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int A, B, C;
bool visited[201][201][201];
vector<int> ans;
queue<pair<pair<int, int>,int>> q;

void input(){
    cin >> A >> B >> C;
}

void bfs(){
    q.push(make_pair(make_pair(0, 0), C)); //처음에는 A,B = empty, C = full
    while(!q.empty()){
        //a, b, c 는 각 물통의 양
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        
        if(visited[a][b][c]) continue; //방문한 곳이라면 패스
        visited[a][b][c] = true;
        
        if(a==0) ans.push_back(c); //A통이 비었을 때, "C"에 담겨있을 수 있는 물의 양을 구해야 하므로
        
        if(a+b>B) q.push(make_pair(make_pair(a+b-B, B), c)); //A->B
        else      q.push(make_pair(make_pair(0, a+b), c));
        
        if(a+b>A) q.push(make_pair(make_pair(A, a+b-A), c)); //B->A
        else      q.push(make_pair(make_pair(a+b, 0), c));
        
        if(a+c>C) q.push(make_pair(make_pair(a+c-C, b), C)); //A->C
        else      q.push(make_pair(make_pair(0, b), a+c));
        
        if(a+c>A) q.push(make_pair(make_pair(A, b), a+c-A)); //C->A
        else      q.push(make_pair(make_pair(a+c, b), 0));
        
        if(b+c>C) q.push(make_pair(make_pair(a, b+c-C), C)); //B->C
        else      q.push(make_pair(make_pair(a, 0), b+c));
        
        if(b+c>B) q.push(make_pair(make_pair(a, B), b+c-B)); //C->B
        else      q.push(make_pair(make_pair(a, b+c), 0));
    }
}

void output(){
    sort(ans.begin(), ans.end());
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    bfs();
    output();
    return 0;
}
