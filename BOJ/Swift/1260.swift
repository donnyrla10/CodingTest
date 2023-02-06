import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = input[0]
let m = input[1]
let v = input[2]

var graph = [[Int]](repeating: [], count: n+1)
for _ in 0..<m {
    let vertices = readLine()!.split(separator: " ").map{ Int(String($0))! }
    graph[vertices[0]].append(vertices[1])
    graph[vertices[1]].append(vertices[0])
}

for i in 1...n {
    graph[i] = graph[i].sorted()
}

func BFS() { //while
    var queue = [v]
    var front = 0
    visited[v] = true
    
    while queue.count > front {
        let x = queue[front]
        print(x, terminator: " ")
        front += 1
        
        for next in graph[x] {
            guard !visited[next] else { continue }
            visited[next] = true
            queue.append(next)
        }
    }
}

func DFS(now: Int) { //recursion
    visited[now] = true
    print(now, terminator: " ")
    
    for next in graph[now] {
        guard !visited[next] else { continue }
        DFS(now: next)
    }
}

var visited = [Bool](repeating: false, count: n+1)
DFS(now: v)
print("")
visited = [Bool](repeating: false, count: n+1)
BFS()
