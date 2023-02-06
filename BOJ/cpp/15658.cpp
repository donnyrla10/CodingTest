#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, arr[12], minv=1000000001, maxv=-1000000001;
int op[4]; //+, -, *, /
vector<int> v;

int calc(){
    int result = arr[0];
    for(int i=0; i<v.size(); i++){
        if(v[i] == 0){              // +
            result += arr[i+1];
        }else if(v[i] == 1){        // -
            result -= arr[i+1];
        }else if(v[i] == 2){        // *
            result *= arr[i+1];
        }else if(v[i] == 3){        // /
            result /= arr[i+1];
        }
    }
    return result;
}

void BT(int cnt){
    if(cnt == n-1){
        int result = calc();
        minv = min(minv, result);
        maxv = max(maxv, result);
        return;
    }
    
    for(int i=0; i<4; i++){ //연산자
        if(op[i] != 0){
            op[i]--;
            v.push_back(i); //연산자 번호 넣기 (+:0, -:1, *:2, /:3)
            BT(cnt+1);
            v.pop_back();
            op[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<4; i++) cin >> op[i];
    
    BT(0);
    cout << maxv << '\n' << minv << '\n';
    
    return 0;
}
