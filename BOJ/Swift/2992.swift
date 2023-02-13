import Foundation

/*
 정수 X와 구성이 같으면서 X보다 큰 수 중 가장 작은 수 출력하기
 수의 구성이 같다 == 수를 이루고 있는 각 자릿수가 같다는 뜻
 -> 123 == 321, 123 != 432
 */

//input
let x = Int(readLine()!)!
let arr = String(x).map{ Int(String($0))! }
var answer = Int.max
var visited = [Bool](repeating: false, count: arr.count + 1)
var num = [Int]()

func bt(_ cnt: Int) {
    if num.count == arr.count {
        let n = Int(num.map{String($0)}.joined())!
        if n > x { answer = min(answer, n) }
        return
    }

    var flag = false
    for i in 0..<arr.count {
        if !visited[i] {
            visited[i] = true
            num.append(arr[i])
            if num.count < arr.count {
                for i in 0..<num.count {
                    if num[i] > arr[i] {
                        break
                    }else if num[i] < arr[i] {
                        flag = true
                        break
                    }
                }
            }
            if !flag { bt(cnt + 1) }
            num.removeLast()
            visited[i] = false
            flag = false
        }
    }
}
bt(0)
print(answer == Int.max ? 0 : answer)
