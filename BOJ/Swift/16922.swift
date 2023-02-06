import Foundation

/*
 I, V, X, L (1, 5, 10, 50)
 하나 또는 그 이상의 문자를 이용해서 수를 나타낼 수 있다. 각 문자가 의미하는 수를 모두 합한 값이다.
 XXXV = 10+10+10+5, IXI = 1+10+1
 N개를 사용해서 만들 수 있는 서로 다른 수의 개수를 구하라
 */

let n = Int(readLine()!)!
let num = [1, 5, 10, 50]
var set = Set<Int>()

func bt(_ cnt: Int, _ start: Int, _ sum: Int) {
    if cnt == n {
        set.insert(sum)
        return
    }
    for i in start..<4 {
        bt(cnt+1, i, sum + num[i])
    }
}
bt(0, 0, 0)
print(set.count)
