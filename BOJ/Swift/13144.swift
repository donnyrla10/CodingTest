import Foundation

//input
let n = Int(readLine()!)!
var array = readLine()!.split(separator: " ").map{ Int(String($0))! }
array.insert(0, at: array.startIndex)

private func search() {
    var r = 0
    var answer = 0
    var check = [Bool](repeating: false, count: 100002)

    for l in 1...n {
        while r+1 <= n && !check[array[r+1]] { //L에서 갈 수 있는 곳까지(원소 중복없이) R을 이동시킨 후
            r += 1
            check[array[r]] = true
        }
        answer += r-l+1 //l과 r 사이의 원소 개수 == 중복없이 연속 수를 뽑을 수 있는 경우의 수
        check[array[l]] = false //l 앞으로 이동시킬 것이므로 앞 원소 제거하기
    }
    
    print(answer)
}
search()
