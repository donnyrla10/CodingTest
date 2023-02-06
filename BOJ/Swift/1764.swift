import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = input[0]
let m = input[1]
var dontListen = [String]()
var answer = [String]()

for _ in 0..<n {
    dontListen.append(readLine()!)
}
dontListen = dontListen.sorted()

for _ in 0..<m {
    let dontSee = readLine()!
    var left = 0
    var right = n-1
    while left <= right {
        let mid = (left + right) / 2
        if dontListen[mid] == dontSee {
            answer.append(dontSee)
            break
        }else if dontListen[mid] < dontSee {
            left = mid + 1
        }else {
            right = mid - 1
        }
    }
}
print(answer.count)
answer.sorted().forEach {
    print($0)
}
