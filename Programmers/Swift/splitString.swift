import Foundation

func solution(_ s:String) -> Int {
    guard 1...10000 ~= s.count else {return 0}
    let tmp = s.map{$0}
    guard s.filter({$0 == tmp[0]}).count != tmp.count else {return 1}
    var answer = 0
    var index = 1
    var x = tmp[0]
    var xcnt = 1
    var cnt = 0
    var changeX : Bool = false

    repeat {
        if index + 1 == tmp.count {
            answer += 1
            break
        }
        if changeX {
            x = tmp[index]
            xcnt = 1
            cnt = 0
            changeX = false
            index += 1
            continue
        }
        if x == tmp[index] {
            xcnt += 1
        }else {
            cnt += 1
        }
        if cnt == xcnt {
            answer += 1
            changeX = true
        }
        index += 1
    }while index < tmp.count
    return answer
}
