const classDecorator: ClassDecorator = (target: Object) => {
    console.log(`classDecorator => target:${target.constructor.name}`)
}

const classDecoratorWithParamter = (str: string) => {
    return (target: Object) => {
        console.log(`classDecoratorWithParamter => target:${target.constructor.name} str:${str}`)
    };
}

const propertyDecorator: PropertyDecorator = (target: Object, propertyName: string | symbol) => {
    console.log(`propertyDecorator => target:${target.constructor.name} propertyName:${propertyName?.toString()}`)
}

const methodDecorator: MethodDecorator = (target: Object, methodName: string | symbol, descriptor: PropertyDescriptor) => {
    console.log(`methodDecorator => target:${target.constructor.name} methodName:${methodName?.toString()} descriptor:${descriptor}`)
}

const parameterDecorator: ParameterDecorator = (target: Object, parameterName: string | symbol | undefined, parameterIndex: number) => {
    console.log(`parameterDecorator => target:${target.constructor.name} parameterName:${parameterName?.toString()} parameterIndex:${parameterIndex}`)
}

@classDecorator
@classDecoratorWithParamter("ok")
class Nothing {
    set(@parameterDecorator id: number) {
        this.id_ = id
    }

    @methodDecorator
    get() {
        return this.id_
    }

    @propertyDecorator
    private id_: number = 0
}

function main() {
    /**
     * => parameterDecorator => target:Nothing parameterName:set parameterIndex:0
     * => methodDecorator => target:Nothing methodName:get descriptor:[object Object]
     * => propertyDecorator => target:Nothing propertyName:id_
     * => classDecoratorWithParamter => target:Nothing str:ok
     * => classDecorator => target:Nothing
     * => 1024
     */
    const nothing = new Nothing();
    nothing.set(1024);
    console.log(nothing.get());
}

main()
