# !/bin/sh

Iter=5
Size=( 50 100 150 200 250 )

Output_File="results.csv"

Names=( "TTM_DP" "TTM_J" "TTM_UT" "THP_DP" "THP_I" "THP_J" "MTTKRP_IJ" "MTTKRP_I" "MTTKRP_J" )

echo -n "size," > $Output_File

for name in ${Names[@]}
do
    echo -n "$name," >> $Output_File
    c++ "$name.cpp" -g -std=c++17 -O3 -ffast-math -pthread -mtune=native -Wno-narrowing -ftree-vectorize -mavx2 -o $name
done
echo "" >> $Output_File

for size in ${Size[@]}
do
    echo -n "$size," >> $Output_File
    
    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./TTM_DP $size $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./TTM_J $size $size $size $size 1)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./TTM_UT $size $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File



    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./THP_DP $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./THP_I $size $size $size 1)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./THP_J $size $size $size 1)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File



    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./MTTKRP_IJ $size $size $size $size 1 1)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./MTTKRP_I $size $size $size $size 1)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$(./MTTKRP_J $size $size $size $size 1)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File



    echo $size

    echo  "" >> $Output_File

done


