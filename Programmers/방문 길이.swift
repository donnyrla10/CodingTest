import Foundation

/*
 상하좌우로 한칸씩 이동. (0,0)에서 시작. 최대 (-5,5)
 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이 구하기
 경계를 넘어선 명령은 무시
 */

struct RoadCoordinate: Hashable {
    let sx, sy, ex, ey : Int
}

func solution(_ dirs:String) -> Int {
    var answer = 0
    var currentCoordinate = (0, 0) //tuple x, y
    var setRoad = Set<RoadCoordinate>()
    
    //경계안에 있는지 체크
    func checkOutOfRange(endX: Int, endY: Int) -> Bool {
        return (-5...5) ~= endX && (-5...5) ~= endY ? true : false
    }
    
    //갔던 곳인지 체크
    func checkVisited(endX: Int, endY: Int) -> Bool {
        return setRoad.contains(RoadCoordinate(sx: currentCoordinate.0, sy: currentCoordinate.1, ex: endX, ey: endY)) || setRoad.contains(RoadCoordinate(sx: endX, sy: endY, ex: currentCoordinate.0, ey: currentCoordinate.1)) ? true : false
    }
    
    for dir in dirs {
        var endX = currentCoordinate.0
        var endY = currentCoordinate.1
        
        switch dir {
        case "U": endX -= 1 //-1,  0
        case "D": endX += 1 // 1,  0
        case "R": endY += 1 // 0,  1
        case "L": endY -= 1 // 0, -1
        default:  break
        }
        
        guard checkOutOfRange(endX: endX, endY: endY) else { continue } //범위를 넘어서면 명령 패스
        if !checkVisited(endX: endX, endY: endY) {
            answer += 1
            setRoad.insert(RoadCoordinate(sx: currentCoordinate.0, sy: currentCoordinate.1, ex: endX, ey: endY))
        }
        currentCoordinate = (endX, endY) //current coordinate update
    }
    return answer
}

print(solution("ULURRDLLU")) //7
print(solution("LULLLLLLU")) //7
