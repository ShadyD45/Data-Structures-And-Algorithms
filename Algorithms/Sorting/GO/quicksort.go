package main

func partition(inputArr []int, start int, end int) int {
	pivot := inputArr[end] // Select last element as pivot
	i := start - 1
	j := start

	for j < end {
		if inputArr[j] <= pivot {
			i++
			inputArr[i], inputArr[j] = inputArr[j], inputArr[i]
		}
		j++
	}

	inputArr[end], inputArr[i+1] = inputArr[i+1], inputArr[end]

	return i + 1 // Return the position of pivot
}

func quickSort(arr []int) {
	if len(arr) < 2 {
		return
	}

	pivot := partition(arr, 0, len(arr)-1)
	quickSort(arr[:pivot])
	quickSort(arr[pivot+1:])
}
