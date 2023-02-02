import Foundation

//input
let ns = readLine()!.split(separator: " ").map{ Int(String($0))! }
var array = readLine()!.split(separator: " ").map{ Int(String($0))! }
array.insert(0, at: array.startIndex)

private func search() {
    var r = 0
    var sum = 0
    var answer = ns[0]+1

    for l in 1...ns[0] {
        sum -= array[l-1] //L-1 원소 값을 구간 합에서 제거
        while r+1 <= ns[0] && sum < ns[1] {
            r += 1
            sum += array[r]
        }
        if sum >= ns[1] {
            answer = min(answer, r-l+1)
        }
    }
    print(answer == ns[0] + 1 ? 0 : answer)
}

search()
