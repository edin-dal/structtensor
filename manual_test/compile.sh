# !bin/bash

parent_folder="$PWD"

structtensor_names=("TTM_DP" "TTM_J" "TTM_UT" "THP_DP" "THP_I" "THP_J" "MTTKRP_JIK" "MTTKRP_D" "MTTKRP_J" "PGLM" "SpMV_UT" "SpMV_D" "LRC" "LRA" "PR2C" "PR2A" "PR3C" "PR3A")
sbt_commands=""
experiments_folder="$parent_folder/manual_test"

for name in ${structtensor_names[@]}
do
    echo "Compiling $name.cpp"
    clang++ "$experiments_folder/$name.cpp" -std=c++17 -O3 -ffast-math -march=native -mtune=native -ftree-vectorize -Rpass=loop-vectorize -o "$experiments_folder/$name.o"
done

