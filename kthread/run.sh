#/bin/bash
for (( i=0; i<10000; i++ ))
do
    make insert
    make remove
done

