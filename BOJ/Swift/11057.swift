import Foundation

//input
let n = Int(readLine()!)!
var dp = [[Int]](repeating: [Int](repeating: 0, count: 11), count: n+1) //오르막수 개수

//initial
dp[0][0] = 0
for i in 0..<10 {
    dp[1][i] = 1
}
for i in 0...n {
    dp[i][0] = 1
}
if n == 1 {
    print(10)
}else {
    for i in 2...n {
        for j in 1..<10 {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007
        }
    }
    print(dp[n].reduce(0, +) % 10007)
}
