

for j in memcpy.csv memset.csv
do
    echo "" > $j
    i=0
    while [ $i -lt 1000 ]
    do
	echo $i
	./n >> $j
	let i=i+1
    done
done
