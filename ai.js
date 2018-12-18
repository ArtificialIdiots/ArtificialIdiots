#!/usr/bin/env node

const readline = require('readline')

const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
        terminal: true
})

rl.setPrompt('>> ')

const close = (newline) => {
        console.log(`${newline ? '' : '\n'}再见我的朋友！`)
        process.exit(0)
}

const reply = (line) => {
        switch(true) {
                case /再见/.test(line):
                        close(true)
                        break
                case /(你|大家)好/.test(line):
                        console.log(Math.random() > 0.5 ? '你好！' : '大家好！')
                        break
                default:
                        console.log(line.replace(/\?|？/ig, '！').replace(/吗/ig, Math.random() > 0.2 ? '' : '呀').replace(/你/ig, Math.random() > 0.5 ? '' : '我'))
        }

        rl.prompt()
}

console.log('你好我的朋友！')
rl.prompt()

rl.on('line', reply).on('close', close)
