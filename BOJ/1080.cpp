#include <iostream>
using namespace std;
#define MAX 50

char a[MAX][MAX], b[MAX][MAX];

void change(int y, int x)
{
    for (int i = y; i < y + 3; i++){
        for (int j = x; j < x + 3; j++){
            a[i][j] = a[i][j] == '1' ? '0' : '1';
        }
    }
}

int Solution(int N, int M)
{
    int answer = 0;

    for (int i = 0; i < N - 2; i++){
        for (int j = 0; j < M - 2; j++){
            if (a[i][j] != b[i][j]){
                change(i, j);
                answer++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(a[i][j] != b[i][j])
                return -1;
        }
    }
    return answer;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> a[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> b[i][j];
    cout << Solution(N, M) << '\n';
    return 0;
}
