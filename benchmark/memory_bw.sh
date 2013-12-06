
run="charwrite intwrite longwrite charread intread longread"
for i in $run
do
    echo $i
    python benchmark.py ../memory/bandwidth/run.py $i > bw_mem_$i.csv
done


