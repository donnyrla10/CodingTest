import Foundation

let directions = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
struct FireBall {
    let r: Int
    let c: Int
    let mass: Int
    let speed: Int
    let direction: Int
    
    func move(n: Int) -> Self {
        var nr = (directions[direction][0] * speed + r) % n
        var nc = (directions[direction][1] * speed + c) % n
        if nr < 0 { nr += n } //왼쪽으로 넘어가면 n을 더해주면 된다
        if nc < 0 { nc += n }
        return FireBall(r: nr, c: nc, mass: mass, speed: speed, direction: direction)
    }
}

//input
let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let n = input[0]
let m = input[1]
let k = input[2]
var fireBalls = [FireBall]()
var array = Array(repeating: Array(repeating: [FireBall](), count: n), count: n)

for _ in 0..<m {
    let fireball = readLine()!.split(separator: " ").map{ Int(String($0))! }
    fireBalls.append(FireBall(r: fireball[0]-1, c: fireball[1]-1, mass: fireball[2], speed: fireball[3], direction: fireball[4]))
}

func move() {
    // 1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
    fireBalls = fireBalls.map{$0.move(n: n)}
    array = Array(repeating: Array(repeating: [FireBall](), count: n), count: n)
    fireBalls.forEach { fireball in
        array[fireball.r][fireball.c].append(fireball)
    }
}

// 2. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
func merge() {
    //filter 고차 함수로 파이어볼 2개 이상인 곳만 걸러내서 mergeList 만들기 → [[], [], [], []] 이런 식으로 같은 좌표에 있는 파이어볼이 하나의 배열 원소로 들어감
    let fireBallsInSameRoom = array.flatMap{$0}.filter{ $0.count >= 2 }
    
    for fireballs in fireBallsInSameRoom {
        let x = fireballs.first!.r
        let y = fireballs.first!.c
        var isEven = false
        var isOdd = false
        var mass = 0
        var speed = 0
        
        for fireball in fireballs {
            if fireball.direction % 2 == 0 { isEven = true }
            else { isOdd = true }
            mass += fireball.mass
            speed += fireball.speed
        }
        mass /= 5
        speed /= fireballs.count
        
        if mass == 0 {
            array[x][y] = []
            continue
        }
        
        //4개의 파이어볼로 나눠서 (x,y)좌표에 업데이트 (추가x 4개만 해당 좌표에 있는 것)
        let ballsDirection = isEven && isOdd ? [1,3,5,7] : [0,2,4,6]
        array[x][y] = ballsDirection.map{FireBall(r: x, c: y, mass: mass, speed: speed, direction: $0)} //ballsDirection 배열을 map으로 순회하면서 차례로 FireBall 객체에 파라미터 값으로 넣어줌
    }
    
    //update fireBalls
    fireBalls = array.flatMap{$0}.flatMap{$0} //3차원 배열을 1차원 배열로 압축 (nil 제외)
}

for _ in 0..<k {
    move()
    merge()
}

print(fireBalls.reduce(0, { partialResult, fireball in
    partialResult + fireball.mass
}))
