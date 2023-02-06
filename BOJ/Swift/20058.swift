import Foundation

//input
let nq = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = Int(pow(2.0, Double(nq[0])))
var array = [[Int]]()
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
for _ in 0..<n {
    array.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}
var question = readLine()!.split(separator: " ").map{ Int(String($0))! }

func rotation(_ l: Int, _ x: Int, _ y: Int, _ array: inout[[Int]]) {
    var tmpArr = [[Int]](repeating: [Int](repeating: 0, count: l), count: l)
    var ii = 0, jj = 0
    for i in x..<x+l {
        jj = 0
        for j in y..<y+l {
            tmpArr[ii][jj] = array[i][j]
            jj += 1
        }
        ii += 1
    }
    
    var tmp = tmpArr
    for i in 0..<tmpArr.count {
        for j in 0..<tmpArr.count {
            tmp[i][j] = tmpArr[tmpArr.count-1-j][i]
        }
    }
    
    ii = 0
    jj = 0
    for i in x..<x+l {
        jj = 0
        for j in y..<y+l {
            array[i][j] = tmp[ii][jj]
            jj += 1
        }
        ii += 1
    }
}

func fireStorm(_ q: Int){
    //1. 2^L X 2^L 크기의 부분 격자로 나누기
    let l = Int(pow(2.0, Double(q)))
    for i in stride(from: 0, to: n, by: l) {
        for j in stride(from: 0, to: n, by: l) {
            //i, j를 기준으로 2^L 크기를 시계방향으로 90도 회전하기
            //2. 모든 부분 격자를 시계 방향으로 90도 회전
            rotation(l, i, j, &array) //i, j는 부분 격자의 좌측상단 좌표값
        }
    }
    
    //3. 격자를 순회하면서 인접칸 중 얼음이 있는 칸이 3개 미만이면 얼음양 -1
    let tmp = array
    for i in 0..<n {
        for j in 0..<n {
            guard tmp[i][j] != 0 else { continue } //0이면 pass
            var cnt = 0
            for k in 0..<4 {
                let dx = i + direction[k][0]
                let dy = j + direction[k][1]
                guard (0..<n) ~= dx, (0..<n) ~= dy else { continue }
                if tmp[dx][dy] != 0 {
                    cnt += 1
                }
            }
            if cnt < 3 {
                array[i][j] -= 1
            }
        }
    }
}

//1. 파이어볼 시전
question.forEach { q in
    fireStorm(q)
}

//2. 모두 끝난 뒤
//2-1. 남은 얼음의 합
var sum = 0
for i in 0..<n {
    for j in 0..<n {
        sum += array[i][j]
    }
}
print(sum)

var answer = 0 //max(덩어리의 칸 개수)
var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: n)

func BFS(_ i: Int, _ j: Int){
    var count = 0         //(i,j)와 연결된 얼음의 개수
    var queue = [(i, j)]
    var front = 0

    while queue.count > front {
        let (x, y) = queue[front]
        front += 1

        for d in 0..<4 {
            let dx = x + direction[d][0]
            let dy = y + direction[d][1]
            guard (0..<n) ~= dx, (0..<n) ~= dy else { continue }
            if !visited[dx][dy] && array[dx][dy] != 0 { //얼음이 있고, 방문한 곳이 아니라면
                count += 1
                visited[dx][dy] = true
                queue.append((dx, dy))
            }
        }
    }
    answer = max(answer, count)
}

//2-2. 남은 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수 구하기 -> BFS
for i in 0..<n {
    for j in 0..<n {
        if !visited[i][j] && array[i][j] != 0 {
            BFS(i, j)
        }
    }
}
print(answer)
