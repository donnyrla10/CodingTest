import Foundation

/*
 Heap 구현
 라이노님 https://gist.github.com/JCSooHwanCho/a3f070c2160bb8c0047a5ddbb831f78e
 */

public struct Heap<T> {
    var nodes: [T] = [] //heap nodes 담을 배열
    let comparer: (T,T) -> Bool //비교자
    
    var isEmpty: Bool {
        return nodes.isEmpty
    }
    
    init(comparer: @escaping (T,T) -> Bool) { //비교자 초기화
        self.comparer = comparer
    }
    
    //노드 추가
    mutating func insert(_ element: T) {
        var index = nodes.count //노드가 추가될 맨 뒤 인덱스
        
        nodes.append(element) //노드 추가
        
        //(index-1)/2 == 부모 노드
        //index == 0 (꼭대기 노드) 되거나 부모보다 크(<)/작으(>)면 끝
        while index > 0, !comparer(nodes[index], nodes[(index-1)/2]) {
            nodes.swapAt(index, (index-1)/2)
            index = (index - 1) / 2
        }
    }
    
    mutating func delete() -> T? {
        guard !nodes.isEmpty else { return nil }
        if nodes.count == 1 { return nodes.removeFirst() }
        
        let result = nodes.first //삭제될 맨 첫번째(min/max) element
        nodes.swapAt(0, nodes.count - 1) //맨 위랑 맨 마지막 swap
        _ = nodes.popLast() //last element 삭제
        
        var index = 0
        
        
        //모든 노드 이동..
        while index < nodes.count { //배열 모두 순회
            let left = index * 2 + 1
            let right = left + 1
            
            if right < nodes.count {
                if comparer(nodes[left], nodes[right]),
                   !comparer(nodes[right], nodes[index]) {
                    nodes.swapAt(right, left)
                    index = right
                } else if !comparer(nodes[left], nodes[index]) {
                    nodes.swapAt(left, right)
                    index = left
                } else {
                    break
                }
            } else if left < nodes.count {
                if !comparer(nodes[left], nodes[index]) {
                    nodes.swapAt(left, index)
                    index = left
                } else {
                    break
                }
            } else {
                break
            }
        }
        return result
    }
}

extension Heap where T: Comparable {
    init() {
        self.init(comparer: >) //<: max heap, >: min heap
    }
}
