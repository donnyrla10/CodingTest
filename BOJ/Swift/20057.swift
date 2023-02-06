import Foundation

//input
let n = Int(readLine()!)!
var array = [[Int]]()
for _ in 0..<n {
    array.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

//좌표 가운데에서 시작
var curX = n / 2
var curY = n / 2
var answer = 0
var movingNumber = 1 //같은 방향으로 몇 회 이동할지
var direction = 0    //왼쪽 방향부터 시작
let dir = [[0,-1], [1,0], [0,1], [-1,0]]

let masks = [ //좌 하 우 상
    [[0, 0, 2, 0, 0], [0, 10, 7, 1, 0], [5, -1, 0, 0, 0], [0, 10, 7, 1, 0], [0, 0, 2, 0, 0]],
    [[0, 0, 0, 0, 0], [0, 1, 0, 1, 0], [2, 7, 0, 7, 2], [0, 10, -1, 10, 0], [0, 0, 5, 0, 0]],
    [[0, 0, 2, 0, 0], [0, 1, 7, 10, 0], [0, 0, 0, -1, 5], [0, 1, 7, 10, 0], [0, 0, 2, 0, 0]],
    [[0, 0, 5, 0, 0], [0, 10, -1, 10, 0], [2, 7, 0, 7, 2], [0, 1, 0, 1, 0], [0, 0, 0, 0, 0]]
]

//flutteringSandList의 중심(2,2)에 curX, curY를 맞추고 진행
private func flutterSand(_ d: Int, _ array: inout [[Int]]) {
    guard array[curX][curY] != 0 else { return } //모래양이 0이면 할 필요 없음
    let sand = array[curX][curY] //y 위치의 모래 양
    var tmp = sand
    var (x, y) = (0, 0)
    array[curX][curY] = 0        //모래 다 날아감~
    
    //MASK에 맞춰서 진행
    for i in 0..<5 {
        for j in 0..<5 {
            guard masks[d][i][j] != 0 else { continue } //비율 없는 곳 or x, y -> pass
            if masks[d][i][j] == -1 { //알파라면
                (x, y) = (i, j)
                continue
            }
            //1. 해당 위치로 날아간 모래 양 구하기
            let amount = sand * masks[d][i][j] / 100
            tmp -= amount
            //2. 범위 체크 (격자 밖으로 나갔는지 안나갔는지)
            let nx = curX + i - 2
            let ny = curY + j - 2
            if (0..<n) ~= nx, (0..<n) ~= ny { //격자 밖으로 안나감
                array[nx][ny] += amount //흩날려간 모래 양 더하기
            } else { //격자 밖으로 나감
                answer += amount //격자 밖으로 나간 모래 양 더하기
            }
        }
    }
    
    //알파 계산
    let nx = curX + x - 2
    let ny = curY + y - 2
    if (0..<n) ~= nx, (0..<n) ~= ny { //격자 밖으로 안나감
        array[nx][ny] += tmp //흩날려간 모래 양 더하기
    } else { //격자 밖으로 나감
        answer += tmp //격자 밖으로 나간 모래 양 더하기
    }
}

while true {
    for _ in 0..<2 {
        for _ in 0..<movingNumber {
            curX += dir[direction][0]
            curY += dir[direction][1]
            flutterSand(direction, &array)
        }
        //direction 바꾸기
        direction = (direction + 1) % 4
    }
    movingNumber += 1
    if movingNumber == n { //마지막
        for _ in 0..<movingNumber {
            curX += dir[direction][0]
            curY += dir[direction][1]
            if (0..<n) ~= curX, (0..<n) ~= curY {
                flutterSand(direction, &array)
            }
        }
        break
    }
}
print(answer)
