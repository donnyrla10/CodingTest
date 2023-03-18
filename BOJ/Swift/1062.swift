import Foundation

//input
var nk = readLine()!.split(separator: " ").map{Int(String($0))!}
var (n, k) = (nk[0], nk[1])
var answer = 0
var alphabet = 0
var wordsBit = [Int](repeating: 0, count: 51)

//문장을 입력받을 때마다 각 단어를 비트마스킹으로 추가
for i in 0..<n {
    let a = readLine()!.map{String($0)}
    for j in a {
        wordsBit[i] |= 1 << (Int(Character(j).asciiValue! - Character("a").asciiValue!))
    }
}

//조합으로 사용할 수 있는 알파벳 구하기
func dfs(_ depth: Int, _ start: Int) {
    if depth == k { //배울 알파벳 모두 골랐으면
        var count = 0
        for i in 0..<n { //고른 알파벳만으로 몇개의 단어를 읽을 수 있는지 카운트
            if wordsBit[i] & alphabet == wordsBit[i] { //wordBit[i]의 알파벳보다 alphabet이 더 많은 알파벳을 가지고 있을 수 있으므로 둘의 공통점만 뽑아서 비교!
                count += 1
            }
        }
        answer = max(answer, count)
        return
    }

    for i in start...25 {
        if (alphabet & (1 << i)) == 0 { //해당 알파벳이 없다면! (중복제외)
            alphabet |= (1 << i)  //알파벳 추가
            dfs(depth + 1, i)     //다음 알파벳 구하러 가기
            alphabet &= ~(1 << i) //초기화 (알파벳 빼기)
        }
    }
}

func solution() -> Int{
    if k < 5 { //a, n, t, c, i 도 못배우는 것이므로 읽을 수 있는 단어 개수가 0개!
        return 0
    }
    //비트마스킹을 사용해서 alphabet에 읽을 수 있는 단어(a, n, t, i, c) 저장
    ["a", "n", "t", "i", "c"].forEach {
        alphabet |= 1 << (Int(Character($0).asciiValue! - Character("a").asciiValue!))
    }
    k -= 5
    dfs(0, 0)
    return answer
}

print(solution())
