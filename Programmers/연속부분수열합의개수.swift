import Foundation

/*
 원형 수열의 연속하는 부분 수열의 합으로 만들 수 있는 수가 모두 몇 가지인지 알아보자
 길이가 1~n(elements.count)인 연속 부분 수열 구하기
 */

func solution(_ elements:[Int]) -> Int {
    var set = Set<Int>()
    elements.forEach{ set.insert($0) }
    set.insert(elements.reduce(0, +))
    for i in 2..<elements.count {
        for start in 0..<elements.count {
            var sum = elements[start]
            for next in start..<start+i-1 {
                sum += elements[(next + 1) % elements.count]
            }
            set.insert(sum)
        }
    }
    return set.count
}

print(solution([7,9,1,1,4]))
