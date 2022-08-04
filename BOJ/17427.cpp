#include <iostream>
#include <algorithm>
using namespace std;

//a, b
//a=bc를 만족하는 자연수 c를 a의 약수
//A의 약수의 합은 A의 모든 약수를 더한 값 = f(A)
//x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)
//N이 주어졌을 때, g(N) 구하기
//N보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값 = g(N)

//ex) N=4 (1, 2, 4)
//f(1)=1, f(2)=3, f(3)=4, f(4)=7 -> 15

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long gn = 0;
    for(int i=1; i<=n; i++){
        gn += (n/i)*i;
    }
    cout << gn << '\n';
    return 0;
}
