var v1 = {
    i: 0,
    str: "",
    func: function () { }
}
v1.i = 1024;
v1.str = "hello world"
v1.func = function () { console.log(this.i, this.str) }

var v2 = {
    x: 0,
    y: 0
}
v2.x = 2048
v2.y = 4096

function func(obj: { x: number, y: number }) {
    console.log(obj.x, obj.y)
}

type Value = {
    n: number
    s: string,
    func(): void
}
let v3: Value = {
    n: 999,
    s: "999",
    func: function (): void {
        console.log(this.n, this.s)
    }
}

/**
 * => 1024 hello world
 * => 2048 4096
 * => 999 999
 */
v1.func()
func(v2)
v3.func()
