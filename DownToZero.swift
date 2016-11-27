/*
 
 Down to Zero II
 ---------------
 
 You are given Q queries. Each query consists of a single number N. You can perform 2 operations on N in each move. If N = a x b (a != 1, b != 1), we can change N = max(a, b) or decrease the value of N by 1.
 
 Determine the minimum number of moves required to reduce the value of N to 0.
 
 Input Format
 
 The first line contains the integer Q.
 The next  lines each contain an integer, N.
 
 Constraints
 
 1 <= Q <= 1000
 0 <= N <= 1000000
 
 
 Output Format
 
 Output Q lines. Each line containing the minimum number of moves required to reduce the value of N to 0.
 
*/

// Swift 3.0.1

func maxFactors(n: Int) -> Set<Int> {
    var tryFactor = 2
    var factors: Set<Int> = []
    
    // return no factors in case of small numbers 0, 1, 2, 3.
    if (n <= 3) {
        return factors
    }
    
    while (tryFactor * tryFactor <= n) {
        if n % tryFactor == 0 {
            factors.insert(n/tryFactor) // insert the larger factor
        }
        tryFactor += 1
    }
    
    return factors;
}

func downToZero(n: Int) -> Int {
    
    if ( n <= 3) {
        return n
    }
    
    var soFarNumbers : Set<Int> = []
    var nextNumbers: Set<Int> = [n]
    var currentNumbers : Set<Int>
    var stepsToZero = 0
    
    while true {
        // only get the new numbers
        currentNumbers = nextNumbers.subtracting(soFarNumbers)
        soFarNumbers.formUnion(currentNumbers)
        
        nextNumbers = []
        for number in currentNumbers.sorted() {
            
            if (number <= 3) {
                return stepsToZero + number
            }
            nextNumbers.insert(number - 1)
            let factors = maxFactors(n: number)
            nextNumbers.formUnion(factors)
            
        }
        //print(nextNumbers)
        stepsToZero += 1
    }
}


func readNumber() -> Int {
    let optNumber = readLine()
    return Int(optNumber!)!
}

let q = readNumber()

for _ in 1...q
{
    let n = readNumber()
    print(downToZero(n:n))
}
