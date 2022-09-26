namespace A {
    export class X {
        print(): void {
            console.log('A.X.print()')
        }
    }

    export namespace B {
        export function print() {
            console.log('A.B.print()')
        }
    }
}

let a = new A.X()

/**
 * => A::X::print()
 * => A::B::print()
 */
a.print()
A.B.print()
