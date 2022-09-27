import fs_extra_mgr = require('fs-extra')
import path_mgr = require('path')

const G_FILE_NAME = path_mgr.join(`${__dirname}`, 'nothing.json')

interface Other {
    arg: any
}

interface Person {
    name: string
    age: number
    isAlive: boolean
    list: number[]
    other: Other
}

function write_json() {
    let one: Person = {
        name: 'one',
        age: 1,
        isAlive: true,
        list: [1, 2, 3],
        other: { arg: null }
    }

    fs_extra_mgr.writeJsonSync(G_FILE_NAME, one, { encoding: 'utf-8', mode: 0o666, flag: 'w+', spaces: '  ' })
}

function read_json() {
    if (fs_extra_mgr.existsSync(G_FILE_NAME)) {
        let one: Person = fs_extra_mgr.readJsonSync(G_FILE_NAME, { encoding: 'utf-8', flag: 'r+' })
        console.log(JSON.stringify(one, undefined, '  '))
        fs_extra_mgr.unlinkSync(G_FILE_NAME)
    }
}

write_json()
read_json()
