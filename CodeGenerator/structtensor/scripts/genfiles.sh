# !bin/bash

cd ..
structtensor_names=("TTM_DP" "TTM_J" "THP_DP" "THP_I" "THP_J" "MTTKRP_IJ" "MTTKRP_I" "MTTKRP_J")
for name in ${structtensor_names[@]}
do
  sbt "run $name"
  sbt "run $name sparse"
  sbt "run $name dense MLIR"
done
