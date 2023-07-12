
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
    %CONT_SZi32 = "func.call"(%argv1) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %CONT_SZ = arith.index_cast %CONT_SZi32 : i32 to index


    %cont_sum1 = memref.alloc(%CONT_SZ) : memref<?xf64>
    %cont_degree2 = memref.alloc(%CONT_SZ, %CONT_SZ) : memref<?x?xf64>
    %cont_degree3 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?xf64>
    %cont_degree4 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?xf64>


    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i1: index):

    "scf.if"(%oi1) ({
      %rval2 = "func.call"() {callee = @rand} : () -> i32
      %rval3 = "arith.remui"(%rval2, %1000000) : (i32, i32) -> i32
      %rval4 = "arith.sitofp"(%rval3) : (i32) -> f64
      %rval5 = "arith.divf"(%rval4, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval5, %cont_sum1, %i1): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %cont_sum1, %i1): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i6: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i7: index):

    "scf.if"(%oi0) ({
      %rval8 = "func.call"() {callee = @rand} : () -> i32
      %rval9 = "arith.remui"(%rval8, %1000000) : (i32, i32) -> i32
      %rval10 = "arith.sitofp"(%rval9) : (i32) -> f64
      %rval11 = "arith.divf"(%rval10, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval11, %cont_degree2, %i6, %i7): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %cont_degree2, %i6, %i7): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i12: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i13: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i14: index):

    "scf.if"(%oi0) ({
      %rval15 = "func.call"() {callee = @rand} : () -> i32
      %rval16 = "arith.remui"(%rval15, %1000000) : (i32, i32) -> i32
      %rval17 = "arith.sitofp"(%rval16) : (i32) -> f64
      %rval18 = "arith.divf"(%rval17, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval18, %cont_degree3, %i12, %i13, %i14): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %cont_degree3, %i12, %i13, %i14): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i19: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i20: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i21: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i22: index):

    "scf.if"(%oi0) ({
      %rval23 = "func.call"() {callee = @rand} : () -> i32
      %rval24 = "arith.remui"(%rval23, %1000000) : (i32, i32) -> i32
      %rval25 = "arith.sitofp"(%rval24) : (i32) -> f64
      %rval26 = "arith.divf"(%rval25, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval26, %cont_degree4, %i19, %i20, %i21, %i22): (f64, memref<?x?x?x?xf64>, index, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %cont_degree4, %i19, %i20, %i21, %i22): (f64, memref<?x?x?x?xf64>, index, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64




affine.for %x0 = %0 to %CONT_SZ step 1 {

%x1_sum = affine.for %x1 = %x0 to %CONT_SZ step 1 iter_args(%iter_sum_x1 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%finalV29 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x1 = "arith.addf"(%finalV29, %iter_sum_x1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x1): (f64) -> ()
}
"affine.yield"() : () -> ()
}


affine.for %x0 = %0 to %CONT_SZ step 1 {

affine.for %x1 = %x0 to %CONT_SZ step 1 {

%x2_sum = affine.for %x2 = %x1 to %CONT_SZ step 1 iter_args(%iter_sum_x2 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%tmp2 = affine.load %cont_sum1[%x2] : memref<?xf64>

%prod3 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%finalV31 = "arith.mulf"(%prod3, %tmp2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x2 = "arith.addf"(%finalV31, %iter_sum_x2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x2): (f64) -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}


affine.for %x0 = %0 to %CONT_SZ step 1 {

affine.for %x1 = %x0 to %CONT_SZ step 1 {

affine.for %x2 = %x1 to %CONT_SZ step 1 {

%x3_sum = affine.for %x3 = %x2 to %CONT_SZ step 1 iter_args(%iter_sum_x3 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%tmp2 = affine.load %cont_sum1[%x2] : memref<?xf64>

%tmp3 = affine.load %cont_sum1[%x3] : memref<?xf64>

%prod4 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%prod5 = "arith.mulf"(%prod4, %tmp2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%finalV33 = "arith.mulf"(%prod5, %tmp3) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x3 = "arith.addf"(%finalV33, %iter_sum_x3) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x3): (f64) -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}

    %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
    
    %last2 = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64
    "func.call"(%last2) {callee = @print_f64_cerr} : (f64) -> ()
    %last3 = "memref.load"(%cont_degree3, %0, %0, %0) : (memref<?x?x?xf64>, index, index, index) -> f64
    "func.call"(%last3) {callee = @print_f64_cerr} : (f64) -> ()
    %last = "memref.load"(%cont_degree4, %0, %0, %0, %0) : (memref<?x?x?x?xf64>, index, index, index, index) -> f64

    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
