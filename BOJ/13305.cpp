#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long sum = 0, ans = 0;
    vector<long long> dis;
    vector<long long> oil;
    
    cin >> n;
    for(int i=0; i<n-1; i++){
        int d;
        cin >> d;
        dis.push_back(d);
    }
    for(int i=0; i<n; i++){
        int o;
        cin >> o;
        oil.push_back(o);
    }
    
    for(int i=0; i<n; i++){
        int j = 0;
        if(oil[i] > oil[i+1]){
            ans += oil[i] * dis[i];
        }else{
            for(j=i+1; j<n; j++){
                sum += dis[j-1];
                if(oil[j] < oil[i]){
                    ans += oil[i] * sum;
                    if(j == n-1) i = j;
                    else i = j-1;
                    sum = 0; //초기화
                    break;
                }
            }
        }
        if(j == n) {
            ans += oil[i] * sum;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
