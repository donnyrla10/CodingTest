import Foundation

struct Student {
    let name: String
    let korean: Int
    let english: Int
    let math: Int
}

let n = Int(readLine()!)!
var array = [Student]()
for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ String($0) }
    array.append(Student(name: input[0], korean: Int(input[1])!, english: Int(input[2])!, math: Int(input[3])!))
}
array = array.sorted(by: { st1, st2 in
    if st1.korean == st2.korean {
        if st1.english == st2.english {
            if st1.math == st2.math {
                return st1.name < st2.name
            }
            return st1.math > st2.math
        }
        return st1.english < st2.english
    }
    return st1.korean > st2.korean
})

array.forEach {
    print($0.name)
}
