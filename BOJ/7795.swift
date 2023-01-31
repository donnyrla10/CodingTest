import Foundation

/*
 A는 자기보다 크기가 작은 B를 먹는다.
 A의 크기가 B보다 큰 쌍은 몇 개?
 */

let t = Int(readLine()!)!
var results = [Int]()
for _ in 0..<t {
    let _ = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let a = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let b = readLine()!.split(separator: " ").map{ Int(String($0))! }.sorted()
    var answer = 0

    a.forEach { element in
        if element > b.last! {
            answer += b.count
        }else if element <= b.first! {
            answer += 0
        }else {
            let bigger = b.firstIndex{ element <= $0 }!
            answer += bigger
        }
    }
    results.append(answer)
}
results.forEach{
    print($0)
}
