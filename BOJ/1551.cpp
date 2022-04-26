#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    vector<int> a;
    string s, token;

    cin >> n >> k;
    int len = n;
    cin >> s;
    
    stringstream ss(s);

    while(getline(ss, token, ',')){
        a.push_back(stoi(token));
    }
    
    while(k--){
        for(int i=1; i<len; i++){
            a[i-1] = a[i] - a[i-1];
        }
        len -= 1;
    }
    
    for(int i=0; i<len; i++){
        if(i == len-1) cout << a[i];
        else           cout << a[i] << ',';
    }
    cout << '\n';
    
    return 0;
}
