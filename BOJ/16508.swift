import Foundation

/*
 가장 적은 비용으로 민호가 원하는 단어를 만들기 위해 어떤 전공책을 선택해야 할까?
 단어를 만들기 위해 선택해야 하는 전공책의 가장 적은 가격의 합 구하기
 */

//input
let t = readLine()!.map{ String($0) }
let n = Int(readLine()!)!
var books = [(String, Int)]()
var talpha = [Int](repeating: 0, count: 26)
var bookAlpha = [Int](repeating: 0, count: 26)
var answer = Int.max

for i in 0..<t.count {
    let index = Int(UnicodeScalar(t[i])!.value) - Int(UnicodeScalar("A").value)
    talpha[index] += 1
}

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ String($0) }
    books.append((input[1], Int(input[0])!))
}

//list에 있는 책들로 단어를 만들 수 있는지 체크하는 함수
func checkWord() -> Bool {
    for i in 0..<26 {
        if talpha[i] > bookAlpha[i] { return false }
    }
    return true
}

func searchWord(count: Int, sum: Int) {
    if n == count { //정한 책의 개수를 채웠을 경우
        if checkWord() { //만약 선택한 책에서 단어를 만들어낼 수 있다면
            answer = min(answer, sum)
        }
        return
    }
    let tmp = books[count].0.map{String($0)}
    for i in 0..<tmp.count {
        let index = Int(UnicodeScalar(tmp[i])!.value) - Int(UnicodeScalar("A").value)
        bookAlpha[index] += 1
    }
    searchWord(count: count + 1, sum: sum + books[count].1)
    for i in 0..<tmp.count {
        let index = Int(UnicodeScalar(tmp[i])!.value) - Int(UnicodeScalar("A").value)
        bookAlpha[index] -= 1
    }
    searchWord(count: count + 1, sum: sum)
}

searchWord(count: 0, sum: 0)

if answer == Int.max { answer = -1 }
print(answer)
