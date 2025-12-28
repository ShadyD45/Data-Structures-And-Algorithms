package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
)

func partition(inputList []int, start int, end int) int {
	pivot := inputList[end]
	i := start - 1
	j := start

	for j < end {
		if inputList[j] <= pivot {
			i++
			inputList[i], inputList[j] = inputList[j], inputList[i]
		}
		j++
	}

	inputList[end], inputList[i+1] = inputList[i+1], inputList[end]

	return i + 1
}

func quickSort(arr []int) {
	if len(arr) < 2 {
		return
	}

	pivot := partition(arr, 0, len(arr)-1)
	quickSort(arr[:pivot])
	quickSort(arr[pivot+1:])
}

func generateRandomInts(size int, min, max int) []int {
	arr := make([]int, size)

	for i := range size {
		arr[i] = rand.Intn(max-min+1) + min
	}

	return arr
}

func main() {
	argsWithoutProg := os.Args[1:]

	if len(argsWithoutProg) == 0 {
		fmt.Println("Usage: go run main.go <array-size>")
		os.Exit(1)
	}

	inputSize, err := strconv.Atoi(argsWithoutProg[0])

	if err != nil {
		fmt.Println("Invalid input size: ", err)
		os.Exit(1)
	}

	arr := generateRandomInts(inputSize, 1, 1000)

	fmt.Printf("Input array size: %d\n", inputSize)
	fmt.Println("Input array before sort: ", arr)

	// Sort
	quickSort(arr)

	fmt.Printf("Input array size: %d \n", inputSize)
	fmt.Println("Input array after sort: ", arr)
}
