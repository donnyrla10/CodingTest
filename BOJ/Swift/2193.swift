import Foundation

/*
 0으로 시작 ㄴㄴ
 1이 두 번 연속으로 나타나지 않음
 dp[1][i] = i자리가 1인 경우
 dp[0][i] = i자리가 0인 경우
 */

//input
let n = Int(readLine()!)!
var dp = [[Int]](repeating: [Int](repeating: 0, count: n+2), count: 2)
dp[1][1] = 1
dp[0][1] = 0
if n > 1 {
    for i in 2...n {
        dp[0][i] = dp[0][i-1] + dp[1][i-1]
        dp[1][i] = dp[0][i-1]
    }
}
print(dp[0][n] + dp[1][n])

