async function timeout(ms: number) {
    await new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
}

async function printAsync(str: string) {
    await timeout(1000)
    console.log(str)
    return 0
}

function print(str: string) {
    let code = printAsync(str)
    console.log(code)
}

print('hello world')
console.log('are you ok')
