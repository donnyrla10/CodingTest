#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
vector<pair<char, string>> p;

int findPair(char s){
    for(int i=0; i<p.size(); i++){
        if(p[i].first == s) return i;
    }
    return -1;
}

bool checkS(char c, string str){
    for(int i=0; i<p.size(); i++){
        if(p[i].second == str){
            if(p[i].first != c) return false;
        }
    }
    return true;
}

bool wordPattern(string pattern, string s) {
    bool answer = true;
    stringstream ss(s);
    string buffer;
    vector<string> v;
    while(getline(ss, buffer, ' ')) v.push_back(buffer);
    
    if(pattern.size() != v.size()) return false;
    
    for(int i=0; i<pattern.size(); i++){
        int index = findPair(pattern[i]);
        if(!checkS(pattern[i], v[i])) return false;
        if(index == -1){ //짝이 없다면
            p.push_back({pattern[i], v[i]});
            
        }else{
            if(p[index].second != v[i]) return false;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << wordPattern("abba", "dog dog dog dog") << '\n';
    cout << wordPattern("abba", "dog cat cat fish") << '\n';
    return 0;
}
