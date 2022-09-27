import fs_mgr = require('fs')
import path_mgr = require('path')

const G_FILE_NAME = path_mgr.join(`${__dirname}`, 'nothing.txt')

function read_file_list() {
    let cur_path = path_mgr.resolve(`${__dirname}`)
    let file_list = fs_mgr.readdirSync(cur_path)
    for (let file of file_list) {
        let path = path_mgr.join(`${__dirname}`, file)
        let stat = fs_mgr.statSync(path)
        if (stat.isDirectory()) {
            console.log('%s is directory', path)
        } else if (stat.isFile()) {
            console.log('%s is file', path)
        } else {
            console.log('%s is other', path)
        }
    }
}

function write_file() {
    fs_mgr.writeFileSync(G_FILE_NAME, 'hello world\n', { encoding: 'utf-8', mode: 0o666, flag: 'w+' })
    fs_mgr.appendFileSync(G_FILE_NAME, 'are you ok\n', { encoding: 'utf-8', mode: 0o666, flag: 'a+' })
}

function read_file() {
    if (fs_mgr.existsSync(G_FILE_NAME)) {
        let str = fs_mgr.readFileSync(G_FILE_NAME, { encoding: 'utf-8', flag: 'r+' })
        console.log(str)
        fs_mgr.unlinkSync(G_FILE_NAME)
    }
}

function write_read_file() {
    let writefd = fs_mgr.openSync(G_FILE_NAME, 'w+', 0o666)
    fs_mgr.writeSync(writefd, 'hello world', 0, 'utf-8')
    fs_mgr.closeSync(writefd)

    let buf = Buffer.alloc(64)
    let readfd = fs_mgr.openSync(G_FILE_NAME, 'r+', 0o666)
    fs_mgr.readSync(readfd, buf, { offset: 0, length: buf.length, position: 0 })
    fs_mgr.closeSync(readfd)
    console.log(buf.toLocaleString())

    fs_mgr.unlinkSync(G_FILE_NAME)
}

read_file_list()
write_file()
read_file()
write_read_file()
