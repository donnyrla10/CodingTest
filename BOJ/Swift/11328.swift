import Foundation

let n = Int(readLine()!)!
for _ in 0..<n {
    let str = readLine()!.split(separator: " ").map{ String($0) }
    if strfry(a: str[0], b: str[1]) {
        print("Possible")
    }else {
        print("Impossible")
    }
}

func strfry(a: String, b: String) -> Bool {
    let tmpA = a.sorted()
    let tmpB = b.sorted()
    return tmpA == tmpB
}
