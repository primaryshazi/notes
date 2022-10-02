/**
 * extends: 只需要实现父类中的抽象函数
 * implements: 需要实现父类中所有的函数
 */

abstract class AbsClassBase {
    show() {
    }

    abstract print(): void

    public member_: any = null
}

class ClassBase {
    constructor() {
    }

    show() {
    }

    print(): void {
    }

    public member_: any = null
}

class ClassDerive_1 extends AbsClassBase {
    print(): void {
    }
}

class ClassDerive_2 implements AbsClassBase {
    show(): void {
    }

    print(): void {
    }

    public member_: any = null
}


class ClassDerive_3 extends ClassBase {
    func(): void {
        super.show()
        super.print()
    }
}

class ClassDerive_4 implements ClassBase {
    show(): void {
    }

    print(): void {
    }

    public member_: any = null
}

interface InterfaceM_1 extends ClassBase {
}
