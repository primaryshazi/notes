/**
 * *: 表示生成器
 * yield: 表示发送值给使用方
 */
function* generator(seed: number) {
    let n: number = seed
    // 不会陷入死循环，调用时才会继续循环
    while (true) {
        n = (n * 1103515245 + 12345) % 32768
        yield n
    }
}

let gen = generator(1024)
for (let i = 0; i < 10; i++) {
    console.log(gen.next().value)
}
