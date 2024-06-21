# !bin/bash

cd ..
# names1=("TTM_DP")
# names2=("TTM_J" "MTTKRP_I" "MTTKRP_J")
names2=("MTTKRP_I" "MTTKRP_J")
# names3=("THP_DP")
# names4=("THP_I" "THP_J")
names5=("MTTKRP_IJ")


Iter=5
Size=( 50 100 150 200 250 400 )
results_path="results/cVScpp"
mkdir -p $results_path



for name in ${names2[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,C_no_cm,C_CM,C_sparse_no_cm,C_sparse_CM,CPP_no_cm,CPP_cm,CPP_sparse_no_cm,CPP_sparse_cm" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_no_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_Sparse_no_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_Sparse_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_no_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse_no_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse_cm" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File   
  done
done





for name in ${names5[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,C_no_cm,C_CM,C_sparse_no_cm,C_sparse_CM,CPP_no_cm,CPP_cm,CPP_sparse_no_cm,CPP_sparse_cm" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_no_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_Sparse_no_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_c/${name}_Sparse_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_no_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse_no_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse_cm" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File   
  done
done







