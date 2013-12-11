s="0 60 100"
run="250 500 1000 2000 4000 8000"

for j in $s
do
    echo "swap******************************************************"
    echo $j
    echo $j > /proc/sys/vm/swappiness
    for i in $run
    do
	echo "---------------------------------------------------"
	echo $i
	bash clean.sh
	./r $i
    done
done
