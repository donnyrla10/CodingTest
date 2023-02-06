#include <iostream>
using namespace std;

int node[10000];
int i;

//50 30 24 5 28 45 98 52 69

void post(int start, int end){
    if(start>=end) return;
    
    for(i=start+1; i<end; i++)
        if(node[start] < node[i]) break; //다음 원소가 더 크면 여기서부터 오른쪽 서브트리
    
    post(start+1, i); //Left SubTree   (start+1 ~ i-1)
    post(i, end);     //Right SubTree  (i ~ end-1)
    cout << node[start] << '\n';
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, index=0;
    while (cin>>n) {
        if (n == EOF) break;
        node[index++] = n;
    }
    post(0, index);
    return 0;
}
