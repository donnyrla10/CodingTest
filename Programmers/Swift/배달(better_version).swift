import Foundation

var INF = 2100000000

func dijkstra(_ node: Int, _ G: inout [[(Int, Int)]], _ D: inout [Int]) {
    var PQ = [(Int,Int)]()
    PQ.append((1,D[node]))

    while(!PQ.isEmpty) {
        PQ.sort { $0.1 > $1.1 }
        let nowNode = PQ.last!.0
        let nowDistance = PQ.last!.1
        PQ.removeLast()
        for i in G[nowNode].indices {
            let nextNode = G[nowNode][i].0
            let nextDistance = G[nowNode][i].1 + nowDistance
            if nextDistance < D[nextNode] {
                D[nextNode] = nextDistance
                PQ.append((nextNode, nextDistance))
            }
        }
    }
}

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var answer = 0
    var G = [[(Int, Int)]](repeating: [], count: N+1)
    var distance = [Int](repeating: INF, count: N+1)
    distance[1] = 0

    for i in road.indices {
        G[road[i][0]].append((road[i][1],road[i][2]));
        G[road[i][1]].append((road[i][0],road[i][2]));
    }

    dijkstra(1, &G, &distance)
    for i in 1...N {
        if distance[i] <= k { answer += 1 }
    }

    return answer
}
