import Foundation

//input
let n = Int(readLine()!)!
var arr = [0]
var dp = [Int](repeating: 0, count: 10002)
for _ in 0..<n {
    arr.append(Int(readLine()!)!)
}
var answer = 0 //max value

//dp[i]는 i번째까지 포도주를 마신 최대양
dp[1] = arr[1]
if n > 1 {
    dp[2] = arr[1] + arr[2]
}
if n > 2 {
    for i in 3...n {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i], dp[i-1])
    }
}
print(dp[n])

//import Foundation
//
////input
//let n = Int(readLine()!)!
//var arr = [0]
//var dp = [[Int]](repeating: [Int](repeating: 0, count: 10002), count: 2)
//for _ in 0..<n {
//    arr.append(Int(readLine()!)!)
//}
//var answer = 0 //max value
//
////dp[0][i] = i-1 안먹기
////dp[1][i] = i-1 먹기
//
//dp[0][1] = arr[1]
//dp[1][1] = arr[1]
//
//if n == 1 {
//    print(arr[1])
//}else {
//    dp[0][2] = arr[2]
//    dp[1][2] = arr[2] + arr[1]
//    if n <= 2 {
//        print(dp[1][n])
//    }else {
//        for i in 3...n {
//            dp[0][i] = max(dp[0][i-2], dp[1][i-2], dp[1][i-3], dp[0][i-3]) + arr[i]
//            dp[1][i] = dp[0][i-1] + arr[i]
//        }
//        print([dp[0][n], dp[1][n], dp[1][n-1], dp[0][n-1]].max()!)
//    }
//}
