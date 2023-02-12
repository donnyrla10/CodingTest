import Foundation

/*
 부등호 고정
 선택되는 숫자가 다르다
 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다.
 각 부등호의 앞뒤에 들어가는 숫자는 0~9 중 하나. 선택된 숫자는 모두 다르게
 */

//input
let n = Int(readLine()!)!
let inequality = readLine()!.split(separator: " ")
var visit = [Bool](repeating: false, count: 11)
var maxv = Int.min
var minv = Int.max

//DFS를 이용한 백트래킹 -> 매 노드마다 조건을 확인해서 바로 가지치기! -> 불필요한 연산 & 노드 체크 안할 수 있음
func BT(_ k: Int, _ num: [Int]) {
    if k >= 2 { //2개 이상이 되어야 비교할 수 있으므로
        if inequality[k - 2] == "<" && num[k-2] > num[k-1] { return }
        else if inequality[k - 2] == ">" && num[k-2] < num[k-1] { return }
    }
    
    if k == n + 1 {
        let number = num.reduce(into: 0) { $0 = $0 * 10 + $1 }
        maxv = max(maxv, number)
        minv = min(minv, number)
        return
    }
    
    for i in 0...9 {
        if !visit[i] {
            visit[i] = true
            BT(k+1, num + [i])
            visit[i] = false
        }
    }
}

func insertZero(_ str: Int) -> String {
    var str = String(str)
    while str.count < n + 1 {
        str.insert("0", at: str.startIndex)
    }
    return str
}

BT(0, [])
print("\(insertZero(maxv))\n\(insertZero(minv))")
