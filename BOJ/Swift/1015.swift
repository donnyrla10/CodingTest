import Foundation

let n = Int(readLine()!)!
let array = readLine()!.split(separator: " ").map{ Int(String($0))! }
var answer = [(Int,Int)](repeating: (0, 0), count: n)
for i in 0..<n {
    answer[i] = (i, array[i])
}
answer = answer.sorted{ $0.1 < $1.1 }
for i in 0..<n {
    answer[i].1 = i
}
answer.sorted{ $0.0 < $1.0 }.forEach {
    print($0.1, terminator: " ")
}
