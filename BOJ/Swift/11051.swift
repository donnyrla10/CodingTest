import Foundation

//input
let nk = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n, k) = (nk[0], nk[1])
var dp = [[Int]](repeating: [Int](repeating: 1, count: n + 1), count: n + 1)
for i in 1...n {
    for j in 0...i {
        if j == 0 || j == i {
            dp[i][j] = 1
        }else {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007
        }
    }
}
print(dp[n][k])
