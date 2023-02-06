import Foundation

/*
 각 점은 N개의 색깔 중 하나를 갖는다
 각 점 p에 대해서, p에서 시작하는 직선 화살표를 이용해 다른 점 q를 연결하려고 한다.
 여기서 점 q는 p와 같은 색깔의 점 중 p와 거리가 가장 가까운 점 (가까운 점이 두 개이상이면 아무거나 선택)
 모든 점에서 시작하는 화살표들의 길이 합을 출력
 point = (index, color)
 */

//input
let n = Int(readLine()!)!
var answer = 0
var points = [(Int, Int)]()
for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    points.append((input[0], input[1]))
}
points = points.sorted { $0.1 == $1.1 ? $0.0 < $1.0 : $0.1 < $1.1 } //색상기준, 인덱스 오름차순으로 정렬

//각 점을 순회하면서 왼쪽, 오른쪽 방향으로 최소 화살표 길이 구하기
for i in 0..<n {
    var left = 0
    var right = 0
    if i - 1 >= 0 {
        if points[i].1 == points[i-1].1 {
            left = points[i].0 - points[i-1].0
        }
    }
    if i + 1 < n {
        if points[i].1 == points[i+1].1 { //같은 색이라면
            right = points[i+1].0 - points[i].0
        }
    }
    if left == 0 { answer += right }
    else if right == 0 { answer += left }
    else { answer += min(left, right) }
}
print(answer)
