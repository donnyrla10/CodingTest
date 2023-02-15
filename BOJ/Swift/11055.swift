import Foundation

/*
 A의 증가 부분 수열 중에서 합이 가장 큰 것을 구하자
 */

//input
let n = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var dp = [Int](repeating: 0, count: 1001)

for i in 1...n {
    dp[i] = arr[i-1]
    for j in 1..<i {
        if arr[i-1] > arr[j-1] {
            dp[i] = max(dp[j] + arr[i-1], dp[i])
        }
    }
}
print(dp.max()!)
