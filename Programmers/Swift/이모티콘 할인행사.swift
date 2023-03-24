import Foundation

/*
 1. 가입자를 최대한 늘리는 것
 2. 판매액을 최대한 늘리는 것
 n명의 사용자들에게 m개를 할인해서 판매
 할인율은 다를 수 있으며, 10, 20, 30, 40 중 하나로 설정
 기준에 따라 이모티콘을 사거나, 이모티콘 플러스 서비스에 가입
 사용자들은 자신의 기준에 따라 일정 비율 이상 할인하는 이모티콘을 모두 구매
 자신의 기준에 따라 이모티콘 구매 비용의 합이 일정 가격 이상이 된다면, 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입
 
 */

var rate = [10, 20, 30, 40]
var combination = [Int]()
var n = 0 //이모티콘 개수
var result = [(Int, Int)]()

//만든 경우에 따른 결과값 계산
func calculate(_ users: [[Int]], _ emoticons: [Int]) -> (Int, Int) {
    var amount = 0 //이모티콘 매출액
    var account = 0 //서비스 가입수
    for user in users {
        var sum = 0
        for i in 0..<emoticons.count {
            if combination[i] >= user[0] { //사용자 할인율보다 큰 이모티콘만 구매
                sum += emoticons[i] - Int(Double(emoticons[i]) * Double(combination[i]) / 100.0)
            }
        }
        if sum >= user[1] { account += 1 } //이모티콘 플러스 가입
        else { amount += sum }
    }
    return (account, amount)
}

//각 이모티콘에 대한 할인율 순열 구하기(중복가능)
func bt(_ now: Int, _ users: [[Int]], _ emoticons: [Int]) {
    if now == n {
        result.append(calculate(users, emoticons))
        return
    }
    for i in 0..<rate.count {
        combination.append(rate[i])
        bt(now+1, users, emoticons)
        combination.removeLast()
    }
}

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    n = emoticons.count
    bt(0, users, emoticons)
    result = result.sorted(by: { $0.0 == $1.0 ? $0.1 > $1.1 : $0.0 > $1.0 })
    return [result[0].0, result[0].1]
}

print(solution([[40, 10000], [25, 10000]], [7000,9000]))
print(solution([[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]], [1300, 1500, 1600, 4900]))
