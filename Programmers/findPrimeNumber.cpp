#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
//#define MAX 640000
using namespace std;
bool visit[10];
int ans = 0;
set<int> ss;
//int prime[MAX];

//void isPrime(){
//    for(int i=2; i<=MAX; i++) prime[i] = i;
//    for(int i=2; i<=sqrt(MAX); i++){
//        if(prime[i] == 0) continue;
//        for(int j=i*i; j<=MAX; j+=i) prime[j] = 0;
//    }
//}

bool isPrime(int x){
    if(x==0||x==1) return false;
    for(int i=2; i<x; i++){
        if(x%i == 0) return false;
    }
    return true;
}

void BT(int cnt, int k, string s, string numbers){
    if(cnt == k){           //k개의 숫자를 모았으면 소수인지 체크
        int n = stoi(s);
        if(isPrime(n)) ss.insert(n); //중복 제거
        return;
    }
    
    int last = 0;
    for(int i=0; i<numbers.size(); i++){
        if(!visit[i] && last != numbers[i]){
            last = numbers[i];
            visit[i] = true;
            BT(cnt+1, k, s+numbers[i], numbers);
            visit[i] = false;
        }
    }
}

//1234567

int solution(string numbers) {
    int answer = 0;
    for(int i=1; i<=numbers.size(); i++){
        memset(visit, false, 10); //초기화
        BT(0, i, "", numbers);    //자릿수 개수(i)
    }
    answer = ss.size();
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//    cout << solution("17") << '\n';         //3 (소수 개수 리턴)
    cout << solution("011") << '\n';
    return 0;
}
