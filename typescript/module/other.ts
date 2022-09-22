export class A {
    print(): void {
        this.b.print()
    }

    private b: B = new B()
}

class B {
    print(): void {
        console.log("B.print()")
    }
}
