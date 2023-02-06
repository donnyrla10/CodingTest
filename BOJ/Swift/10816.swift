import Foundation

let n = Int(readLine()!)!
var sgDict = [String: Int]()
var sg = readLine()!.split(separator: " ").map{ String($0) }
for i in sg {
    sgDict[i] = (sgDict[i] ?? 0) + 1
}
let m = Int(readLine()!)!
var card = readLine()!.split(separator: " ").map{ String($0) }
var answer = [String]()

card.forEach {
    if sgDict[$0] == nil {
        answer.append("0")
    }else {
        answer.append(String(sgDict[$0]!))
    }
}
print(answer.joined(separator: " "))
