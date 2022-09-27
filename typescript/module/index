import { A } from "./other"
import { A as ARef } from "./other"
// 导出整个模块赋予变量之上
import OtherRef = require("./other")

let a = new OtherRef.A()
let b = new A()
let c = new ARef()

/**
 * => B.print()
 * => B.print()
 * => B.print()
 */
a.print()
b.print()
c.print()

