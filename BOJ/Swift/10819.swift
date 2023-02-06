import Foundation

/*
 N개의 정수로 이루어진 배열 A
 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하라
 |A[0]-A[1]| + |A[1]-A[2]| + ... + |A[n-2] - A[n-1]|
 */

//input
let n = Int(readLine()!)!
var array = readLine()!.split(separator: " ").map{ Int(String($0))! }
var tmp = [Int]()
var answer = 0
var visit = [Bool](repeating: false, count: 9)

func calculator(_ index: Int, _ value: Int) -> Int {
    return index == 0 ? 0 : value + abs(tmp[index-1] - tmp[index])
}

func DFS(_ k: Int, _ sum: Int) {
    if k == n {
        answer = max(answer, sum)
        return
    }
    
    for i in 0..<n {
        if !visit[i] {
            visit[i] = true
            tmp.append(array[i])
            DFS(k+1, calculator(k, sum))
            tmp.removeLast()
            visit[i] = false
        }
    }
}

DFS(0, 0)
print(answer)
