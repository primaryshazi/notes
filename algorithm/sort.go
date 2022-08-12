package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"time"
)

type sortFunc func([]int)

func generate(length int) []int {
	rand.Seed(1024)
	arr := make([]int, length)

	for i := 0; i < length; i++ {
		arr[i] = rand.Intn(10000)
	}

	return arr
}

func bubbleSort(arr []int) {
	length := len(arr)
	for i := 0; i < length; i++ {
		for j := 0; j < length-i-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
}

func selectSort(arr []int) {
	length := len(arr)
	for i := 0; i < length; i++ {
		index := i
		for j := i + 1; j < length; j++ {
			if arr[j] < arr[index] {
				index = j
			}
		}
		if i != index {
			arr[i], arr[index] = arr[index], arr[i]
		}
	}
}

func insertSort(arr []int) {
	length := len(arr)
	for i := 0; i < length; i++ {
		tmp := arr[i]
		j := i

		for j > 0 && arr[j-1] > tmp {
			arr[j] = arr[j-1]
			j--
		}

		arr[j] = tmp
	}
}

func shellSort(arr []int) {
	length := len(arr)
	for span := length / 2; span > 0; span /= 2 {
		for i := 0; i < length; i += span {
			tmp := arr[i]
			j := i

			for j >= span && arr[j-span] > tmp {
				arr[j] = arr[j-span]
				j -= span
			}

			arr[j] = tmp
		}
	}
}

func heapSort(arr []int) {
	length := len(arr)

	var buildHeap func([]int, int, int)

	buildHeap = func(arr []int, length int, index int) {
		father := index
		left := 2*index + 1
		right := 2*index + 2

		if left < length && arr[left] > arr[father] {
			father = left
		}

		if right < length && arr[right] > arr[father] {
			father = right
		}

		if father != index {
			arr[index], arr[father] = arr[father], arr[index]
			buildHeap(arr, length, father)
		}
	}

	for i := length - 1; i >= 0; i-- {
		buildHeap(arr, length, i)
	}

	for i := length - 1; i >= 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		buildHeap(arr, i, 0)
	}
}

func mergeSort(arr []int) {
	length := len(arr)

	var merge func([]int, int, int, int)
	var mgSort func([]int, int, int)
	tmpArr := make([]int, length)

	merge = func(arr []int, left, mid, right int) {
		i, j, k := left, mid+1, 0

		for i <= mid && j <= right {
			if arr[i] <= arr[j] {
				tmpArr[k] = arr[i]
				i++
			} else {
				tmpArr[k] = arr[j]
				j++
			}
			k++
		}

		for i <= mid {
			tmpArr[k] = arr[i]
			i++
			k++
		}

		for j <= right {
			tmpArr[k] = arr[j]
			j++
			k++
		}

		for k = 0; left <= right; {
			arr[left] = tmpArr[k]
			left++
			k++
		}
	}

	mgSort = func(arr []int, left, right int) {
		if left < right {
			mid := left + ((right - left) >> 1)
			mgSort(arr, left, mid)
			mgSort(arr, mid+1, right)
			merge(arr, left, mid, right)
		}
	}

	mgSort(arr, 0, length-1)
}

func quickSort(arr []int) {
	length := len(arr)

	var partition func([]int, int, int) int
	var qcSort func([]int, int, int)

	partition = func(arr []int, left, right int) int {
		random := rand.Intn(right+1)%(right-left+1) + left
		arr[right], arr[random] = arr[random], arr[right]

		standard := arr[right]
		index := left

		for i := left; i < right; i++ {
			if arr[i] < standard {
				arr[i], arr[index] = arr[index], arr[i]
				index++
			}
		}
		arr[index], arr[right] = arr[right], arr[index]

		return index
	}

	qcSort = func(arr []int, left, right int) {
		if left < right {
			index := partition(arr, left, right)
			qcSort(arr, left, index-1)
			qcSort(arr, index+1, right)
		}
	}

	qcSort(arr, 0, length-1)
}

func countSort(arr []int) {
	length := len(arr)
	if length < 2 {
		return
	}

	max := arr[0]
	for i := 1; i < length; i++ {
		if arr[i] > max {
			max = arr[i]
		}
	}

	tmpArr := make([]int, max+1)
	for _, i := range arr {
		tmpArr[i]++
	}

	index := 0
	for i, count := range tmpArr {
		for j := 0; j < count; j++ {
			arr[index] = i
			index++
		}
	}
}

func radixSort(arr []int) {
	length := len(arr)
	if length < 2 {
		return
	}

	max := arr[0]
	for i := 1; i < length; i++ {
		if arr[i] > max {
			max = arr[i]
		}
	}

	digit := int(math.Floor(math.Log10(float64(max))) + 1)
	radix := make([][]int, 10)

	for d := 0; d < digit; d++ {
		for _, i := range arr {
			ratio := int(math.Pow10(d))
			index := i % (ratio * 10) / ratio
			radix[index] = append(radix[index], i)
		}

		index := 0
		for i, m := range radix {
			for _, n := range m {
				arr[index] = n
				index++
			}
			radix[i] = []int{}
		}
	}
}

func bucketSort(arr []int) {
	length := len(arr)
	if length < 2 {
		return
	}

	max := arr[0]
	min := arr[0]
	for i := 1; i < length; i++ {
		if arr[i] > max {
			max = arr[i]
		} else if arr[i] < min {
			min = arr[i]
		}
	}

	bucketSize := (max-min)/length + 1
	bucket := make([][]int, bucketSize)

	for _, i := range arr {
		index := (i - min) / length
		bucket[index] = append(bucket[index], i)
	}

	for index := range bucket {
		sort.Ints(bucket[index])
	}

	index := 0
	for _, m := range bucket {
		for _, n := range m {
			arr[index] = n
			index++
		}
	}
}

func main() {
	sorts := make(map[string]sortFunc)

	sorts["bubbleSort"] = bubbleSort
	sorts["selectSort"] = selectSort
	sorts["insertSort"] = insertSort
	sorts["shellSort"] = shellSort
	sorts["heapSort"] = heapSort
	sorts["mergeSort"] = mergeSort
	sorts["quickSort"] = quickSort
	sorts["countSort"] = countSort
	sorts["radixSort"] = radixSort
	sorts["bucketSort"] = bucketSort

	for k, v := range sorts {
		arr := generate(50000)
		start := time.Now().UnixNano()
		v(arr)
		end := time.Now().UnixNano()
		fmt.Printf("%10s %6.6f\n", k, float64(end-start)/1000000)
	}
}
