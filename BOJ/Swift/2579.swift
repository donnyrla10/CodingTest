import Foundation

/*
 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임
 각각의 계단에는 일정한 점수가 쓰여있는데, 계단을 밟으면 그 계단에 쓰인 점수 얻음
 1. 한번에 한계단 혹은 두계단
 2. 연속된 3개의 계단을 모두 밟으면 안됨. 시작점은 계단 아님
 3. 마지막 도착 계단은 반드시 밟아야 됨
 최대 점수 출력
 */

//input
let n = Int(readLine()!)!
var stair = [0]
var dp = [[Int]](repeating: [Int](repeating: 0, count: 2), count: n+2)
for _ in 0..<n {
    stair.append(Int(readLine()!)!)
}

//dp[0][i]: i-1번 밟지 않고, i번 도착
//dp[1][i]: i-1번 밟고, i번 도착

//초기화
dp[1][0] = 0
dp[1][1] = stair[1]
if n == 1 {
    print(stair[1])
}else if n == 2 {
    print(stair[1] + stair[2])
}else {
    dp[2][0] = stair[2]
    dp[2][1] = stair[2] + stair[1]
    for i in 3...n {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stair[i]
        dp[i][1] = dp[i-1][0] + stair[i]
    }
    print(max(dp[n][0], dp[n][1]))
}
