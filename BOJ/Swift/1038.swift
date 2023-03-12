import Foundation

/*
 감소하는 수
 정수 X의 자릿수가 가장 큰 자릿수부터 작은 자릿수까지 감소한다면
 예를 들어, 321, 950. 322, 958 안됨
 N번째 감소하는 수를 출력하라.
 */

//input
let n = Int(readLine()!)!
var cnt = -1

func bt(_ now: Int, _ num: String, _ dest: Int) {
    if now == dest {
        cnt += 1
        if cnt == n {
            print(num)
            exit(0)
        }
    }
    
    for i in 0...9 {
        if num != "" {
            if String(num.last!) <= String(i) { continue }
        }
        bt(now+1, num + String(i), dest)
    }
}

for i in 1...10 {
    bt(0, "", i)
}
print(-1)
