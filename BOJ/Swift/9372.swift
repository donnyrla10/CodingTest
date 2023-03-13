import Foundation

/*
 최대한 적은 종류의 비행기를 타고 국가를 이동하려고 한다
 한 국가에서 다른 국가로 이동할 때, 다른 국가를 거쳐 가도 된다 (이미 방문한 곳도 가능)
 */

//input
let t = Int(readLine()!)!
var cnt = 0

func dfs(_ now: Int, _ visited: inout [Bool], _ flights: [[Int]]) {
    visited[now] = true
    for flight in flights[now] {
        if visited[flight] { continue }
        cnt += 1
        dfs(flight, &visited, flights)
    }
}

func solution() {
    let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let (n, m) = (nm[0], nm[1])
    var flights = [[Int]](repeating: [], count: n+1)
    var visited = [Bool](repeating: false, count: n+1)
    for _ in 0..<m {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        flights[input[0]].append(input[1])
        flights[input[1]].append(input[0])
    }
    dfs(1, &visited, flights)
    print(cnt)
    cnt = 0
}

for _ in 0..<t {
    solution()
}
