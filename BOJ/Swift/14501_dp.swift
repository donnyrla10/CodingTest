import Foundation

//input
let n = Int(readLine()!)!
var arr = [(Int, Int)]() //기간, 이익
var dp = [Int](repeating: 0, count: 17)
for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    arr.append((input[0], input[1]))
}
var answer = 0
for i in 0..<n {
    if arr[i].0 + i > n { continue }
    dp[i] = arr[i].1
    for j in 0..<i {
        if arr[j].0 + j <= i {
            dp[i] = max(dp[i], arr[i].1 + dp[j])
        }
    }
    answer = max(answer, dp[i])
}
print(answer)
