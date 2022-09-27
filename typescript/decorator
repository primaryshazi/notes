const classDecorator: ClassDecorator = (target: any) => {
    console.log(target.name)
}

const classDecorator2 = (str: string) => {
    return (target: any) => {
        console.log(target.name, str)
    };
}

const propertyDecorator: PropertyDecorator = (target: any, propertyName: string | symbol) => {
    console.log(target.name, propertyName)
}

const methodDecorator: MethodDecorator = (target: any, methodName: string | symbol) => {
    console.log(target.name, methodName)
}

const parameterDecorator: ParameterDecorator = (target: any, parameterName: string | symbol, parameterIndex: number) => {
    console.log(target.name, parameterName, parameterIndex)
}

// 待修改
const promiseConstructor = (target: any, propertyName: string, descriptor: PropertyDescriptor) => {
    console.log(target.name, propertyName, descriptor)
}

@classDecorator
@classDecorator2("ok")
class Nothing {

    @methodDecorator
    do() {
    }

    set(@parameterDecorator id: number) {
        this.id_ = id
    }

    // @promiseConstructor
    get() {
        return this.id_
    }

    @propertyDecorator
    private id_: number = 0
}
