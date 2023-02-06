import Foundation

/*
 닉네임 변경하는 방법 (변경 후, 기존 채팅방에 출력되어 있던 메세지 닉네임도 전부 변경
 중복 닉네임 허용.
 모든 기록이 처리된 후,최종 메세지 결과
 */

struct Message {
    let id: String
    let isEnter: Bool
}

func solution(_ record:[String]) -> [String] {
    var messages = [Message]()
    var dictionary = [String: String]() //id:nickname
    for rec in record {
        let m = rec.split(separator: " ").map{ String($0) }
        if m[0] == "Enter" {
            dictionary[m[1]] = m[2]
            messages.append(Message(id: m[1], isEnter: true))
        }else if m[0] == "Leave" {
            messages.append(Message(id: m[1], isEnter: false))
        }else {
            dictionary[m[1]] = m[2] //update nickname
        }
    }
    return messages.map { $0.isEnter ? "\(dictionary[$0.id]!)님이 들어왔습니다." : "\(dictionary[$0.id]!)님이 나갔습니다." }
}

print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))
