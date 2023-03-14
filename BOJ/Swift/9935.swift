import Foundation

/*
 문자열에 폭발 문자열을 심어 놓았다. 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지고 남은 문자열은 합쳐진다
 1. 모든 폭발 문자열이 폭발
 2. 남은 문자열을 순서대로 이어 붙여서 새로운 문자열 만들기
 3. 폭발 문자열이 없을때까지 반복
 남은 문자열이 없는 경우 "FRULA" 출력
 */

//input
let word = readLine()!.map{ String($0) }
let explosion = readLine()!
let explosionLength = explosion.map{ String($0) }.count

//폭발 문자열이 없거나 남은 문자열이 없을 때까지 반복
var stack = ""
var count = 0
var i = 0
repeat {
    stack += word[i]
    count += 1
    i += 1
    if count < explosionLength { continue }
    if stack.hasSuffix(explosion) {
        stack.removeLast(explosionLength)
    }
} while i < word.count

print(stack == "" ? "FRULA" : stack)

//시간초과
//while word.contains(explosion) && !word.isEmpty {
//    word = word.replacingOccurrences(of: explosion, with: "")
//}
//print(word == "" ? "FRULA" : word)
