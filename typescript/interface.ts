/**
 * interface: 着重描述数据结构
 * type: 着重描述类型
 */

interface InterfaceNum {
    readonly x: number
}

interface InterfaceFunc {
    print(...argv: any[]): void
}

interface InterfaceAny extends InterfaceNum, InterfaceFunc {
}

let num: InterfaceNum = {
    x: 1024
}

let func: InterfaceFunc = {
    print: function (...argv: any[]): void {
        console.log(argv.join(' '))
    }
}

let num_func: InterfaceAny = {
    x: 2048,
    print: function (...argv: any[]): void {
        argv.push(this.x)
        console.log(argv.join(' '))
    }
}

/**
 * => 1024
 * => 2048
 */
func.print(num.x)
num_func.print()
