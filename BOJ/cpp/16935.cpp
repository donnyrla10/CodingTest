#include <iostream>
#include <algorithm>
using namespace std;
int n, m, r;
int arr[101][101];

void one(){
    for(int i=0; i<n/2; i++) for(int j=0; j<m; j++) swap(arr[i][j], arr[n-1-i][j]);
}

void two(){
    for(int i=0; i<n; i++) for(int j=0; j<m/2; j++) swap(arr[i][j], arr[i][m-1-j]);
}

void three(){ //right 90
    int h = n;
    swap(n, m);
    int tmp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = arr[h-1-j][i];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

void four(){ //left 90
    int w = m;
    swap(n,m);
    int tmp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = arr[j][w-1-i];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

void five(){
    int N = n/2;
    int M = m/2;
    int tmp[n][m];
    
    //1->2 : ++j
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmp[i][j+M] = arr[i][j];
        }
    }
    //2->3 : ++i
    for(int i=0; i<N; i++){
        for(int j=M; j<m; j++){
            tmp[i+N][j] = arr[i][j];
        }
    }
    //3->4 : --j
    for(int i=N; i<n; i++){
        for(int j=M; j<m; j++){
            tmp[i][j-M] = arr[i][j];
        }
    }
    //4->1 : --i
    for(int i=N; i<n; i++){
        for(int j=0; j<M; j++){
            tmp[i-N][j] = arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

void six(){
    int N = n/2;
    int M = m/2;
    int tmp[n][m];
    
    //1->4 : ++i
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmp[i+N][j] = arr[i][j];
        }
    }
    //4->3 : ++j
    for(int i=N; i<n; i++){
        for(int j=0; j<M; j++){
            tmp[i][j+M] = arr[i][j];
        }
    }
    //3->2 : --i
    for(int i=N; i<n; i++){
        for(int j=M; j<m; j++){
            tmp[i-N][j] = arr[i][j];
        }
    }
    //2->1 : --j
    for(int i=0; i<N; i++){
        for(int j=M; j<m; j++){
            tmp[i][j-M] = arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    
    while(r--){
        int op;
        cin >> op;
        switch (op) {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
            default:
                break;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
