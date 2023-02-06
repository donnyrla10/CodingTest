import Foundation

//input
let n = Int(readLine()!)!
var array = readLine()!.split(separator: " ").map{ Int(String($0))! }.sorted()
var answer = 0

for i in 0..<n {
    var r = n-1
    var l = 0
    let target = array[i]
    
    while l < r { //두 개의 합을 구해야 하므로
        //자기 자신은 덧셈에 포함 안됨
        if l == i { l += 1 }
        else if r == i { r -= 1 }
        else {
            if array[l] + array[r] == target {
                answer += 1
                break
            }else if array[l] + array[r] > target {
                r -= 1
            }else {
                l += 1
            }
        }
    }
}
print(answer)
