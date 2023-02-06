import Foundation

//input
let n = Int(readLine()!)!
var array = readLine()!.map{ String($0) }
var sort = 0
var count = [Int](repeating: 0, count: 26)

func add(x: String) {
    let index = Int(UnicodeScalar(x)!.value) - Int(UnicodeScalar("a").value)
    count[index] += 1
    if count[index] == 1 {
        sort += 1
    }
}

func erase(x: String) {
    let index = Int(UnicodeScalar(x)!.value) - Int(UnicodeScalar("a").value)
    count[index] -= 1
    if count[index] == 0 {
        sort -= 1
    }
}

func solution(){
    var answer = 0
    var l = 0
    for r in 0..<array.count {
        add(x: array[r])
        while sort > n { //알파벳 종류 n개를 넘은 경우
            erase(x: array[l])
            l += 1
        }
        answer = max(answer, r-l+1)
    }
    print(answer)
}
solution()
