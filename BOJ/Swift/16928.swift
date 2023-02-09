import Foundation

/*
 주사위를 조작해 내가 원하는 수가 나오게 만들 수 있다면, 최소 몇 번만에 도착점에 도착할 수 있을까?
 주사위의 각 면에는 1~6까지의 수가 적혀있다.
 10x10 보드판. 1부터 100까지 수가 하나씩 순서대로 적혀있다.
 플레이어는 주사위를 굴려 나온 수만큼 이동해야 한다. 플레이어가 i번 칸에 있고, 주사위를 굴려 나온 수가 4면 i+4 칸으로 이동
 도착한 칸이 사다리면, 사다리를 타고 위로 올라간다. 뱀이 있는 칸이면 뱀을 따라거 내려간다.
 즉, 사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 크고, 뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 작아짐.
 게임의 목표는 1번에서 시작해 100번 칸에 도착.
 100번 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값 구하기
 */

//input
let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n, m) = (nm[0], nm[1])
var ladderNsnake = [Int](repeating: 0, count: 102) //겹치지 않기 때문에 ㄱㅊ
var check = [Bool](repeating: false, count: 102)
for _ in 0..<n+m {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    ladderNsnake[input[0]] = input[1]
}

//1에서 시작해서 100에 도달해야됨
func BFS() {
    var queue = [(1, 0)] //현재 위치, 카운트(주사위 굴린 횟수)
    var front = 0
    
    while queue.count > front {
        let (x, cnt) = (queue[front].0, queue[front].1)
        front += 1
        
        //주사위 굴린 경우
        for i in 1...6 {
            var next = x + i
            if next == 100 { //도착했기 때문에 끝내기!
                print(cnt + 1)
                return
            } else if next < 100 {
                                //사다리 혹은 뱀을 위치 1에서는 체크하지 않은 것은, 1과 100에선 뱀과 사다리가 없기 때문
                                if ladderNsnake[next] != 0 {  //이동한 곳에 사다리 혹은 뱀이 있다면 이동! (무조건 이동)
                    next = ladderNsnake[next] //사다리로 이동하면 카운팅 없음, 위치만 변경
                }
                if !check[next] {             //방문한 곳이 아니라면 방문! (재방문 없음)
                    queue.append((next, cnt + 1))
                    check[next] = true
                }
            }
        }
    }
}
BFS()
