package main

import (
	"fmt"
	"math/rand"
	"os"
	"slices"
	"strconv"
	"strings"
)

// Cause GO doesn't have ENUMS as a language feature, so we existing constructs to acheive similar behaviour as enums :)
type SortAlgo int

const (
	QuickSort SortAlgo = iota
	MergeSort
)

var sortNameMap = map[string]SortAlgo{
	"quicksort": QuickSort,
	"mergesort": MergeSort,
}

func validateCmdLineArgs() {
	argsWithoutProg := os.Args[1:]

	availableSortAlgos := make([]string, 0, len(sortNameMap))

	for sa := range sortNameMap {
		availableSortAlgos = append(availableSortAlgos, sa)
	}

	// Validate if we have correct number of args
	if len(argsWithoutProg) < 2 {
		fmt.Println("Usage:  go run sort.go <sort-algo> <array-size>\n Available SortAlgo: ", availableSortAlgos)
		os.Exit(1)
	}

	if !slices.Contains(availableSortAlgos, strings.ToLower(argsWithoutProg[0])) {
		fmt.Println("Invalid sorting algorithm: ", argsWithoutProg[0])
		os.Exit(1)
	}
}

func generateRandomInts(size int, min int, max int) []int {
	arr := make([]int, size)

	for i := range size {
		arr[i] = rand.Intn(max-min+1) + min
	}

	return arr
}

func sortArray(sort string, arr []int) {
	algo := sortNameMap[strings.ToLower(sort)]
	fmt.Printf("===== Sorting array using %v =========\n", sort)
	switch algo {
	case QuickSort:
		quickSort(arr)
	case MergeSort:
		mergeSort(arr)
	default:
		fmt.Println("Invalid sorting algorithm: ", algo)
		os.Exit(1)
	}
}

func main() {
	// Validate input
	validateCmdLineArgs()

	argsWithoutProg := os.Args[1:]

	arrSize, err := strconv.Atoi(argsWithoutProg[1])
	sortAlgo := argsWithoutProg[0]

	if err != nil {
		fmt.Printf("Invalid input: %s \n %s", argsWithoutProg[1], err)
		os.Exit(1)
	}

	if arrSize < 0 {
		fmt.Printf("Size should be positive. Provided: %d \n", arrSize)
		os.Exit(1)
	}

	// Generate a random number array
	arr := generateRandomInts(arrSize, 1, 1000)

	fmt.Println("Array size: ", arrSize)
	fmt.Println("Array before sort: ", arr)

	// Apply selected sort
	sortArray(sortAlgo, arr)

	fmt.Println("Array size: ", arrSize)
	fmt.Println("Array after sort: ", arr)
}
