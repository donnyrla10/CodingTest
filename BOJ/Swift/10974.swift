import Foundation

/*
 N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램
 */

//input
let n = Int(readLine()!)!
var check = [Bool](repeating: false, count: n+1)
var result = [Int]()

func DFS(_ k: Int) {
    if k == n {
        result.forEach {
            print($0, terminator: " ")
        }
        print("")
        return
    }
    
    for i in 1...n {
        if !check[i] {
            check[i] = true
            result.append(i)
            DFS(k+1)
            result.removeLast()
            check[i] = false
        }
    }
}

DFS(0)
