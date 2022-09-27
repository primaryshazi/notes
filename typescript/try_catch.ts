function func() {
    throw new Error('this is exception')
}

try {
    func()
} catch (err) {
    let e = err as Error
    console.log(e.name, e.message)
}
