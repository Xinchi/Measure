run="1 2 4 8 16 32"
size=500

for i in $run
do
    echo $i
    bash clean.sh
    ./Tao_file $size $i | grep lantecy > $i.log
done

