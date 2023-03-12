import Foundation

/*
 4x4 보드게임
 한번 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동
 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다. 한번의 이동에서 이미 합쳐진 블록은 또다른 블록과 함쳐질 수 없다
 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램. 0은 빈칸
 */

//input
let n = Int(readLine()!)!
var block = [[Int]]()
var answer = 0
for _ in 0..<n {
    block.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

//상:0, 하:1, 좌:2, 우:3
func movingBlock(_ d: Int, _ block: inout [[Int]]) {
    var queue = [Int]()

    if d == 0 { //상
        //같은 열(i)
        for i in 0..<n {
            //이동 행(j)
            for j in 0..<n {
                if block[j][i] != 0 {
                    queue.append(block[j][i]) //0이 아닌 애들만 queue에 넣어준다.
                }
                block[j][i] = 0 //일단 0으로 변경
            }
            var indx = 0

            while !queue.isEmpty {
                let data = queue.first!
                queue.removeFirst()

                if block[indx][i] == 0 { //빈칸인 경우 데이터 넣기
                    block[indx][i] = data
                }else if block[indx][i] == data { //데이터가 같으면 *2 하기!
                    block[indx][i] *= 2
                    indx += 1 //다음 행으로 이동
                }else { //빈칸도 아니고, 같은 데이터도 아니라면 데이터 넣기
                    indx += 1 //다음 행으로 이동
                    block[indx][i] = data
                }
            }
        }
    }else if d == 1 { //하
        for i in 0..<n {
            for j in (0..<n).reversed() {
                if block[j][i] != 0 {
                    queue.append(block[j][i])
                }
                block[j][i] = 0
            }
            var indx = n-1

            while !queue.isEmpty {
                let data = queue.first!
                queue.removeFirst()

                if block[indx][i] == 0 {
                    block[indx][i] = data
                }else if block[indx][i] == data {
                    block[indx][i] *= 2
                    indx -= 1
                }else {
                    indx -= 1
                    block[indx][i] = data
                }
            }
        }
    }else if d == 2 { //좌
        for i in 0..<n {
            for j in 0..<n {
                if block[i][j] != 0 {
                    queue.append(block[i][j])
                }
                block[i][j] = 0
            }
            var indx = 0

            while !queue.isEmpty {
                let data = queue.first!
                queue.removeFirst()
                
                if block[i][indx] == 0 {
                    block[i][indx] = data
                }else if block[i][indx] == data {
                    block[i][indx] *= 2
                    indx += 1
                }else {
                    indx += 1
                    block[i][indx] = data
                }
            }
        }
    }else { //우
        for i in 0..<n {
            for j in (0..<n).reversed() {
                if block[i][j] != 0 {
                    queue.append(block[i][j])
                }
                block[i][j] = 0
            }
            var indx = n-1

            while !queue.isEmpty {
                let data = queue.first!
                queue.removeFirst()

                if block[i][indx] == 0 {
                    block[i][indx] = data
                }else if block[i][indx] == data {
                    block[i][indx] *= 2
                    indx -= 1
                }else {
                    indx -= 1
                    block[i][indx] = data
                }
            }
        }
    }
}

func DFS(_ now: Int, _ block: inout [[Int]]) {
    if now == 5 { //최대 5회 이동
        for i in 0..<n {
            for j in 0..<n {
                answer = max(answer, block[i][j])
            }
        }
        return
    }
    let tmpStorage = block
    for i in 0...3 {
        movingBlock(i, &block)
        DFS(now + 1, &block)
        block = tmpStorage //원래대로 복구 -> 다른 케이스 적용하기 위해
    }
}

DFS(0, &block)
print(answer)
