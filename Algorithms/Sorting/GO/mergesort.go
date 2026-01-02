package main

func merge(arr []int, start int, q int, end int) {

	lst1Length := q - start + 1
	lst2Length := end - q

	sublist1 := make([]int, lst1Length)
	sublist2 := make([]int, lst2Length)

	for i := range lst1Length {
		sublist1[i] = arr[start+i]
	}

	for i := range lst2Length {
		sublist2[i] = arr[q+1+i]
	}

	i := 0
	j := 0
	k := 0

	for {
		if sublist1[i] <= sublist2[j] {
			arr[start+k] = sublist1[i]
			i++
			k++
			if i == lst1Length {
				for j < lst2Length {
					arr[start+k] = sublist2[j]
					j++
					k++
				}
				break
			}
		} else {
			arr[start+k] = sublist2[j]
			j++
			k++
			if j == lst2Length {
				for i < lst1Length {
					arr[start+k] = sublist1[i]
					i++
					k++
				}
				break
			}
		}
	}
}

func sort(arr []int, start int, end int) {
	if start < end {
		mid := (start + end) / 2
		sort(arr, start, mid)
		sort(arr, mid+1, end)
		merge(arr, start, mid, end)
	}

}

func mergeSort(arr []int) {
	sort(arr, 0, len(arr)-1)
}
