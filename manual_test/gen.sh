# !bin/bash

parent_folder="$PWD"

structtensor_names=("TTM_DP" "TTM_J" "TTM_UT" "THP_DP" "THP_I" "THP_J" "MTTKRP_JIK" "MTTKRP_D" "MTTKRP_J" "PGLM" "SpMV_UT" "SpMV_D" "LRC" "LRA" "PR2C" "PR2A" "PR3C" "PR3A")
sbt_commands=""
examples_folder="$parent_folder/structtensor/examples"
structtensor_folder="$parent_folder/structtensor"

for structtensor_name in "${structtensor_names[@]}"
do
    sbt_commands="$sbt_commands;run stur --inf $PWD/examples/$structtensor_name.stur --outf $PWD/manual_test/$structtensor_name.cpp --init-tensors --enforce-dims"
done

sbt clean
sbt compile
sbt "$sbt_commands"
