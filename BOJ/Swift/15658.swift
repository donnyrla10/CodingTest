import Foundation

//input
let n = Int(readLine()!)!
var num = readLine()!.split(separator: " ").map{ Int(String($0))! }
var op = readLine()!.split(separator: " ").map{ Int(String($0))! }
var maxV = -Int.max
var minV = Int.max

func calculator(_ a: Int, _ b: Int, _ op: Int) -> Int {
    switch op {
    case 0: return a + b
    case 1: return a - b
    case 2: return a * b
    case 3: return a / b
    default: return 0
    }
}

func search(_ depth: Int, _ result: Int) { //원하는 개수의 수를 모두 선택한 경우
    if depth == n {
        maxV = max(maxV, result)
        minV = min(minV, result)
        return
    }
    
    for i in 0..<4 {
        if op[i] != 0 {
            op[i] -= 1
            search(depth + 1, calculator(result, num[depth], i))
            op[i] += 1
        }
    }
}

search(1, num[0])
print("\(maxV)\n\(minV)")
