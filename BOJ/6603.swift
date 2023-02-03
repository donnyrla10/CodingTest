import Foundation

/*
 {1,2,...,49}에서 수 6개를 고른다
 49가지 중 k개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
 집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법은?
 */

//input
while true {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let k = input[0]
    if input.count == 1 && k == 0 { break }
    input.removeFirst()
    var result = [Int]()
    var visit = [Bool](repeating: false, count: 50)
    
    func DFS(_ cnt: Int, _ start: Int) {
        if cnt == 6 { //로또 번호 6개 모두 모았음
            result.forEach {
                print($0, terminator: " ")
            }
            print("")
            return
        }
        for i in start..<k {
            if !visit[i] {
                visit[i] = true
                result.append(input[i])
                DFS(cnt + 1, i+1)
                result.removeLast()
                visit[i] = false
            }
        }
    }
    DFS(0, 0)
    print("")
}
