// 每次从第一个开始，⽐较相邻的元素。如果第⼀个⽐第⼆个⼤，就交换他们两个
function bubbleSort(arr: number[]) {
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = 0; j < arr.length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
    }
}

// 每一次从待排序的数据元素中选出最小的⼀个元素，存放在序列的起始位置
function selectSort(arr: number[]) {
    for (let i = 0; i < arr.length - 1; i++) {
        let minIndex = i;
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    }
}

// 将⼀个数据插入到已经排好序的有序数据中，从而得到⼀个新的、个数加⼀的有序数据
function insertSort(arr: number[]) {
    for (let i = 1; i < arr.length; i++) {
        let current = arr[i];
        let j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

// 希尔排序是插入排序的改进版，它通过设置一个增量来分组排序，最后再进行一次插入排序
function shellSort(arr: number[]) {
    let gap = Math.floor(arr.length / 2);
    while (gap > 0) {
        for (let i = gap; i < arr.length; i++) {
            let current = arr[i];
            let j = i - gap;
            while (j >= 0 && arr[j] > current) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = current;
        }
        gap = Math.floor(gap / 2);
    }
}

function heapSort(arr: number[]) {

}


function mergeSort(arr: number[]) {

}

function quickSort(arr: number[]) {

}

function countSort(arr: number[]) {

}

function radixSort(arr: number[]) {

}

function bucketSort(arr: number[]) {

}

function stdSort(arr: number[]) {
    arr.sort((a, b) => a - b);
}

function generate(num: number): number[] {
    return Array.from({ length: num }, () => Math.floor(Math.random() * 1000000));
}

function isSorted(array: number[]): boolean {
    for (let i = 1; i < array.length; i++) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

function main() {
    const vFunc: Array<{ name: string, func: (array: number[]) => void }> = [
        { name: 'bubbleSort', func: bubbleSort },
        { name: 'selectSort', func: selectSort },
        { name: 'insertSort', func: insertSort },
        { name: 'shellSort', func: shellSort },
        { name: 'heapSort', func: heapSort },
        { name: 'mergeSort', func: mergeSort },
        { name: 'quickSort', func: quickSort },
        { name: 'countSort', func: countSort },
        { name: 'radixSort', func: radixSort },
        { name: 'bucketSort', func: bucketSort },
        { name: 'stdSort', func: stdSort },
    ];

    const originalArray = generate(10000);

    vFunc.forEach(({ name, func }) => {
        const array = [...originalArray];
        const start = performance.now();
        func(array);
        const end = performance.now();

        console.log(
            `${name.padStart(12)} ${(end - start).toFixed(3).padStart(15)} ${(isSorted(array) ? 'true' : 'false').padStart(8)}`
        );
    });
}

main();
