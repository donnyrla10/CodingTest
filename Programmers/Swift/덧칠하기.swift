import Foundation

//section: 칠할 영역
//한번의 페인트칠에 연속된 m개의 구역 칠할 수 있음(m=롤러길이)

func solution(_ n:Int, _ m:Int, _ section:[Int]) -> Int {
    var answer = 0
    var array = [Bool](repeating: true, count: n+1)
    for i in 0..<section.count { array[section[i]] = false }
    for i in 1...n {
        if i > n-m+1 && !array[i] {
            answer += 1
            break
        }else {
            if !array[i] {
                for j in i..<i+m { array[j] = true }
                answer += 1
            }
        }
    }
    return answer
}

print(solution(8, 4, [2,3,6]))
print(solution(5, 4, [1,3]))
print(solution(4, 1, [1,2,3,4]))
