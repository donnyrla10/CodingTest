import Foundation

let n = Int(readLine()!)!
var card = [Int:Int]() //card number : counting
for _ in 0..<n {
    let c = Int(readLine()!)!
    card[c] = (card[c] ?? 0) + 1
}
print(card.sorted{
    return $0.value == $1.value ? $0.key < $1.key : $0.value > $1.value
}.first!.key)
