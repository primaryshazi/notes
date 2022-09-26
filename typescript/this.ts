interface Wiget {
    onClickEvent(callback: (type: number) => void, caller: any, type: number): void
    onClickEvent2(callback: (this: void, type: number) => void, type: number): void
}

class Handler {
    name_: string = ''

    constructor(n: string) {
        this.name_ = n
    }

    dealClickStatic(type: number): void {
        console.log(this.name_ + ' deal click static ' + type)
    }

    dealClickDynamic = (type: number) => {
        console.log(this.name_ + ' deal click dyanmic ' + type)
    }

    dealClickBing(type: number): void {
        console.log(this.name_ + ' deal click bind ' + type)
    }
}

let windows: Wiget = {
    onClickEvent(callback: (type: number) => void, caller: any, type: number): void {
        callback.call(caller, type)
    },

    onClickEvent2(callback: (this: void, type: number) => void, type: number): void {
        callback(type)
    }
}

/**
 => handler deal click static 1024
 => handler deal click dyanmic 2048
 => handler deal click bind 4096
 */
let handler = new Handler('handler')
windows.onClickEvent(handler.dealClickStatic, handler, 1024)
windows.onClickEvent2(handler.dealClickDynamic, 2048)
windows.onClickEvent2(handler.dealClickBing.bind(handler), 4096)
