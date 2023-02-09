import Foundation

let n = Int(readLine()!)!
var card = readLine()!.split(separator: " ").map{ Int(String($0))! }
card.insert(0, at: card.startIndex)
var dp = [Int](repeating: 0, count: n+2)

for i in 1...n {
    for j in 1...i {
        dp[i] = max(dp[i], dp[i-j] + card[j])
    }
}
print(dp[n])
