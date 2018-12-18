#!/usr/bin/env python3
import random
import re

if __name__ == '__main__':
    print('你好我的朋友！')
    while True:
        line = input('>>> ')
        if not line:
            continue
        if re.search(r'再见', line):
            break
        elif re.search(r'(你|大家)好', line):
            print(random.choice(['你好！', '大家好！']))
        else:
            line = re.sub(r'\?|？', '！', line)
            line = re.sub(r'吗', '' if random.random() > 0.2 else '呀', line)
            line = re.sub(r'你', random.choice(['', '我']), line)
            print(line)
    print('再见我的朋友！')
