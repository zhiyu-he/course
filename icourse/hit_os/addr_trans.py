# -*- coding: utf-8 -*-

import sys

hint_msg = '-h show help\n -b hex2cap e.g. -b0x7c00 output: 31KB'

if __name__ == '__main__':
    if len(sys.argv) == 1:
        print hint_msg
        exit(0)
    print "%s" % sys.argv

