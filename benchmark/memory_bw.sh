echo "" > bw_memcpy.log
echo "" > bw_memset.log
echo "" > bw_charcpy.log
echo "" > bw_charset.log

run="1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192"
charrun="1024 2048 4096 8192"
for i in $run
do
    echo $i
    python benchmark.py ../memory/bandwidth/run.py memcpy $i >> bw_memcpy.log
done

for i in $run
do
    echo $i
    python benchmark.py ../memory/bandwidth/run.py memset $i >> bw_memset.log
done

for i in $charrun
do
    echo $i
    python benchmark.py ../memory/bandwidth/run.py charcpy $i >> bw_charcpy.log
done

for i in $charrun
do
    echo $i
    python benchmark.py ../memory/bandwidth/run.py charset $i >> bw_charset.log
done
