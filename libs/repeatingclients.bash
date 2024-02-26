#!/bin/bash

for N in {1..20}
do 
    ./tcpclient 127.0.0.1 {"id":1,"jsonrpc":"2.0","method":"readfile","params":{"path":"/home/zyd/Documents/tst.txt"}}
done 
wait