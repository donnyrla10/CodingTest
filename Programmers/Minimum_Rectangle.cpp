#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int l = 0; int s = 0;
    for(int i=0; i<sizes.size(); i++){
        l = max(l, max(sizes[i][0], sizes[i][1]));
        s = max(s, min(sizes[i][0], sizes[i][1]));
    }
    answer = l * s;
    return answer;
}
