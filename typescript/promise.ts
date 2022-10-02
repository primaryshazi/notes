class DoSomething {
    do(t: string): Promise<string> {
        return new Promise<string>((resolve, reject) => {
            if (t === 'success') {
                resolve(t)
            } else {
                reject('fail')
            }
        })
    }
}

let pro = new DoSomething()
pro.do('success').then(resolveArg => {
    console.log('resove:', resolveArg)
}, rejectArg => {
    console.log('reject', rejectArg)
}).catch(reason => {
    console.log('catch:', reason)
}).finally(() => {
    console.log('finally')
})
