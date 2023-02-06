import Foundation

func solution(_ a:Int, _ b:Int, _ n:Int) -> Int {
    var answer = 0
    var m = n
    repeat {
        answer += (m / a) * b
        m = m - (m / a * a) + (m / a) * b
    } while m >= a
    return answer
}
