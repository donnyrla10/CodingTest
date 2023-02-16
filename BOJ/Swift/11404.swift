import Foundation

/*
 n개의 도시. -> 정점 개수
 한 도시에서 출발해 다른 도시에 도착하는 m개의 버스 -> 간선 개수
 각 버스는 한 번 사용할 때 필요한 비용
 모든 도시 쌍에대해서 A에서 B로 가는데 필요한 최솟값 구하기
 */

//input
let n = Int(readLine()!)! //도시 n개 -> 정점 개수
let m = Int(readLine()!)! //버스 m개 -> 간선 개수
var adj = [[Int]](repeating: [Int](repeating: 0, count: n+1), count: n+1)
let INF = 987654321
for _ in 0..<m {
    let vertex = readLine()!.split(separator: " ").map{ Int(String($0))! }
    adj[vertex[0]][vertex[1]] = adj[vertex[0]][vertex[1]] == 0 ? vertex[2] : min(adj[vertex[0]][vertex[1]], vertex[2])
}

for i in 1...n {
    for j in 1...n {
        if i == j { //자기 자신
            adj[i][j] = 0
        }else if adj[i][j] == 0 { //가는 길이 없다는 뜻
            adj[i][j] = INF
        }
    }
}

//floyd algorithm
for k in 1...n { //라운드 n번 진행
    for i in 1...n {
        for j in 1...n {
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])
        }
    }
}
for i in 1...n {
    for j in 1...n {
        if adj[i][j] == INF {
            print(0, terminator: " ")
        }else {
            print(adj[i][j], terminator: " ")
        }
    }
    print("")
}
