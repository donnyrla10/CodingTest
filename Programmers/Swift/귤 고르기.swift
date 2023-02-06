import Foundation

/*
 수확한 귤 중 k개를 골라 상자에 담아 판매하려고 한다.
 귤을 크기별로 분류했을 때, 서로 다른 종류의 수를 최소화하고 싶다.
 귤의 종류의 수 최솟값은?
 */

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var answer = 0
    var sum = 0
    var dictionary = [Int:Int]()
    for tan in tangerine {
        dictionary[tan] = (dictionary[tan] ?? 0) + 1
    }
    let sortedDictionary = dictionary.sorted { t1, t2 in
        return t1.value > t2.value
    }
    
    for tangerine in sortedDictionary {
        if tangerine.value + sum >= k {
            answer += 1
            break
        }
        sum += tangerine.value
        answer += 1
    }
    return answer
}
