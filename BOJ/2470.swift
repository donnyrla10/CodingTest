import Foundation

/*
 산성 용액의 특성값: 1...1000000000
 알칼리성 용액의 특성값: -1...-1000000000
 같은 양의 두 용액을 혼합한 용액의 특성값 -> 혼합에 사용된 각 용액의 특성값의 합
 서로 다른 용액을 혼합해 특성값이 "0"에 가장 가까운 용액을 만들어내는 두 용액을 찾아라.
 */

let n = Int(readLine()!)!
var array = readLine()!.split(separator: " ").map{ Int(String($0))! }.sorted()
var sum = 2000000001
var left = 0
var right = n-1
var ans1 = 0
var ans2 = 0

while left < right {
    if sum > abs(array[left] + array[right]) {
        sum = abs(array[left] + array[right])
        ans1 = left
        ans2 = right
    }
    if array[left] + array[right] > 0 {
        right -= 1
    }else {
        left += 1
    }
}
print("\(array[ans1]) \(array[ans2])")
