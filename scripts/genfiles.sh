# !bin/bash

cd ..
# structtensor_names=("TTM_DP" "TTM_J" "THP_DP" "THP_I" "THP_J" "MTTKRP_IJ" "MTTKRP_I" "MTTKRP_J")
structtensor_names=("MTTKRP_IJ" "MTTKRP_I" "MTTKRP_J")

sbt_commands=""

for name in ${structtensor_names[@]}
do
  sbt_commands="$sbt_commands;run $name dense CPP cm"
  sbt_commands="$sbt_commands;run $name sparse CPP cm"
  sbt_commands="$sbt_commands;run $name dense C cm"
  sbt_commands="$sbt_commands;run $name sparse C cm"
  # sbt_commands="$sbt_commands;run $name dense MLIR"
done

sbt "$sbt_commands"

for name in ${structtensor_names[@]}
do
  mv outputs/$name.cpp outputs/${name}_cm.cpp
  mv outputs/${name}_Sparse.cpp outputs/${name}_Sparse_cm.cpp
  mv outputs_c/$name.c outputs_c/${name}_cm.c
  mv outputs_c/${name}_Sparse.c outputs_c/${name}_Sparse_cm.c
done


sbt_commands=""

for name in ${structtensor_names[@]}
do
  sbt_commands="$sbt_commands;run $name dense CPP no-cm"
  sbt_commands="$sbt_commands;run $name sparse CPP no-cm"
  sbt_commands="$sbt_commands;run $name dense C no-cm"
  sbt_commands="$sbt_commands;run $name sparse C no-cm"
  # sbt_commands="$sbt_commands;run $name dense MLIR"
done

sbt "$sbt_commands"

for name in ${structtensor_names[@]}
do
  mv outputs/$name.cpp outputs/${name}_no_cm.cpp
  mv outputs/${name}_Sparse.cpp outputs/${name}_Sparse_no_cm.cpp
  mv outputs_c/$name.c outputs_c/${name}_no_cm.c
  mv outputs_c/${name}_Sparse.c outputs_c/${name}_Sparse_no_cm.c
done