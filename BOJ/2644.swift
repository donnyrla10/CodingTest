import Foundation

let n = Int(readLine()!)!
let people = readLine()!.split(separator: " ").map{ Int(String($0))! }
let one = people[0]
let two = people[1]
let m = Int(readLine()!)!
var graph = [[Int]](repeating: [], count: n+1)
var visited = [Int](repeating: -1, count: n+1)
for _ in 0..<m {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    graph[input[0]].append(input[1])
    graph[input[1]].append(input[0])
}
func BFS() -> Int {
    var queue = [one]
    var front = 0
    visited[one] = 0
    
    while queue.count > front {
        let x = queue[front]
        front += 1
        
        if x == two {
            return visited[x]
        }
        
        for next in graph[x] {
            guard visited[next] == -1 else { continue }
            visited[next] = visited[x] + 1
            queue.append(next)
        }
    }
    return -1
}

print(BFS())
