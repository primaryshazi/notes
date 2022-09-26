class ClassA {
    x: number = 0

    constructor(v: number) {
        this.x = v
    }

    print(): void {
        console.log(this.constructor.name + ' => ' + this.x)
    }
}

interface InterfaceB {
    y: number
    print(): void
}

// 接口继承类
interface ICA extends ClassA {
}

// 类实现接口
class CIB implements InterfaceB {
    y: number = 0

    constructor(v: number) {
        this.y = v
    }

    print() {
        console.log(this.constructor.name + ' => ' + this.y)
    }
}

// 类继承类
class CCA extends ClassA {
    constructor(v: number) {
        super(v)
    }
}

class C {
    static S_STATIC_VALUE: string = 'nothing'

    constructor(i: number, j: number, k: number) {
        this.x = i
        this.y = j
        this.z = k
    }

    public x: number = 0

    public print(): void {
        this.print2()
    }

    protected y: number = 0
    protected print2(): void {
        this.print3()
    }

    private z: number = 0
    private print3(): void {
        console.log(this.constructor.name + ' => ' + this.x, this.y, this.z)
    }
}

let v1: ICA = {
    x: 1024,
    print: function (): void {
        console.log(this.constructor.name + ' => ' + this.x)
    }
}

let v2 = new CIB(2048)

let v3 = new CCA(4096)

let v4 = new C(2, 4, 8)

/**
 * => Object => 1024
 * => CIB => 2048
 * => CCA => 4096
 * C => 2 4 8
 */
v1.print()
v2.print()
v3.print()
v4.print()
