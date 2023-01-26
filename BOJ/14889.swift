import Foundation

let n = Int(readLine()!)!
var array = [[Int]]()
var answer = Int.max
var visited = [Bool](repeating: false, count: n+1)
for _ in 0..<n {
    array.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

var list = [Int]()

func bt(_ count: Int, _ now: Int) {
    if count == n/2 {
        var start = 0
        var link = 0
        for i in 0..<n {
            for j in 0..<n {
                if visited[i] && visited[j] { start += array[i][j] }
                else if !visited[i] && !visited[j] {
                    link += array[i][j]
                }
            }
        }
        answer = min(answer, abs(start - link))
        return
    }
    
    for i in now..<n {
        visited[i] = true
        bt(count+1, i+1)
        visited[i] = false
    }
}

bt(0, 0)
print(answer)
