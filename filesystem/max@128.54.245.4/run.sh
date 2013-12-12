
run="20 40 80 160 320 640"
echo "---------------------------------------------------"
echo "sequencial read"
echo "---------------------------------------------------"
for i in $run
do
    echo $i
    bash clean.sh
    ./r $i 0
done

echo "---------------------------------------------------"
echo "random read"
echo "---------------------------------------------------"
for i in $run
do
    echo $i
    bash clean.sh
    ./r $i 1
done

