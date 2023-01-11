import Foundation

/*
 Queue 구현 (cursor 이용)
 Double Array를 사용해면 극단적인 케이스에서 시간초과가 발생할 수 있다.
 cursor는 pointer로 top을 가리킨다.
 */

struct Queue<T> {
    var input: [T] = []
    var cursor = 0
    
    var isEmpty: Bool {
        return count == cursor
    }
    
    var count: Int {
        return input.count - cursor
    }
    
    mutating func push(_ value: T) {
        input.append(value)
    }
    
    mutating func pop() -> T? {
        guard cursor < input.count else { return nil }
        defer {
            cursor += 1
            
            if cursor >= 100 && cursor < input.count {
                input = Array(input[cursor..<input.count])
                cursor = 0
            }
        }
        return input[cursor]
    }
}
