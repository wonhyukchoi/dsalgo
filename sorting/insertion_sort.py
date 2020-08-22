#! /usr/bin/env python3

def swap(array: list, i: int, j: int) -> None:
	temp = array[i]
	array[i] = array[j]
	array[j] = temp


def insertion_sort(array: list) -> None:
	idx = 1
	# Can't use enumerate(array) b/c of index boundary
	while idx < len(array):
		value = array[idx]
		backwards_idx = idx - 1
		while array[backwards_idx] > value and backwards_idx >= 0:
			swap(array, backwards_idx, backwards_idx+1)
			backwards_idx -= 1
		idx += 1		


if __name__ == "__main__":
	example = [1, 0, 1, 2, 3, 4, 1, 2, 5, 234, 1, 12, 3, 2, 23, 12, 2, -5, 3, 4]

	print(f"Input: \n{example}")

	insertion_sort(example)
	print(f"Insertion Sort: \n{example}")
