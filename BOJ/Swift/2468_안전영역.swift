import Foundation

let n = Int(readLine()!)!
var array = [[Int]]()
var maxH = 0
for _ in 0..<n {
    let tmp = readLine()!.split(separator: " ").map{ Int(String($0))! }
    maxH = max(tmp.max()!, maxH)
    array.append(tmp)
}

func flood(tmp: inout [[Int]], height: Int) {
    for i in 0..<n {
        for j in 0..<n {
            if tmp[i][j] <= height {
                tmp[i][j] = 0 //잠김
            }
        }
    }
}

var tmp = array
var count = 0
var answer = 0
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: n)

func BFS(height: Int, i: Int, j: Int) {
    var queue = [(i, j)]
    var front = 0
    
    while queue.count > front {
        let (x,y) = queue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            
            guard (0..<n) ~= dx, (0..<n) ~= dy else { continue } //범위 넘긴 경우
            guard !visited[dx][dy], tmp[dx][dy] != 0 else { continue }
            visited[dx][dy] = true
            queue.append((dx, dy))
        }
    }
}

for h in 0..<maxH { //height마다 안전 영역 개수 세기
    flood(tmp: &tmp, height: h)
    count = 0
    visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: n)
    
    for i in 0..<n {
        for j in 0..<n {
            if tmp[i][j] != 0 && !visited[i][j] {
                count += 1
                BFS(height: h, i: i, j: j)
            }
        }
    }
    
    answer = max(answer, count)
}

print(answer)
