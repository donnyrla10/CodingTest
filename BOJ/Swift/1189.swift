import Foundation

/*
 왼쪽 아래점에 있고, 집은 오른쪽 위
 한번 지나친 곳은 다시 방문하지 않음
 T로 표시된 부분은 가지 못하는 곳.
 한수가 집까지 도착하는 경우 중 거리가 K인 가짓수 구하기
 */

//24ms

////input
//let rck = readLine()!.split(separator: " ").map{ Int(String($0))! }
//let (r, c, k) = (rck[0], rck[1], rck[2])
//var arr = [[Character]]()
//var (x, y) = (r-1, 0) //destination = (0, c-1)
//var answer = 0
//var visited = [[Bool]](repeating: [Bool](repeating: false, count: r+1), count: c+1)
//for _ in 0..<r {
//    arr.append(readLine()!.map{ Character(String($0)) })
//}
//
//let dir = [[1,0], [-1,0], [0,1], [0,-1]]
//
////DFS를 사용한 BT(조건이 추가되고, 조건에 해당하지 않으면 바로 패스해서 이전으로 돌아가는?)
//func search(_ x: Int, _ y: Int, _ cnt: Int) {
//    if (x, y) == (0, c-1) { //destination에 도착한 경우
//        if k == cnt { answer += 1 }
//        return
//    }
//if cnt > k { return }
//
//    //x, y에서 출발해서 갈 수 있는 곳 -> 4방향
//    for i in 0..<4 {
//        let dx = x + dir[i][0]
//        let dy = y + dir[i][1]
//        guard (0..<r) ~= dx, (0..<c) ~= dy else { continue } //범위 벗어나면 안됨 -> 패스
//        if !visited[dx][dy] && arr[dx][dy] != "T" { //방문한 곳이 아니라면
//            visited[dx][dy] = true
//            search(dx, dy, cnt + 1)
//            visited[dx][dy] = false
//        }
//    }
//}
//
//visited[r-1][0] = true
//search(r-1, 0, 1)
//print(answer)


import Foundation

/*
 왼쪽 아래점에 있고, 집은 오른쪽 위
 한번 지나친 곳은 다시 방문하지 않음
 T로 표시된 부분은 가지 못하는 곳.
 한수가 집까지 도착하는 경우 중 거리가 K인 가짓수 구하기
 */

//24ms

//input
let rck = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (r, c, k) = (rck[0], rck[1], rck[2])
var arr = [[Character]]()
var (x, y) = (r-1, 0) //destination = (0, c-1)
var answer = 0
var visited = [[Bool]](repeating: [Bool](repeating: false, count: r+1), count: c+1)
for _ in 0..<r {
    arr.append(readLine()!.map{ Character(String($0)) })
}

let dir = [[1,0], [-1,0], [0,1], [0,-1]]
//DFS를 사용한 BT(조건이 추가되고, 조건에 해당하지 않으면 바로 패스해서 이전으로 돌아가는?)
func search(_ x: Int, _ y: Int, _ cnt: Int) {
    if (x, y) == (0, c-1) { //destination에 도착한 경우
        if k == cnt { answer += 1 }
        return
    }
    
    if cnt > k { return } //가지치기

    //x, y에서 출발해서 갈 수 있는 곳 -> 4방향
    for i in 0..<4 {
        let dx = x + dir[i][0]
        let dy = y + dir[i][1]
        guard (0..<r) ~= dx, (0..<c) ~= dy else { continue } //범위 벗어나면 안됨 -> 패스
        if !visited[dx][dy] && arr[dx][dy] != "T" { //방문한 곳이 아니라면
            visited[dx][dy] = true
            search(dx, dy, cnt + 1)
            visited[dx][dy] = false
        }
    }
}

visited[r-1][0] = true
search(r-1, 0, 1)
print(answer)
