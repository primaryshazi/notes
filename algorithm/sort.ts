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

// 堆排序是将数组看作一棵完全二叉树，将树调整为堆，然后依次将堆顶元素与末尾元素交换，再调整堆
function heapSort(arr: number[]) {
    const length = arr.length;

    const buildHeap = (arr: number[], length: number, index: number): void => {
        let father = index;
        const left = 2 * index + 1;
        const right = 2 * index + 2;

        if (left < length && arr[left] > arr[father]) {
            father = left;
        }

        if (right < length && arr[right] > arr[father]) {
            father = right;
        }

        if (father !== index) {
            [arr[index], arr[father]] = [arr[father], arr[index]];
            buildHeap(arr, length, father);
        }
    };

    for (let i = Math.floor(length / 2) - 1; i >= 0; i--) {
        buildHeap(arr, length, i);
    }

    for (let i = length - 1; i >= 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        buildHeap(arr, i, 0);
    }
}

// 归并排序是将数组分成两部分，然后对两部分进行排序，最后将两部分合并
function mergeSort(arr: number[]) {
    const length = arr.length;
    const tmpArr = new Array(length);

    const merge = (arr: number[], left: number, mid: number, right: number): void => {
        let i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                tmpArr[k] = arr[i];
                i++;
            } else {
                tmpArr[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            tmpArr[k] = arr[i];
            i++;
            k++;
        }

        while (j <= right) {
            tmpArr[k] = arr[j];
            j++;
            k++;
        }

        for (k = 0; left <= right;) {
            arr[left] = tmpArr[k];
            left++;
            k++;
        }
    };

    const mgSort = (arr: number[], left: number, right: number): void => {
        if (left < right) {
            const mid = left + ((right - left) >> 1);
            mgSort(arr, left, mid);
            mgSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    };

    mgSort(arr, 0, length - 1);
}

// 快速排序是选择一个基准元素，将数组分成两部分，一部分比基准元素小，一部分比基准元素大，然后递归地对两部分进行排序
function quickSort(arr: number[]) {
    const length = arr.length;

    const partition = (arr: number[], left: number, right: number): number => {
        const random = Math.floor(Math.random() * (right - left + 1)) + left;
        [arr[right], arr[random]] = [arr[random], arr[right]];

        const standard = arr[right];
        let index = left;

        for (let i = left; i < right; i++) {
            if (arr[i] < standard) {
                [arr[i], arr[index]] = [arr[index], arr[i]];
                index++;
            }
        }
        [arr[index], arr[right]] = [arr[right], arr[index]];

        return index;
    };

    const qcSort = (arr: number[], left: number, right: number): void => {
        if (left < right) {
            const index = partition(arr, left, right);
            qcSort(arr, left, index - 1);
            qcSort(arr, index + 1, right);
        }
    };

    qcSort(arr, 0, length - 1);
}

// 计数排序是将数组中的元素作为键存储在额外开辟的数组空间中，然后依次将键值对中的元素放回原数组
function countSort(arr: number[]) {
    const length = arr.length;
    if (length < 2) {
        return;
    }

    let max = arr[0];
    for (let i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    const tmpArr = new Array(max + 1).fill(0);
    for (const num of arr) {
        tmpArr[num]++;
    }

    let index = 0;
    for (let i = 0; i < tmpArr.length; i++) {
        const count = tmpArr[i];
        for (let j = 0; j < count; j++) {
            arr[index] = i;
            index++;
        }
    }
}

// 基数排序是根据元素的每一位进行排序，从低位到高位依次排序
function radixSort(arr: number[]) {
    const length = arr.length;
    if (length < 2) {
        return;
    }

    let max = arr[0];
    for (let i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    const digit = Math.floor(Math.log10(max)) + 1;
    const radix: number[][] = Array.from({ length: 10 }, () => []);

    for (let d = 0; d < digit; d++) {
        for (const num of arr) {
            const ratio = Math.pow(10, d);
            const index = Math.floor(num / ratio) % 10;
            radix[index].push(num);
        }

        let index = 0;
        for (let i = 0; i < radix.length; i++) {
            for (const num of radix[i]) {
                arr[index] = num;
                index++;
            }
            radix[i] = [];
        }
    }
}

// 桶排序是根据元素的值将元素分配到不同的桶中，然后对每个桶进行排序，最后将桶中的元素依次放回原数组
function bucketSort(arr: number[]) {
    const length = arr.length;
    if (length < 2) {
        return;
    }

    let max = arr[0];
    let min = arr[0];
    for (let i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    const bucketSize = Math.floor((max - min) / length) + 1;
    const bucket: number[][] = Array.from({ length: bucketSize }, () => []);

    for (const num of arr) {
        const index = Math.floor((num - min) / length);
        bucket[index].push(num);
    }

    for (let i = 0; i < bucket.length; i++) {
        bucket[i].sort((a, b) => a - b);
    }

    let index = 0;
    for (const b of bucket) {
        for (const num of b) {
            arr[index] = num;
            index++;
        }
    }
}

// 标准排序
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
