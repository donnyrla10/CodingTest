import Foundation

/*
 철자의 순서를 뒤바꾸어 같아질 수 있는 두 단어 == 애너그램 관계
 */

var a = readLine()!
var b = readLine()!
var numberA = Array(repeating: 0, count: 26)
var numberB = Array(repeating: 0, count: 26)
var answer = 0
for aa in a { numberA[Int(UnicodeScalar(String(aa))!.value) - Int(UnicodeScalar("a").value)] += 1 }
for bb in b { numberB[Int(UnicodeScalar(String(bb))!.value) - Int(UnicodeScalar("a").value)] += 1 }
for i in 0..<26 {
    answer += abs(numberB[i] - numberA[i])
}
print(answer)
