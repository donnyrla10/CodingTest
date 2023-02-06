import Foundation

/*
 F층 빌딩. 갈 곳 G층. 지금있는 층 S층
 U버튼: 위로 U층, D버튼: 아래로 D층
 G층에 가려면 버튼을 적어도 몇 번 눌러야?
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let f = input[0]
let s = input[1]
let g = input[2]
let u = input[3]
let d = input[4]
var visited = [Int](repeating: -1, count: f+1)

func BFS() {
    var queue = [s]
    var front = 0
    visited[s] = 0
    
    while queue.count > front {
        let x = queue[front]
        front += 1
        
        if g == x {
            print(visited[x])
            return
        }
        
        let dir = [u, -d]
        for i in 0..<2 {
            let nx = x + dir[i]
            
            guard (1...f) ~= nx else { continue }
            guard visited[nx] == -1 else { continue }
            visited[nx] = visited[x] + 1
            queue.append(nx)
        }
    }
    print("use the stairs")
}

BFS()
