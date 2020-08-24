#! /usr/bin/env python
""" I was going to implement this in `C++`, 
    but this algorithm is on the front page of Python website. (really!)
    So, much like my Haskell quicksort implementation,
    I feel obliged to include this bottom-up fibonacci memoization example."""

def fibonacci(n: int) -> int:
	a = 0
	b = 1
	for _ in range(n-1):
		a,b = b,a+b
	return b
	

if __name__ == "__main__":
	index = 0x2f
	expected = 2971215073
	calculated = fibonacci(index)
		
	assert expected == calculated, "YOU ARE WRONG!"
	print(f"Hurray! Fibonacci index {index} is {calculated}!")

