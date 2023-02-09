import Foundation

let t = Int(readLine()!)!
for _ in 0..<t {
    let n = Int(readLine()!)!
    var dp = [Int](repeating: 0, count: 12)
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    guard n >= 4 else { print(dp[n]); continue; }
    for i in 4...n {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    }
    print(dp[n])
}

//let T = Int(readLine()!)!
//var dp = [0, 1, 2, 4]
//for i in 4...10 {
//    dp.append(dp[i-1] + dp[i-2] + dp[i-3])
//}
//for _ in 0..<T {
//    let n = Int(readLine()!)!
//    print(dp[n])
//}
