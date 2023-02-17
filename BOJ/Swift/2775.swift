import Foundation

/*
 부녀회장이 될테야
 a층의 b호에 살려면 자신의 아래층(a-1)의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다
 k층에 n호에는 몇 명이 살고 있는가?
 0층부터 있고, 각 층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.
 */

//input
let t = Int(readLine()!)!
var dp = [[Int]](repeating: [Int](repeating: 0, count: 15), count: 15)
for i in 1...14 {
    dp[0][i] = i
}

for i in 1...14 {
    for j in 1...14 {
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
    }
}

for _ in 0..<t {
    let k = Int(readLine()!)!
    let n = Int(readLine()!)!
    print(dp[k][n])
}
