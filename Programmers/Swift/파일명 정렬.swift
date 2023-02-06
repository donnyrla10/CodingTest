import Foundation

/*
 코드 순이 아닌, 파일명에 포함된 숫자를 반영한 정렬기능 구현하기
 HEAD: 숫자가 아닌 문자로 이루어지고, 최소 한 글자 이상
 NUMBER: 1~5 연속된 숫자. 00000-99999
 TAIL: 나머지 부분. 숫자 혹은 아무 글자가 없을 수도 있음
 이렇게 3가지로 나눈 후, 파일명을 정렬한다. 윗 조건이 같을 경우 밑 조건 ㄱㄱ
 1. HEAD 기준으로 먼저 사전순 정렬 (대소문 구분x)
 2. NUMBER 숫자순 정렬
 3. 원래 입력에 주어진 순서 유지.
 */

func solution(_ files:[String]) -> [String] {
    return files.sorted { file1, file2 in
        let numberStartIndex1 = file1.firstIndex(where: { $0.isNumber })!
        let numberStartIndex2 = file2.firstIndex(where: { $0.isNumber })!
        let numberEndIndex1 = file1[numberStartIndex1...].firstIndex(where: { !$0.isNumber }) ?? file1.endIndex
        let numberEndIndex2 = file2[numberStartIndex2...].firstIndex(where: { !$0.isNumber }) ?? file2.endIndex
        let head1 = file1[file1.startIndex..<numberStartIndex1].lowercased()
        let number1 = file1[numberStartIndex1..<numberEndIndex1]
        let finalNumber1 = number1.count > 5 ? Int(number1.prefix(5))! : Int(number1)!
        let head2 = file2[file2.startIndex..<numberStartIndex2].lowercased()
        let number2 = file2[numberStartIndex2..<numberEndIndex2]
        let finalNumber2 = number2.count > 5 ? Int(number2.prefix(5))! : Int(number2)!
        if head1 == head2 {
            if finalNumber1 == finalNumber2 {
                return file1 == file2
            } else {
                return finalNumber1 < finalNumber2
            }
        }
        return head1 < head2
    }
}
