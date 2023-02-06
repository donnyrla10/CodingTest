#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    int ia, ib;
    cin >> a >> b;
    
    for(int i=0; i<a.size(); i++) if(a[i] == '6') a[i] = '5';
    for(int i=0; i<b.size(); i++) if(b[i] == '6') b[i] = '5';
    ia = stoi(a); ib = stoi(b);
    cout << ia + ib << ' ';
    
    for(int i=0; i<a.size(); i++) if(a[i] == '5') a[i] = '6';
    for(int i=0; i<b.size(); i++) if(b[i] == '5') b[i] = '6';
    ia = stoi(a); ib = stoi(b);
    cout << ia + ib << '\n';
    return 0;
}
