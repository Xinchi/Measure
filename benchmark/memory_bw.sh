#echo "" > bw_memcpy.log
#echo "" > bw_memset.log
echo "" > bw_charcpy.log
echo "" > bw_charset.log
echo "" > bw_longcpy.log
echo "" > bw_longset.log

run="1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536"

for i in $run
do
    echo $i
    echo "------------------------------------------ " >> bw_memcpy.log
    echo $i >> bw_memcpy.log
    python benchmark.py ../memory/bandwidth/run.py memcpy $i >> bw_memcpy.log
done

for i in $run
do
    echo $i
    echo "------------------------------------------ " >> bw_memset.log
    echo $i >> bw_memset.log
    python benchmark.py ../memory/bandwidth/run.py memset $i >> bw_memset.log
done

exit


for i in $run
do
    echo $i
    echo "------------------------------------------ " >> bw_charcpy.log
    echo $i >> bw_charcpy.log
    python benchmark.py ../memory/bandwidth/run.py charcpy $i >> bw_charcpy.log
done

for i in $run
do
    echo $i
    echo "------------------------------------------ " >> bw_charset.log
    echo $i >> bw_charset.log
   python benchmark.py ../memory/bandwidth/run.py charset $i >> bw_charset.log
done
for i in $run
do
    echo $i
    echo "------------------------------------------ " >> bw_longcpy.log
    echo $i >> bw_longcpy.log
    python benchmark.py ../memory/bandwidth/run.py intcpy $i >> bw_longcpy.log
done

for i in $run
do
    echo $i
    echo "------------------------------------------ " >> bw_longset.log
    echo $i >> bw_longset.log
    python benchmark.py ../memory/bandwidth/run.py intset $i >> bw_longset.log
done

exit

