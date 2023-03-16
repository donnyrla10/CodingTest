import Foundation

//input
let n = Int(readLine()!)!
var arr = [[Bool]](repeating: [Bool](repeating: false, count: 102), count: 102)
let dir = [[1,0], [0,-1], [-1,0], [0,1]]
var answer = 0

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    var (x, y, d, g) = (input[0], input[1], input[2], input[3])
    arr[y][x] = true
    var directions = [d] //0세대
    
    //세대에 따른 방향 구하기 (1~g세대)
    for _ in 1...g {
        let size = directions.count
        for j in (0..<size).reversed() {
            directions.append((directions[j]+1) % 4)
        }
    }
    
    for direction in directions {
        x += dir[direction][0]
        y += dir[direction][1]
        arr[y][x] = true
    }
}
//칸 세기
for i in 0..<100 {
    for j in 0..<100 {
        if arr[i][j], arr[i+1][j], arr[i+1][j+1], arr[i][j+1] {
            answer += 1
        }
    }
}
print(answer)
