#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//각 노드에 빌딩 번호.
//가장 마지막 레벨을 제외한 모든 집에는 왼/오 자식 있음
//빌딩에 들어간 순서대로 번호를 종이에 적어놓았다.
//1. 가장 먼저 루트 빌딩
//2. 빌딩 왼쪽 - 현재 - 오른쪽
//3. 모두 방문했으면 부모 노드로 이동.

vector<int> arr;
vector<int> answer[10];

void CompleteBinaryTree(int s, int e, int depth){
    if(s == e){
        answer[depth].push_back(arr[s]);
        return;
    }
    
    int m = (s+e)/2;             //가운데 원소 -> root
    answer[depth].push_back(arr[m]);  //root 가장 먼저 넣기 (깊이에 따라 달리)
    CompleteBinaryTree(s, m-1, depth+1);   //좌측 서브 트리
    CompleteBinaryTree(m+1, e, depth+1); //오측 서브 트리
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    for(int i=0; i<pow(2, k)-1; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    CompleteBinaryTree(0,arr.size()-1,0); //start, end, depth
    
    for(int i=0; i<k; i++){
        for(auto a : answer[i])
            cout << a << ' ';
        cout << '\n';
    }
    
    return 0;
}
