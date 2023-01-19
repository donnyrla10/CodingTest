import Foundation

let n = Int(readLine()!)!
var array = [(0,0)] //기간, 금액
var answer = 0

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    array.append((input[0], input[1]))
}

func DFS(_ x: Int, _ sum: Int){
    if x == n || x + array[x].0 > n {
        answer = max(answer, sum)
        return
    }
    
    for i in array[x].0 + x...n { //다음 출근 날(인덱스)
        if i + array[i].0 - 1 > n {
            continue
        }
        DFS(i, sum + array[i].1)
    }
    
    answer = max(answer, sum)
    return
}

for d in 1...n { //시작하는 날짜
    if d + array[d].0 - 1 > n { continue }
    DFS(d, array[d].1)
}

print(answer)
