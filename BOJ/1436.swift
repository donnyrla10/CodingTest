import Foundation

let n = Int(readLine()!)!
var m = 0
var i = 666
while true {
    let str = String(i)
    var cnt = 0
    for s in str {
        if s == "6" { cnt += 1 }
        else { cnt = 0 }
        if cnt == 3 {
            m += 1
        }
    }
    if n == m { break }
    i += 1
}
print(i)
