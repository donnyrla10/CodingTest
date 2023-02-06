import Foundation

/*
 재료 N개
 각 재료의 신맛S 쓴맛B
 여러 재료를 이용해서 요리할 때, 음식의 신맛은 사용한 재료의 신맛의 곱, 쓴맛은 합
 요리의 신맛과 쓴맛의 차이를 작게 만들려고 한다. 물을 요리라고 할 수 없기 때문에 재료는 적어도 하나 사용
 차이가 가장 작은 요리를 만들어라. 가장 작은 차이 출력
 */

let n = Int(readLine()!)!
var ing = [[Int]]()
var answer = Int.max
for _ in 0..<n {
    ing.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

func choose(_ cnt: Int, _ s:Int, _ b: Int) {
    if cnt == n {
        guard s != 0 && b != 0 else { return }
        answer = min(answer, abs(s-b))
        return
    }
    choose(cnt+1, s, b)
    choose(cnt+1, s == 0 ? ing[cnt][0] : s * ing[cnt][0], b + ing[cnt][1])
}
choose(0, 0, 0)
print(answer)
