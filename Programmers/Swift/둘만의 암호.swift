import Foundation

/*
 문자열 s와 skip, 자연수 index로 문자열 만들기
 - s의 각 알파벳을 index만큼 뒤의 알파벳으로 바꾸기
 - index 만큼의 뒤의 알파벳이 z를 넘어갈 경우, 다시 a로 돌아가기
 - skip에 있는 알파벳은 제외
 */

func solution(_ s:String, _ skip:String, _ index:Int) -> String {
    var s = s.map{ String($0) }
    let alph = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
    for i in 0..<s.count {
        var cnt = 0
        var idx = Int(UnicodeScalar(s[i])!.value) - Int(UnicodeScalar("a").value) //시작 위치
        while true {
            idx = (idx + 1) % 26 //다음 위치
            if !skip.contains(alph[idx]) { //다음 위치의 알파벳이 skip에 없다면
                cnt += 1 //카운팅
            }
            if cnt == index {
                s[i] = alph[idx]
                break
            }
        }
    }
    return s.joined()
}

print(solution("aukks", "wbqd", 5))
