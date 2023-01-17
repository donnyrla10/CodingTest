import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = input[0]
let k = input[1]
var queue = Array(1...n)

print("<", terminator: "")
while !queue.isEmpty {
    for _ in 0..<k-1 {
        queue.append(queue.removeFirst())
    }
    print(queue.first!, terminator: "")
    queue.removeFirst()
    
    if !queue.isEmpty {
        print(",", terminator: " ")
    }
}
print(">")
