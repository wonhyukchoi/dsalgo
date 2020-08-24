/* 
 * Top-down dynamic memoization implementation 
 * of the fibonacci sequence. 
 *
 * ASIDE: (As somebody who's done research on the fib sequence...)
 * Who will ever prove the largeness of the fibonacci sequence?
 * I tried several times, to no avail.
 * I thought when I obtained all this knowledge, 
 * that I would be able to compute a meaningful answer,
 * but I only ended up realizing that computation was just a tool,
 * not a way of solving problems.
 *
 * If somebody can ever prove the largeness of the fibonacci numbers,
 * please do so and let me know, it would let me sleep at night.
 */
#include <iostream>
#include <unordered_map>
#include <cassert>

long fibonacci(int index, std::unordered_map<int, long> &fibTable){
	// https://stackoverflow.com/a/6897865/11801882
	auto iter = fibTable.find(index);
	if(iter != fibTable.end()){
		return iter->second;
	}
	else {
		long a = fibonacci(index-1, fibTable);
		long b = fibonacci(index-2, fibTable);
		long answer = a + b;
		fibTable.insert({index, answer});
		return answer;
	}
}

long fibonacci(int index){
	std::unordered_map<int, long> fibTable;
	fibTable.insert({0,0});
	fibTable.insert({1,1});
	return fibonacci(index, fibTable);	
}


int main(int argc, char**argv){
	int index = 0x2f;
	long expected = 2971215073;
	long calculated = fibonacci(index);

	// https://stackoverflow.com/a/3692961/11801882
	assert(calculated == expected && "you are WRONG!!");

	std::cout << "Good job! Fibonacci index " << index << " is " << calculated << std::endl;
	return 0;	
}
