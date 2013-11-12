#/bin/bash

run="64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608 16777216"

size="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20"

for i in $run
do
    echo "test".$i
    echo "" > $i.log
    for j in $size
    do
	./mem $i $j >> $i.log
	echo "size=".$j
    done
    echo "done_test".$i
done



