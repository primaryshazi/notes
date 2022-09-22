function doNothing(): number {
    return 0
}

function oneArguemnt(i: number): number {
    return i;
}

function optionalArgument(i: number, j?: number): number {
    return j ? i + j : i;
}

function defaultArgument(i: number, j: number = 0): number {
    return i + j
}

function variableArgument(i: number, ...arr: number[]): number {
    let total: number = i

    for (let n of arr) {
        total += n
    }

    return total
}

/**
 * => 0
 * => 1
 * => 1
 * => 3
 * => 6
 */
console.log(doNothing())
console.log(oneArguemnt(1))
console.log(optionalArgument(1))
console.log(defaultArgument(1, 2))
console.log(variableArgument(1, 2, 3))
