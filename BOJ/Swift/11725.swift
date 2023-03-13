import Foundation

//input
let n = Int(readLine()!)!
var trees = [[Int]](repeating: [], count: n+1)
var answer = [Int](repeating: 0, count: n+1)
var visited = [Bool](repeating: false, count: n+1)
for _ in 0..<n-1 {
    let nodes = readLine()!.split(separator: " ").map{Int(String($0))!}
    trees[nodes[0]].append(nodes[1])
    trees[nodes[1]].append(nodes[0])
}

func dfs(_ now: Int) {
    visited[now] = true
    
    for tree in trees[now] {
        if visited[tree] { continue }
        answer[tree] = now
        dfs(tree)
    }
}

dfs(1)
for i in 2...n {
    print(answer[i])
}
