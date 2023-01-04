import Foundation

/*
 주차장의 요금표와 입차/출차 기록이 주어졌을 때 차량별로 주차 요금 계산
 */

struct Car {
    var intime: String
    var cumulativeSum: Int
    var isParking: Bool
}

func calculateParkingTime(inTime: String, outTime: String) -> Int {
    var parkingTime = 0
    var outH = Int(outTime[outTime.startIndex..<outTime.index(outTime.startIndex, offsetBy: 2)])!
    let outM = Int(outTime[outTime.index(outTime.startIndex, offsetBy: 3)..<outTime.endIndex])!
    let inH = Int(inTime[inTime.startIndex..<inTime.index(inTime.startIndex, offsetBy: 2)])!
    let inM = Int(inTime[inTime.index(inTime.startIndex, offsetBy: 3)..<inTime.endIndex])!
    
    //minute부터 계산
    if inM > outM {
        parkingTime = outM + 60 - inM
        outH -= 1
    }else {
        parkingTime = outM - inM
    }
    
    parkingTime += (outH - inH) * 60 //hour 계산 (분으로 만들어야 함)
    return parkingTime
}

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var carDictionary = [String:Car]()
    var final = [String:Int]()
    let defaultTime = fees[0], defaultFee = fees[1], unitTime = fees[2], unitFee = fees[3]
    for record in records {
        let recordArray = record.split(separator: " ").map{ String($0) }
        if recordArray[2] == "IN" {
            if carDictionary[recordArray[1]] == nil {
                carDictionary[recordArray[1]] = Car(intime: recordArray[0], cumulativeSum: 0, isParking: true)
            } else {
                carDictionary[recordArray[1]]!.intime = recordArray[0]
                carDictionary[recordArray[1]]!.isParking = true
            }
        }else { //OUT
            let inTime = carDictionary[recordArray[1]]!.intime //입차시간
            //출차 - 입차 시간 구하기 (주차시간)
            carDictionary[recordArray[1]]!.cumulativeSum += calculateParkingTime(inTime: inTime, outTime: recordArray[0])
            carDictionary[recordArray[1]]!.isParking = false
        }
    }
    //딕셔너리에 있는 애들의 누적합을 통해 주차요금 계산하기
    for car in carDictionary {
        var sum = car.value.cumulativeSum
        if car.value.isParking == true { //23:59에 출차
            sum += calculateParkingTime(inTime: car.value.intime, outTime: "23:59")
        }
        var parkingFee = 0
        if sum > defaultTime {
            var overTime = (sum - defaultTime) % unitTime != 0 ? (sum - defaultTime) / unitTime + 1 : (sum - defaultTime) / unitTime //나누어 떨어지지 않으면 올린다
            parkingFee = defaultFee + overTime * unitFee
        } else {
            parkingFee = defaultFee
        }
        final[car.key] = parkingFee
    }
    return final.sorted { return $0.key < $1.key }.map{ $0.value }
}

print(solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
                                      "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
                                      "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
