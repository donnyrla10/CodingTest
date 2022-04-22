#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string order;
    bool cups[3] = {1, 0, 0};
    cin >> order;
    for(int i=0; i<order.length(); i++){
        if(order[i] == 'A'){
            swap(cups[0], cups[1]);
        }else if(order[i] == 'B'){
            swap(cups[1], cups[2]);
        }else if(order[i] == 'C'){
            swap(cups[0], cups[2]);
        }
    }
    for(int i=0; i<3; i++){
        if(cups[i] == 1) cout << i+1 << '\n';
    }
    return 0;
}
