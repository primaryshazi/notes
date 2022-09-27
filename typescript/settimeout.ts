setTimeout(() => {
    console.log('hello world')
}, 3000)

setTimeout((str: string) => {
    console.log(str)
}, 3000, 'hello world');
