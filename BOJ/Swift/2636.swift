import Foundation

/*
 회색 == 치즈. 가장자리에는 치즈가 없고, 치즈에는 하나 이상의 구멍있을 수 있다
 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어짐.
 치즈 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어가게 된다.
 구멍은 처음엔 공기가 없다가, 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어간다.
 공기 중에서 치즈가 모두 녹아 없어지는데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈 조작이 놓여있는 칸의 개수 출력
 1: 치즈, 0: 빈칸
 */

//input
let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n, m) = (nm[0], nm[1])
var arr = [[Int]]()
for _ in 0..<n {
    arr.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}
var hour = 0 //모두 녹아 없어지는데 걸리는 시간
var counting = 0 //치즈칸 개수
var visited = [[Bool]](repeating: [Bool](repeating: false, count: 102), count: 102)
let dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

func BFS() {
    var queue = [(0, 0)]
    var front = 0
    visited[0][0] = true
    counting = 0
    while queue.count > front {
        let (x, y) = (queue[front].0, queue[front].1)
        front += 1
        
        for d in 0..<4 {
            let dx = x + dir[d][0]
            let dy = y + dir[d][1]
            guard (0..<n) ~= dx, (0..<m) ~= dy else { continue }
            guard !visited[dx][dy] else { continue }
            if arr[dx][dy] == 1 { //치즈를 만난 경우
                arr[dx][dy] = 0   //녹은 치즈로 바꾸기
                counting += 1
            }else if arr[dx][dy] == 0 { //공기를 만난 경우
                queue.append((dx, dy))
            }
            visited[dx][dy] = true
        }
    }
    print(counting)
}

//원래 치즈 칸의 개수 카운팅 -> 1시간만에 바로 치즈가 다 녹을 경우, 원래 치즈 칸 개수 출력
for i in 0..<n {
    for j in 0..<m {
        if arr[i][j] == 1 {
            counting += 1
        }
    }
}
while true { //치즈가 모두 녹을 때까지 반복
    let cheese = counting //이전 치즈 칸 개수
    BFS()
    if counting == 0 { //치즈가 모두 녹은 경우
        print("\(hour)\n\(cheese)") //걸린 시간 & 이전 치즈 칸 개수
        break
    }
    hour += 1
    visited = [[Bool]](repeating: [Bool](repeating: false, count: 102), count: 102)
}

//전체 칸을 돌지 않게 하려고 했는데 오히려 꼬여서 NM범위도 작으니 그냥 0,0에서 출발하도록 구현
//처음엔 1을 모두 세야하는 줄 알았는데, 결국 모두 녹기 전에 치즈는 선분으로만 이루어지기 때문에 겉만 카운팅 해도 된다! wow
