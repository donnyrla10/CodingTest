import Foundation

/*
 8개의 톱니를 가지고 있는 톱니바퀴 4개
 총 K번 회전. 시계방향 / 반시계방향으로 회전
 맞닿은 톱니의 극이 다르면 회전방향과 반대방향으로 회전
 서로 극이 같으면 회전 x
 최종 톱니바퀴 상태
 */

//input
var wheel = [[Int]]()
for _ in 0..<4 { wheel.append(readLine()!.map{Int(String($0))!}) }
let k = Int(readLine()!)!

func rotationWheel(_ w: Int, _ d: Int) {
    var dir = [Int](repeating: 0, count: 4)
    dir[w] = d //톱니바퀴 w의 회전 방향
    var index = w
    //left
    while index > 0 && wheel[index][6] != wheel[index-1][2] {
        dir[index-1] = -dir[index] //반대 방향
        index -= 1
    }
    
    //right
    index = w
    while index < 3 && wheel[index][2] != wheel[index+1][6] {
        dir[index+1] = -dir[index]
        index += 1
    }
    
    for i in 0..<4 {
        if dir[i] == 1 { //시계방향
            let last = wheel[i][7]
            for j in (0...6).reversed() {
                wheel[i][j+1] = wheel[i][j]
            }
            wheel[i][0] = last
        }else if dir[i] == -1 {
            let first = wheel[i][0]
            for j in 1...7 {
                wheel[i][j-1] = wheel[i][j]
            }
            wheel[i][7] = first
        }
    }
}

func solution() {
    for _ in 0..<k {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let (w, d) = (input[0], input[1])
        rotationWheel(w-1, d)
    }
    var answer = 0
    for i in 0..<4 {
        answer += wheel[i][0] == 1 ? (1 << i) : 0
    }
    print(answer)
}
solution()
