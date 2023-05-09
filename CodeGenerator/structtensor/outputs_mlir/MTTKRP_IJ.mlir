
"builtin.module"() ({
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "puts", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "atoi", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "srand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i32), sym_name = "rand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "print_i32", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (), sym_name = "print_i64", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (f64) -> (), sym_name = "print_f64_cerr", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i64), sym_name = "timer", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (i64), sym_name = "timer_elapsed", sym_visibility = "private"} : () -> ()

  "func.func"() ({
    ^bb0(%argc : i32, %argv : !llvm.ptr<!llvm.ptr<i8>>):
    %0 = "arith.constant"() {"value" = 0 : index} : () -> index
    %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
    %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
    %1 = "arith.constant"() {"value" = 1 : index} : () -> index
    %oi1 = "arith.constant"() {"value" = 1 : i1} : () -> i1
    %oi0 = "arith.constant"() {"value" = 0 : i1} : () -> i1
    "func.call"(%zi32) {callee = @srand} : (i32) -> ()
    %1000000 = "arith.constant"() {"value" = 1000000 : i32} : () -> i32
    %f1000000 = "arith.constant"() {"value" = 1000000.0 : f64} : () -> f64


    %argvv1 = llvm.getelementptr %argv[1] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv1 = "llvm.load"(%argvv1) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Mi32 = "func.call"(%argv1) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %M = arith.index_cast %Mi32 : i32 to index

    %argvv2 = llvm.getelementptr %argv[2] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv2 = "llvm.load"(%argvv2) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ni32 = "func.call"(%argv2) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %N = arith.index_cast %Ni32 : i32 to index

    %argvv3 = llvm.getelementptr %argv[3] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv3 = "llvm.load"(%argvv3) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Pi32 = "func.call"(%argv3) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %P = arith.index_cast %Pi32 : i32 to index

    %argvv4 = llvm.getelementptr %argv[4] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv4 = "llvm.load"(%argvv4) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Qi32 = "func.call"(%argv4) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %Q = arith.index_cast %Qi32 : i32 to index

    %argvv5 = llvm.getelementptr %argv[5] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv5 = "llvm.load"(%argvv5) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ii32 = "func.call"(%argv5) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %I = arith.index_cast %Ii32 : i32 to index

    %argvv6 = llvm.getelementptr %argv[6] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv6 = "llvm.load"(%argvv6) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ji32 = "func.call"(%argv6) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %J = arith.index_cast %Ji32 : i32 to index


    %A = memref.alloc(%M, %Q) : memref<?x?xf64>
    %B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %C = memref.alloc(%N, %Q) : memref<?x?xf64>
    %D = memref.alloc(%P, %Q) : memref<?x?xf64>


    "scf.for"(%0, %M, %1) ({
    ^bb0(%i2: index):

    "scf.for"(%0, %N, %1) ({
    ^bb0(%i3: index):

    "scf.for"(%0, %P, %1) ({
    ^bb0(%i4: index):

    %gen_cond1 = "arith.cmpi"(%i2, %I) {predicate = 0 : i64} : (index, index) -> i1   

    "scf.if"(%gen_cond1) ({
      %rval5 = "func.call"() {callee = @rand} : () -> i32
      %rval6 = "arith.remui"(%rval5, %1000000) : (i32, i32) -> i32
      %rval7 = "arith.sitofp"(%rval6) : (i32) -> f64
      %rval8 = "arith.divf"(%rval7, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval8, %B, %i2, %i3, %i4): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %B, %i2, %i3, %i4): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %N, %1) ({
    ^bb0(%i9: index):

    "scf.for"(%0, %Q, %1) ({
    ^bb0(%i10: index):

    "scf.if"(%oi1) ({
      %rval11 = "func.call"() {callee = @rand} : () -> i32
      %rval12 = "arith.remui"(%rval11, %1000000) : (i32, i32) -> i32
      %rval13 = "arith.sitofp"(%rval12) : (i32) -> f64
      %rval14 = "arith.divf"(%rval13, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval14, %C, %i9, %i10): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %C, %i9, %i10): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %P, %1) ({
    ^bb0(%i16: index):

    "scf.for"(%0, %Q, %1) ({
    ^bb0(%i17: index):

    %gen_cond15 = "arith.cmpi"(%i17, %J) {predicate = 0 : i64} : (index, index) -> i1   

    "scf.if"(%gen_cond15) ({
      %rval18 = "func.call"() {callee = @rand} : () -> i32
      %rval19 = "arith.remui"(%rval18, %1000000) : (i32, i32) -> i32
      %rval20 = "arith.sitofp"(%rval19) : (i32) -> f64
      %rval21 = "arith.divf"(%rval20, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval21, %D, %i16, %i17): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %D, %i16, %i17): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %M, %1) ({
    ^bb0(%i22: index):

    "scf.for"(%0, %Q, %1) ({
    ^bb0(%i23: index):

    "scf.if"(%oi0) ({
      %rval24 = "func.call"() {callee = @rand} : () -> i32
      %rval25 = "arith.remui"(%rval24, %1000000) : (i32, i32) -> i32
      %rval26 = "arith.sitofp"(%rval25) : (i32) -> f64
      %rval27 = "arith.divf"(%rval26, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval27, %A, %i22, %i23): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %A, %i22, %i23): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64



%i = affine.apply affine_map<(i) -> (i)>(%I)
"affine.if"(%i, %M) ({

%j = affine.apply affine_map<(i) -> (i)>(%J)
"affine.if"(%j, %Q) ({

%k_sum = affine.for %k = %0 to %N step 1 iter_args(%iter_sum_k = %zerof) -> (f64) {

%l_sum = affine.for %l = %0 to %P step 1 iter_args(%iter_sum_l = %zerof) -> (f64) {

%tmp0 = affine.load %B[%i, %k, %l] : memref<?x?x?xf64>

%tmp1 = affine.load %C[%k, %j] : memref<?x?xf64>

%tmp2 = affine.load %D[%l, %j] : memref<?x?xf64>

%prod3 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%finalV29 = "arith.mulf"(%prod3, %tmp2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_l = "arith.addf"(%finalV29, %iter_sum_l) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_l): (f64) -> ()
}
%new_sum_k = "arith.addf"(%l_sum, %iter_sum_k) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_k): (f64) -> ()
}
%preVal31 = affine.load %A[%i, %j] : memref<?x?xf64>
%peqVal30 = "arith.addf"(%k_sum, %preVal31) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
affine.store %peqVal30, %A[%i, %j] : memref<?x?xf64>
"affine.yield"() : () -> ()
}, {"affine.yield"(): () -> ()}) {condition = affine_set<(d0)[s1]: (d0 <= s1 - 1)>} : (index,index) -> ()
"affine.yield"() : () -> ()
}, {"affine.yield"(): () -> ()}) {condition = affine_set<(d0)[s1]: (d0 <= s1 - 1)>} : (index,index) -> ()

    %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
    
    %last = "memref.load"(%A, %0, %0) : (memref<?x?xf64>, index, index) -> f64

    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
