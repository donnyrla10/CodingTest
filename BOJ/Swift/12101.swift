import Foundation

//input
let nk = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n, k) = (nk[0], nk[1])
var arr = [Int]()
var cnt = 0
var flag = false

func BT(_ sum: Int) {
    print(arr)
    if flag { return }
    if cnt == k { //k번째로 오는
        print(arr.map{String($0)}.joined(separator: "+"))
        flag = true
        return
    }

    for i in 1...3 {
        if sum + i > n { continue } //가지치기. n보다 크면 뒤는 할 필요 없음
        if sum + i == n { cnt += 1 }
        arr.append(i)
        BT(sum + i) //n을 만들 수 있는 경우의 수 카운팅
        arr.removeLast()
    }
}
BT(0)
if !flag { print("-1") }

//// MARK: DP
//let inp = readLine()!.split(separator: " " ).map{Int(String($0))!}
//let N = inp[0], K = inp[1]
//
//var dp = Array(repeating:[String](),count:11)
//dp[1] = ["1"]
//dp[2] = ["11","2"]
//dp[3] = ["111","21","12","3"]
////13, 112, 22, 1111, 211, 121, 31 (6)
//
////for i in 4...10 {
//let i = 4
//    for k in ["1","2","3"] {
//        for arr in dp[i-Int(k)!] { //점화식: dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
//            dp[i].append(arr+k) //뒤에 붙이기
//            print(dp[i])
//        }
//    }
////}
//
////i = 4, k == "1"
////dp[3]의 원소에 "1"붙여서 dp[4]에 넣기
////dp[4] = "1111", "211", "121", "31"
////k == "2"
////dp[2]의 원소에 "2"붙여서 dp[4]에 넣기
////dp[4] = "112", "22"
////k == "1"
////dp[1]의 원소에 "3"붙여서 dp[4]에 넣기
////dp[4] = "13"
//
//let sorted = dp[N].sorted(by: {$0<$1}) //정렬, k번째 경우의 수 찾아야 하므로
//if sorted.count < K {
//    print(-1)
//}else {
//    var answer = ""
//    sorted[K-1].forEach{answer += String($0)+"+"}
//    answer.removeLast()
//    print(answer)
//}
