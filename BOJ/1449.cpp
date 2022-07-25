#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int L, N, pipe[1001];
    cin >> N >> L;
    for(int i=0; i<N; i++) cin >> pipe[i];
    if(L == 1) {
        cout << N << '\n';
        return 0;
    }
    
    sort(pipe, pipe+N);
    
    int cntPipe= 1;
    int s = pipe[0];
    for(int i=1; i<N; i++){
        if(pipe[i] - s + 1 > L) {
            cntPipe++;
            s = pipe[i];
        }
    }
    cout << cntPipe << '\n';
    return 0;
}
