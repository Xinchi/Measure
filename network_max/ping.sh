#!/bin/bash
intertube=0
echo "begin ping"
while [ $intertube -ne 1 ]; do
        ping -c 3 196.128.54.10
        if [ $? -eq  0 ]; then
                echo "ping success";
                say success
                intertube=1;
        else
                echo "fail ping"
        fi
done
echo "fin script"
