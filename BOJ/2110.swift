import Foundation

let nc = readLine()!.split(separator: " ").map{ Int(String($0))! }
var array = [Int]()
for _ in 0..<nc[0] {
    array.append(Int(readLine()!)!)
}
array = array.sorted() //정렬

var l = 0
var r = 1000000000

func cal(D: Int) -> Bool {
    var count = 1       //맨 첫번째 집에 공유기 설치
    var last = array[0] //마지막으로 공유기 설치한 집
    for i in 0..<nc[0] {
        if array[i] - last < D { //최소 d만큼의 거리가 되지 않으므로 공유기 설치 불가 패스
            continue
        }
        last = array[i]
        count += 1
    }
    return count >= nc[1]
}

var answer = 0
while l <= r {
    let mid = (l + r) / 2
    if cal(D: mid) {
        answer = mid
        l = mid + 1
    }else {
        r = mid - 1
    }
}
print(answer)
