import Foundation

/*
 수집된 개인 정보는 유효기간 "전"까지만 보관 가능, 유효 기간 지나면 반드시 파기 (유효기간에 딱 맞아도 파기)
 모든 달은 28일까지 있음
 개인 정보 수집 일자에서 유효기간까지 보관 가능. 오늘 날짜가 그 이상이면 파기해야 될 개인 정보
 2021.05.02에서 유효기간 6달이면, 2021.11.01 까지 가능!
 파기해야할 개인정보 번호를 오름차순으로 담아 리턴
 */

func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
    var answer = [Int]()
    let today = today.split(separator: ".").map{ Int(String($0))! }
    var clause = [String: Int]()
    var index = 1
    
    terms.forEach {
        let term = $0.split(separator: " ").map{ String($0) }
        clause[term[0]] = Int(term[1])!
    }
    
    privacies.forEach{
        let privacy = $0.components(separatedBy: [".", " "]).map{ String($0) }
        var lastDay = [Int(privacy[0])!, Int(privacy[1])!, Int(privacy[2])!] //year,month,day
        //약관에 맞는 유효기간 찾기(dictionary에 있음)
        let validity = clause[privacy[3]]!
        //privacy 달과 validity 더하기
        lastDay[0] += validity / 12
        lastDay[1] += validity % 12
        if lastDay[1] > 12 { //(다음해) 만약 12를 넘기면 해 + 1 && - 12
            lastDay[1] -= 12
            lastDay[0] += 1
        }
        //유효 기간 넘어가지 않음
        if lastDay[0] < today[0] {
            answer.append(index)
        }else if lastDay[0] == today[0] { //같은 해
            if lastDay[1] < today[1] {
                answer.append(index)
            } else if lastDay[1] == today[1] {
                if lastDay[2] <= today[2] {
                    answer.append(index)
                }
            }
        }
        index += 1
    }
    return answer
}

print(solution("2022.05.19", ["A 6", "B 12", "C 3"], ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]))
print(solution("2020.01.01", ["Z 3", "D 5"],  ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]))
