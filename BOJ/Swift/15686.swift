import Foundation

/*
 치킨거리: 집과 가장 가까운 치킨집 사이의 거리.
 도시의 치킨 거리 = 모든 집의 치킨 거리 합
 0 빈칸, 1 집, 2 치킨집
 가장 수익을 많이 낼 수 있는 치킨 집 개수는 최대 M
 도시의 치킨 거리가 가장 작게되도록 치킨 집을 고르고, 도시의 치킨 거리의 최솟값을 구해라
 */

//input
let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n, m) = (nm[0], nm[1])
var arr = [[Int]]()
var chickens = [(Int, Int)]()
var houses = [(Int, Int)]()
var answer = 987654321
for _ in 0..<n {
    arr.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}
for i in 0..<n {
    for j in 0..<n {
        if arr[i][j] == 1 {
            houses.append((i, j))
        }else if arr[i][j] == 2 {
            chickens.append((i, j))
        }
    }
}

//치킨집 1~M개 선택(조합, 순열아님!!) -> [1, 2, 4] == [2, 4, 1] == [4, 1, 2] === ...
//func DFS(_ start: Int, _ selection: [(Int, Int)], _ cnt: Int) {
//    if cnt == m { //m개의 치킨집 선택
//        answer = min(answer, calculator(selection))
//        return
//    }
//    for i in start..<chickens.count {
//        DFS(i+1, selection + [chickens[i]], cnt+1)
//        DFS(i+1, selection, cnt+1)
//    }
//}

//치킨집 M개 선택(조합, 순열아님!!) -> [1, 2, 4] == [2, 4, 1] == [4, 1, 2] === ...
func DFS(_ start: Int, _ selection: [(Int, Int)]) {
    if selection.count == m { //m개의 치킨집 선택
        answer = min(answer, calculator(selection))
        return
    }
    for i in start..<chickens.count {
        DFS(i+1, selection + [chickens[i]])
    }
}

//치킨집과 집마다의 최소 거리 합 구하기
func calculator(_ selectedChicken: [(Int, Int)]) -> Int {
    var sum = 0
    for house in houses {
        var tmp = 987654321
        for chicken in selectedChicken {
            let minD = abs(chicken.0 - house.0) + abs(chicken.1 - house.1)
            tmp = min(minD, tmp)
        }
        sum += tmp
    }
    return sum
}

DFS(0, [])
print(answer)
