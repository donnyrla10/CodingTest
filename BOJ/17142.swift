import Foundation

//input
let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
var array = [[String]]()
for _ in 0..<nm[0] {
    array.append(readLine()!.split(separator: " ").map{ String($0) })
}

var viruses = [(Int, Int)]()
var choice = [(Int, Int)]()
var answer = Int.max

//1
for i in 0..<nm[0] {
    for j in 0..<nm[0] {
        if array[i][j] == "2" {
            viruses.append((i, j))
        }else if array[i][j] == "1" {
            array[i][j] = "-"
        }
    }
}
var visited = [Bool](repeating: false, count: viruses.count+1)

//3. 바이러스 퍼트리기 -> 가장 오래 걸린 시간 찾아서 answer에 넣기
func spreadVirus() -> Int {
    var temp = array
    let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    var queue = [(Int, Int)]()
    var front = 0
    var maxValue = 0
    //선택한 모든 바이러스 동시에 탐색 시작해야하므로 모두 queue에 넣어준다.
    viruses.forEach { virus in
        if choice.contains(where: { (x, y) in
            return x == virus.0 && y == virus.1
        }) {
            queue.append((virus.0, virus.1))
            temp[virus.0][virus.1] = "V" //활성화된 바이러스들은 "0"으로
        }else {
            temp[virus.0][virus.1] = "*" //얘는 비활성화 바이러스로, 여기는 그냥 냅둔다
        }
    }
    while queue.count > front {
        let(x, y) = queue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            
            guard (0..<nm[0]) ~= dx, (0..<nm[0]) ~= dy else { continue } //범위 벗어난 경우
            //값이 "0" -> 빈 칸/방문안했다는 의미
            if temp[dx][dy] == "0" {
                temp[dx][dy] = String((Int(temp[x][y]) ?? 0) + 1)
                maxValue = max(maxValue, Int(temp[dx][dy])!)
                queue.append((dx, dy))
            }
            if temp[dx][dy] == "*" { //비활성화된 애라면
                temp[dx][dy] = String((Int(temp[x][y]) ?? 0) + 1)
                queue.append((dx, dy))
            }
        }
    }
    if temp.contains(where: { tmp in
        return tmp.contains(where: {$0 == "0"})
    }) {
        maxValue = Int.max
    }
    return maxValue
}

//2. 모든 바이러스 중 M개 바이러스 활성화 (경우의 수 -> BT)
//조합 -> N개 중 M개를 중복없이 고르기
func chooseVirus(_ k: Int, _ s: Int) {
    if k == nm[1] { //m개 모두 골랐음 -> BFS로 바이러스 퍼트리기
        answer = min(answer, spreadVirus())
        return
    }
    
    for i in s..<viruses.count {
        if !visited[i] {
            visited[i] = true
            choice.append(viruses[i])
            chooseVirus(k+1, i+1)
            choice.removeLast()
            visited[i] = false
        }
    }
}

chooseVirus(0, 0)
print(answer == Int.max ? -1 : answer)
