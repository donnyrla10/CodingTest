import Foundation

//input
let n = Int(readLine()!)!
var dp = [Int](repeating: 0, count: 5001)
dp[3] = 1
dp[5] = 1
dp[6] = 2
if n >= 8 {
    for i in 8...n {
        dp[i] = min(dp[i-3] == 0 ? n+1 : dp[i-3], dp[i-5] == 0 ? n+1 : dp[i-5]) + 1
    }
}
print(dp[n] == 0 ? -1 : dp[n])
