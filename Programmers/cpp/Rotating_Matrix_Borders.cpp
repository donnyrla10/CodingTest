#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int arr[rows+1][columns+1];
    int v = 1;
    for(int i=1; i<=rows; i++) for(int j=1; j<=columns; j++) arr[i][j] = v++;
    
    for(int i=0; i<queries.size(); i++){
        int r1 = queries[i][0]; int r2 = queries[i][2];
        int c1 = queries[i][1]; int c2 = queries[i][3];
        int cx = r1; int cy = c1;
        int cur = arr[cx][cy];
        int minv = cur;
        
        //top
        while(cy < c2){
            int next = arr[cx][cy+1];
            if(minv > next) minv = next;
            arr[cx][cy+1] = cur;
            cur = next;
            cy++;
        }
        
        //right
        while(cx < r2){
            int next = arr[cx+1][cy];
            if(minv > next) minv = next;
            arr[cx+1][cy] = cur;
            cur = next;
            cx++;
        }
        
        //bottom
        while(cy > c1){
            int next = arr[cx][cy-1];
            if(minv > next) minv = next;
            arr[cx][cy-1] = cur;
            cur = next;
            cy--;
        }
        
        //left
        while(cx > r1){
            int next = arr[cx-1][cy];
            if(minv > next) minv = next;
            arr[cx-1][cy] = cur;
            cur = next;
            cx--;
        }
        answer.push_back(minv);
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    vector<vector<int> > maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    answer = solution(3, 3, {{1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3}});
    for(auto i: answer) cout << i << ' ';
    cout << '\n';
    return 0;
}
