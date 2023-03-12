import Foundation

//input
let hw = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (h, w) = (hw[0], hw[1])
let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var answer = 0
for i in 1..<w-1 {
    var left = 0
    var right = 0
    for j in 0..<i {
        left = max(left, arr[j])
    }
    for j in i+1..<w {
        right = max(right, arr[j])
    }
    answer += max(0, min(left, right) - arr[i])
}
print(answer)
