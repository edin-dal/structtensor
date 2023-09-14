# !bin/bash

cd ..
names1=("TTM_DP")
names2=("TTM_J" "MTTKRP_I" "MTTKRP_J")
names3=("THP_DP")
names4=("THP_I" "THP_J")
names5=("MTTKRP_IJ")


Iter=5
Size=( 50 100 150 200 250 400 )
results_path="results/mlirVScpp"
mkdir -p $results_path

for name in ${names1[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,MLIR,MLIR_polly,CPP,CPP_Sparse" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/$name" $size $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/${name}_polly" $size $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/$name" $size $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse" $size $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File
  done
done








for name in ${names2[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,MLIR,MLIR_polly,CPP,CPP_Sparse" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/$name" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/${name}_polly" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/$name" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse" $size $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File
  done
done














for name in ${names3[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,MLIR,MLIR_polly,CPP,CPP_Sparse" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/$name" $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/${name}_polly" $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/$name" $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse" $size $size $size)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File
  done
done









for name in ${names4[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,MLIR,MLIR_polly,CPP,CPP_Sparse" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/$name" $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/${name}_polly" $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/$name" $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse" $size $size $size 0)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File
  done
done





for name in ${names5[@]}
do
  Output_File="$results_path/$name.csv"
  echo "Size,MLIR,MLIR_polly,CPP,CPP_Sparse" > $Output_File
  for size in ${Size[@]}
  do
    echo "Size: $size"
    echo -n "$size," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/$name" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs_mlir/${name}_polly" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/$name" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo -n "$((Runtime / Iter))," >> $Output_File

    Runtime=0
    for i in $(eval echo "{1..$Iter}")
    do
        result=$("./outputs/${name}_Sparse" $size $size $size $size 0 0)
        Runtime=$(($result + $Runtime))
    done
    echo "$((Runtime / Iter))," >> $Output_File
  done
done