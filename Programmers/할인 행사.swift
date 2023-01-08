import Foundation

/*
 일정 금액을 지불하면 10일동안 회원 자격 부여
 회원 대상으로 매일 한 가지 제품 할인하는 행사. 할인제품 하루에 하나만 구매 가능
 회원 등록시 정현이가 원하는 제품을 모두 할인받을 수 있는 회원 등록 날짜의 총 일수를 리턴
 */

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var answer = 0
    var wanted = [String: Int]()
    for i in 0..<want.count {
        wanted[want[i]] = number[i]
    }
    for i in 0...discount.count - 10 {
        var tmp = wanted
        for j in i..<i+10 {
            guard tmp[discount[j]] != nil else { continue }
            if tmp[discount[j]]! > 0 {
                tmp[discount[j]]! -= 1
            }
        }
        if !tmp.values.contains(where: {$0 != 0}) {
            answer += 1
        }
    }
    return answer
}

print(solution(["banana"], [1], ["chicken", "apple", "apple", "rice", "apple", "pork", "pork", "rice", "pot", "apple", "banana"]))
