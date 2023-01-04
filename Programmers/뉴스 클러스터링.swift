import Foundation

/*
 선행 스킬이란, 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻한다.
 순서에 없는 다른 스킬은 순서에 상관없이 배울 수 있다.
 가능한 스킬트리 개수를 출력한다.
 */

func solution(_ str1:String, _ str2:String) -> Int {
    //1. 둘다 대문자로 바꾸기
    let str1 = str1.uppercased().map{ $0 }
    let str2 = str2.uppercased().map{ $0 }
    var arr1 = [String]()
    var arr2 = [String]()
    for i in 0..<str1.count-1 {
        if str1[i].isLetter, str1[i+1].isLetter {
            arr1.append(String(str1[i]) + String(str1[i+1]))
        }
    }
    for i in 0..<str2.count-1 {
        if str2[i].isLetter, str2[i+1].isLetter {
            arr2.append(String(str2[i]) + String(str2[i+1]))
        }
    }
    //교집합
    var union = arr1.count + arr2.count
    var intersection = 0
    for i in arr1.indices{
        for j in arr2.indices{
            if arr1[i] == arr2[j]{
                intersection += 1
                arr2.remove(at: j)
                break
            }
        }
    }
    union -= intersection
    if union == 0 { return 65536 }
    if intersection == 0 { return 0 }
    return Int(Double(intersection) / Double(union) * 65536)
}

print(solution("aa1+aa2", "AAAA12"))
