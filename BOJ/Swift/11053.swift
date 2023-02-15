import Foundation

/*
 가장 긴 증가하는 부분 수열
 */

//input
let n = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var dp = [Int](repeating: 0, count: 1001)

for i in 1...n { //현재 원소
    dp[i] = 1
    for j in 1..<i { //앞에 있는 원소들
        if arr[j-1] < arr[i-1] {
            dp[i] = max(dp[j] + 1, dp[i])
        }
    }
}
print(dp.max()!)
