# Graph Coverage
### Edge-Pair Coverage
* test case 1
	1. Input values: inputNumber "17" 
	2. Expected result: "-1"
	3. Test program's result: "-1"
	4. Edge-Pair Coverage: (1,2,3),(2,3,9)
* test case2
	1. Input values: inputNumber "1" 
	2. EXpected result: "1"
	3. Test program's result: "1"
	4. Edge-Pair Coverage: (1,2,3),(2,3,4),(3,4,5),(4,5,8)
*  test case3
	1. Input values: inputNumber "2" 
	2. EXpected result: "2"
	3. Test program's result: "2"
	4. Edge-Pair Coverage: (1,2,3),(2,3,4),(3,4,5),(4,5,7),(5,7,6),(7,6,5),(6,5,8)

### Test Path Coverage
* test case 1
	1. Input values: inputNumber "17"
	2. Expected result: "-1"
	3. Test program's result: "-1"
	4. Test Path Coverage: 1->9(1,2,3,9)
* test case 2
	1. Input values: inputNumber "1"
	2. Expected result: "1"
	3. Test program's result: "1"
	4. Test Path Coverage: 1->8(1,2,3,4,5,8)	//no loop
* test case 3
	1. Input values: inputNumber "2"
	2. Expected result: "2"
	3. Test program's result: "2"
	4. Test Path Coverage: 1->8(1,2,3,4,5,7,6,5,8)	//loop


