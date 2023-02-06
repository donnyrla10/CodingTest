import Foundation

//input
let nk = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n, k) = (nk[0], nk[1])
var check = [Bool](repeating: false, count: 9)
var arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var answer = 0

func bt(_ cnt: Int, _ weight: Int) {
    if cnt == n {
        answer += 1
        return
    }
    for i in 0..<n {
        if !check[i] {
            if weight - k + arr[i] < 500 { continue }
            check[i] = true
            bt(cnt+1, weight - k + arr[i])
            check[i] = false
        }
    }
}
bt(0, 500)
print(answer)
