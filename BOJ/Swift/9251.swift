import Foundation

//input
let a = readLine()!.map{ String($0) }
let b = readLine()!.map{ String($0) }
var dp = [[Int]](repeating: [Int](repeating: 0, count: 1001), count: 1001)

//문자열 a를 기준으로
for i in 1...a.count {
    //문자열 b를 순회
    for j in 1...b.count {
        //만약 같은 문자! -> 이전 칸 + 1 (공통문자열길이+1)
        if a[i-1] == b[j-1] {
            dp[i][j] = dp[i-1][j-1] + 1
        }else { //다른 문자! -> 왼쪽 원소와 윗 원소 비교
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        }
    }
}
print(dp[a.count][b.count])

//문자열 a 문자를 시작점으로 b와 비교
