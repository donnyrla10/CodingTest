import Foundation

/*
 접두사X 집합이란 집합의 어떤 한 단어가, 다른 단어의 접두어가 되지 않는 집합
 {hello}, {hello, goodbye, giant, hi}, {} 은 모두 접두사 X
 */

//input
let n = Int(readLine()!)!
var words = [String]()
var check = [Bool](repeating: false, count: n+1)
var answer = n

for _ in 0..<n {
    words.append(readLine()!)
}
words.sort()
for i in 0..<words.count {
    for j in i+1..<words.count {
        if words[j].hasPrefix(words[i]) {
            answer -= 1
            break
        }
    }
}
print(answer)
