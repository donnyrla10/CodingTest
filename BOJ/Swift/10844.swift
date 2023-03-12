import Foundation

//input
let n = Int(readLine()!)!
var dp = [[Int]](repeating: [Int](repeating: 0, count: 10), count: n+2)
var answer = 0

for i in 1...9 {
    dp[1][i] = 1
}
if n > 1 {
    for i in 2...n {
        for j in 0...9 {
            if j == 0 {
                dp[i][j] = dp[i-1][j+1] % 1000000000
            }else if j == 9 {
                dp[i][j] = dp[i-1][j-1] % 1000000000
            }else {
                dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % 1000000000
            }
        }
    }
}

for i in 0...9 {
    answer += dp[n][i]
}
print(answer % 1000000000)
