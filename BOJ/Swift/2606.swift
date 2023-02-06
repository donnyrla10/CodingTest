import Foundation

/*
 바이러스: 한 컴퓨터가 바이러스에 걸리면 컴퓨터와 네트워크 상에 연결된 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
 1번 컴퓨터가 웜 바이러스에 걸렸다. 바이러스에 걸리는 컴퓨터 수는?
 */

let n = Int(readLine()!)!
let m = Int(readLine()!)!
var graph = [[Int]](repeating: [], count: n+1)
var answer = 0
var visited = [Bool](repeating: false, count: n+1)
for _ in 0..<m {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    graph[input[0]].append(input[1])
    graph[input[1]].append(input[0])
}

func BFS() {
    var queue = [1]
    var front = 0
    visited[1] = true
    
    while queue.count > front {
        let x = queue[front]
        front += 1
        
        for next in graph[x] {
            guard !visited[next] else { continue }
            visited[next] = true
            queue.append(next)
            answer += 1
        }
    }
}

BFS()
print(answer)
