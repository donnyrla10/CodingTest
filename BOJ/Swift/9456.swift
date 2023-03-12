import Foundation

/*
 2행 n열
 뗀 스티커의 상하좌우 스티커 사용 불가
 점수의 합이 최대가 되도록 스티커를 떼어내려고 한다.
 i번째 열에서 1행을 선택한 경우, 2행을 선택한 경우를 나눠서 진행하면 된다.
 상하좌우가 붙으면 안되니까 한 열에 하나의 행만 선택하고, 이전 열 혹은 전전 열의 다른 행을 선택한 경우를 봐야 한다.
 */

//input
let t = Int(readLine()!)!
for _ in 0..<t {
    let n = Int(readLine()!)!
    var dp = [[Int]]()
    for _ in 0..<2 {
        dp.append(readLine()!.split(separator: " ").map{Int(String($0))!})
    }
    dp[0].insert(0, at: dp.startIndex)
    dp[1].insert(0, at: dp.startIndex)
    if n > 1 {
       for i in 2...n {
            dp[0][i] += max(dp[1][i-1], dp[1][i-2])
            dp[1][i] += max(dp[0][i-1], dp[0][i-2])
        }
    }
    print(max(dp[0][n], dp[1][n]))
}
