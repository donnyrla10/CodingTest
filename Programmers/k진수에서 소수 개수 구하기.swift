import Foundation

func isPrime(num: Int) -> Bool {
    if num < 4 { return num == 1 ? false: true }
    for i in 2...Int(sqrt(Double(num))) {
        if num % i == 0 { return false }
    }
    return true
}

func solution(_ n:Int, _ k:Int) -> Int {
    var answer = 0
    let array = String(n, radix: k).split(separator: "0").map{ String($0) }
    for i in 0..<array.count {
        if isPrime(num: Int(array[i])!) {
            answer += 1
        }
    }
    return answer
}

print(solution(1, 3))
