import Foundation

/*
 나무 M미터가 필요
 절단기 높이 H 지정해야 한다.
 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다.
 한줄에 연속해있는 나무를 모두 절단한다. 높이가 H보다 큰 나무는 H 위의 부분이 잘리고, 낮은 나무는 잘리지 않는다.
 적어도 M미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값을 구하라. -> 매개변수 탐색
*/

let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
var trees = readLine()!.split(separator: " ").map{ Int(String($0))! }
var answer = 0

func calculator(H: Int) -> Bool {
    var sum = 0
    for i in 0..<nm[0] {
        if trees[i] > H { sum += trees[i] - H }
    }
    return sum >= nm[1]
}

func BinarySearch(){
    var l = 0
    var r = trees.max()!
    
    while l <= r {
        var mid = (l+r)/2
        if calculator(H: mid) { //이 H 길이 톱으로 나무를 잘랐을 때 최소 M 미터의 나무를 가져갈 수 있다.
            answer = mid //이전 answer보다 항상 크다
            l = mid + 1  //더 긴 H길이의 톱으로도 가능한지 더 탐색
        }else {
            r = mid - 1  //더 짧은 길이로 해보기
        }
    }
}

BinarySearch()
print(answer)
