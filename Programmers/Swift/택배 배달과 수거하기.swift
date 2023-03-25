import Foundation

//deliveries -> i+1번째 집에 배달할 택배 상자의 개수
//pickups -> i+1번째 집에서 수거할 택배상자의 개수
//가장 먼 거리를 먼저 끝내기 -> 최대한 한번에 끝내기

func solution(_ cap:Int, _ n:Int, _ deliveries:[Int], _ pickups:[Int]) -> Int64 {
    var answer = 0
    var d = deliveries
    var p = pickups
    while !d.isEmpty && d.last! == 0 { d.removeLast() } //배달없는 곳 삭제
    while !p.isEmpty && p.last! == 0 { p.removeLast() } //수거없는 곳 삭제
    
    while !d.isEmpty || !p.isEmpty { //둘 다 빌때까지
        answer += max(d.count, p.count) * 2 //가장 먼 곳으로 이동
        var box = cap
        //배달
        while !d.isEmpty && box >= 0 {
            let now = d.removeLast()
            if now <= box {
                box -= now
            }else {
                d.append(now - box)
                break
            }
        }
        //수거
        box = cap
        while !p.isEmpty && box >= 0 {
            let now = p.removeLast()
            if now <= box {
                box -= now
            }else {
                p.append(now - box)
                break
            }
        }
    }
    return Int64(answer)
}

print(solution(4, 5, [1,0,3,1,2], [0,3,0,4,0]))
