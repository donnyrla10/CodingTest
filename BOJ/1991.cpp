#include <iostream>
using namespace std;
int n;
char c1, c2, c3, root;
char graph[55][2];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c1 >> c2 >> c3;
        if(i==0) root = c1;
        graph[c1-'A'][0] = c2;
        graph[c1-'A'][1] = c3;
    }
}

void pre_order(char x){
    int i = x-'A';
    if(x == '.') return;
    cout << x;
    pre_order(graph[i][0]);
    pre_order(graph[i][1]);
}

void in_order(char x){
    int i = x-'A';
    if(x == '.') return;
    in_order(graph[i][0]);
    cout << x;
    in_order(graph[i][1]);
}

void post_order(char x){
    int i = x-'A';
    if(x == '.') return;
    post_order(graph[i][0]);
    post_order(graph[i][1]);
    cout << x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    pre_order(root);  cout << '\n';
    in_order(root);   cout << '\n';
    post_order(root); cout << '\n';
    return 0;
}
