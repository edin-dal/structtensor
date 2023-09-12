# !bin/bash

cd ..
structtensor_names=("TTM_DP" "TTM_J" "THP_DP" "THP_I" "THP_J" "MTTKRP_IJ" "MTTKRP_I" "MTTKRP_J")

sbt_commands=""

for name in ${structtensor_names[@]}
do
  sbt_commands="$sbt_commands;run $name"
  sbt_commands="$sbt_commands;run $name sparse"
  sbt_commands="$sbt_commands;run $name dense MLIR"
done

sbt "$sbt_commands"
