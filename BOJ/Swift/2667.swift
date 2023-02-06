import Foundation

let n = Int(readLine()!)!
var array = [[Int]]()
for _ in 0..<n {
    array.append(readLine()!.map{ Int(String($0))! })
}

//방문했으면 0으로 바꾸기
let dir = [[1, 0], [-1, 0], [0, -1], [0, 1]]
var answer = [Int]()
func BFS(i: Int, j: Int) -> Int {
    var count = 1
    var queue = [(i, j)]
    var front = 0
    array[i][j] = 0
    
    while queue.count > front {
        let (x, y) = queue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + dir[i][0]
            let dy = y + dir[i][1]
            
            guard (0..<n) ~= dx, (0..<n) ~= dy else { continue }
            guard array[dx][dy] == 1 else { continue }
            array[dx][dy] = 0
            count += 1
            queue.append((dx, dy))
        }
    }
    return count
}

for i in 0..<n {
    for j in 0..<array[0].count {
        if array[i][j] == 1 {
            answer.append(BFS(i: i, j: j))
        }
    }
}
print(answer.count)
answer.sorted().forEach {
    print($0)
}
