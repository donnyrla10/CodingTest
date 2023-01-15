import Foundation

func solution(_ n:Int) -> Int {
    var ans = 1
    var n = n
    while n != 1 {
        ans += n % 2
        n /= 2
    }
    return ans
}

print(solution(1))
print(solution(5))
print(solution(6))
print(solution(5000))
