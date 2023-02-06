import Foundation

/*
 L개의 다른 알파벳 소문자로 구성.
 최소 한개의 모음, 최소 2개의 자음으로 구성
 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열 (오름차순)
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (l,c) = (input[0], input[1])
var array = readLine()!.split(separator: " ").map{ String($0) }.sorted()
var answer = [String]()
var visited = [Bool](repeating: false, count: c+1)

func checkAlpha(str: String) -> Bool {
    var (consonant, vowel) = (0,0)
    str.forEach {
        if $0 == "a" || $0 == "e" || $0 == "i" || $0 == "o" || $0 == "u" { vowel += 1}
        else { consonant += 1 }
    }
    return consonant >= 2 && vowel >= 1 ? true : false
}

func bt(k: Int, s: Int, str: String) {
    if k == l {
        if checkAlpha(str: str) { answer.append(str) }
        return
    }
    
    for i in s..<c {
        if !visited[i] {
            visited[i] = true
            bt(k: k+1, s: i, str: str + array[i])
            visited[i] = false
        }
    }
}

bt(k: 0, s: 0, str: "")
answer.forEach {
    print($0)
}
