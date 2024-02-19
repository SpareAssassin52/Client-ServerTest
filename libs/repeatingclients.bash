#!/bin/bash

for N in {1..50}
do 
    ./tcpclient 127.0.0.1 ~/Documents/test.txt
done 
wait