import Foundation

/*
 Heap 구현해서 하기 - priority
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

struct Edge: Comparable {
    static func < (lhs: Edge, rhs: Edge) -> Bool {
        lhs.weight < rhs.weight
    }
    
    let vertex: Int
    let weight: Int
}

struct Dict : Hashable {
    let vertex: Int
    let weight: Int
}

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var answer = 0
    let inf = Int.max
    var dist = Array(repeating: inf, count: N+1)
    var graph = [[Dict]](repeating: [Dict](), count: N + 1)
    road.forEach {
        graph[$0[0]].append(Dict(vertex: $0[1], weight: $0[2]))
        graph[$0[1]].append(Dict(vertex: $0[0], weight: $0[2]))
    }
    print(graph)
    var pq : Heap = Heap<Edge>()
    pq.insert(Edge(vertex: 1, weight: 0))
    dist[1] = 0 //시작점 0으로 초기화

    while !pq.isEmpty {
        let now = pq.delete()! //weight가 가장 작은 애 없앰
        if dist[now.vertex] < now.weight { continue }

        for next in graph[now.vertex] {
            if now.weight + next.weight < dist[next.vertex] {
                dist[next.vertex] = now.weight + next.weight
                pq.insert(Edge(vertex: next.vertex, weight: next.weight + now.weight))
            }
        }
    }
    
    for i in 1...N {
        if dist[i] <= k { answer += 1 }
    }
    return answer
}
print(solution(5, [[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]], 3))
