import Foundation

/*
 RGB거리에 집이 N개
 빨, 초, 파 중 하나로 색칠하기
 1. 1번 집의 색은 2번 집의 색과 달라야 한다
 2. n번 집의 색은 n-1번 집의 색과 달라야 한다
 3. i번 집의 색은 i-1번, i+1번 집과 색이 달라야 한다.
 모든 집을 칠하는 비용의 최솟값 구하기
 */

//input
let n = Int(readLine()!)!
var houses = [(Int, Int, Int)]() //red, green, blue
var dp = [[Int]](repeating: [Int](repeating: 0, count: 1001), count: 4)
for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    houses.append((input[0], input[1], input[2]))
}
dp[1][1] = houses[0].0 //r
dp[2][1] = houses[0].1 //g
dp[3][1] = houses[0].2 //b

for i in 2...n {
    dp[1][i] = houses[i-1].0 + min(dp[2][i-1], dp[3][i-1])
    dp[2][i] = houses[i-1].1 + min(dp[1][i-1], dp[3][i-1])
    dp[3][i] = houses[i-1].2 + min(dp[2][i-1], dp[1][i-1])
}
print(min(dp[1][n], min(dp[2][n], dp[3][n])))
