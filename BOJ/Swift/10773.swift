import Foundation

/*
 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지운다.
 모든 수를 받아 적은 후 그 수의 합을 알고싶다.
 */

let K = Int(readLine()!)!
var stack : [Int] = []
var answer = 0
for _ in 0..<K {
    let n = Int(readLine()!)!
    if n == 0 {
        answer -= stack.removeLast()
    }
    else {
        stack.append(n)
        answer += n
    }
}
print(answer)
