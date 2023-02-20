import Foundation

//input
let ab = readLine()!.split(separator: " ").map{ String($0) }
let a = ab[0].map{ String($0) }.sorted(by: >)
let b = Int(ab[1])!
var visited = [Bool](repeating: false, count: a.count+1)

func bt(_ now: Int, _ tmp: String) {
    if now == a.count {
        if Int(tmp)! < b {
            print(tmp)
            exit(0) //바로 끝내버리기 (더이상 재귀호출하지 않고 바로 끝내기 -> 프로그램 종료)
        }
        return
    }
    
    for i in 0..<a.count {
        if now == 0 && a[i] == "0" { continue } //0으로 시작하면 패스
        if !visited[i] {
            visited[i] = true
            bt(now+1, tmp + a[i])
            visited[i] = false
        }
    }
}

bt(0, "")
print(-1)

//input
//let ab = readLine()!.split(separator: " ").map{ String($0) }
//let (a, b) = (ab[0].map{ Int(String($0))! }, Int(ab[1])!)
//var visited = [Bool](repeating: false, count: a.count+1)
//var result = -1
//
//func bt(_ now: Int, _ num: [Int]) {
//    if now == a.count && num[0] != 0 { //새로운 순열 완성
//        let n = Int(num.map({ String($0) }).joined())!
//        if b > n {
//            result = max(result, n) //가장 큰 값
//        }
//        return
//    }
//
//    for i in 0..<a.count {
//        if !visited[i] {
//            visited[i] = true
//            bt(now+1, num + [a[i]])
//            visited[i] = false
//        }
//    }
//}
//
//func solution(){
//    bt(0, [])
//    print(result)
//}
//
//solution()


