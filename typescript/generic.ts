interface InterfaceGeneric<T> {
    t: T                // 成员
    func<T>(t: T): T    // 方法
}

class ClassGeneric<T> {
    constructor(t: T) {
        this.t = t
    }

    func(): T {
        return this.t
    }

    print<X>(x: X) {
        console.log(this.func(), x)
    }

    private t: T
}

function funcGeneric<T>(t: T) {
    return t
}

// 约束T类型
class ExtendsGeneric<T extends number> {
    func(t: T): T {
        return t
    }
}

// 以类型参数约束另一个类型参数
function keyOfGeneric<A, K extends keyof A>(arr: A, key: K) {
    return arr[key]
}

// 类工厂
function create<T, X>(construct: { new(x: X): T; }, x: X) {
    return new construct(x)
}

let a: InterfaceGeneric<number> = {
    t: 1024,
    func<T>(t: T): T {
        return t
    }
}

let b = new ClassGeneric<number>(2048)

let c = funcGeneric<number>(4096)

let d = new ExtendsGeneric<number>().func(8192)

let e = keyOfGeneric({ x: 16384, y: 32768 }, 'x')

let f = create(Number, 65536)

/**
 * => 1024
 * => 2048
 * => 4096
 * => 8192
 * => 16384
 * => 65536
 */
console.log(a.func(a.t))
console.log(b.func())
console.log(c)
console.log(d)
console.log(e)
console.log(f.valueOf())
