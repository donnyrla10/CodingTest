import Foundation

/*
 Queue 구현 (Double Array)
 효율성을 위해 input, output을 따로두고
 reverse를 통해 뒤집어서 마지막 원소를 pop한다.
 맨 앞 원소를 pop하면 시간이 더 걸림.
 */

struct Queue<T> {
    private var input: [T] = []
    private var output: [T] = []
    
    var isEmpty: Bool {
        return input.isEmpty && output.isEmpty
    }
    
    var count: Int {
        return input.count + output.count
    }
    
    mutating func push(_ val: T) {
        self.input.append(val)
    }
    
    mutating func pop() -> T? {
        if output.isEmpty {
            output = input.reversed() //O(1)
            input.removeAll()
        }
        return output.popLast()
    }
}
