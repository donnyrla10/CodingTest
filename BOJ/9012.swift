import Foundation

let t = Int(readLine()!)!

func checkCorrectParenthesis(_ parenthesis: [String]) {
    var stack = [String]()

    for paren in parenthesis {
        if paren == "(" {
            stack.append(paren)
        }else {
            if stack.isEmpty {
                print("NO")
                return
            }else {
                stack.removeLast()
            }
        }
    }
    if stack.isEmpty {
        print("YES")
    }else {
        print("NO")
    }
    return
}

for _ in 0..<t {
    let parenthesis = readLine()!.map{ String($0) }
    checkCorrectParenthesis(parenthesis)
}
