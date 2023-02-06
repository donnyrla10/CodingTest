import Foundation

/*
 같은 모양의 블록이 2x2로 붙어있으면 사라지면서 점수 얻음
 한 블록은 여러 2x2에 포함될 수 있으며, 지워지는 조건에 만족하는 2x2 모양이 여러개면 한번에 지워짐
 지워지면 블록이 아래로 떨어짐
 반복
 지워키는 블록은 모두 몇 개?
 */

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var answer = 0
    var blocks = [[String]]()
    var visited = [[Bool]]()
    var isExploded = false
    board.forEach { blocks.append($0.map{ String($0) }) }
    
    var count = 1
    while true {
        isExploded = false
        //2x2 터트리기
        visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
        for i in 0..<m-1 {
            for j in 0..<n-1 {
                if blocks[i][j] == "." { continue }
                if blocks[i][j] == blocks[i+1][j], blocks[i+1][j] == blocks[i][j+1],
                    blocks[i][j+1] == blocks[i+1][j+1] {
                    isExploded = true
                    if !visited[i][j] {
                        answer += 1
                        visited[i][j] = true
                    }
                    if !visited[i][j+1] {
                        answer += 1
                        visited[i][j+1] = true
                    }
                    if !visited[i+1][j] {
                        answer += 1
                        visited[i+1][j] = true
                    }
                    if !visited[i+1][j+1] {
                        answer += 1
                        visited[i+1][j+1] = true
                    }
                }
            }
        }
        
        if !isExploded { break } //더이상 터지지 않으면 바로 끝
        
        for i in 0..<m {
            for j in 0..<n {
                if visited[i][j] {
                    blocks[i][j] = "."
                }
            }
        }
        
        //밑으로 내리기
        for j in 0..<n { //열마다
            for i in (0..<m-1).reversed() {
                var index = i
                while index < m - 1, blocks[index+1][j] == "." {
                    let tmp = blocks[index+1][j]
                    blocks[index+1][j] = blocks[index][j]  //swap
                    blocks[index][j] = tmp
                    index += 1
                }
            }
        }
        count += 1
    }
    return answer
}

print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))
