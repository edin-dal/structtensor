
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
    %cont_degree5 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?x?xf64>
    %cont_degree6 = memref.alloc(%CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ, %CONT_SZ) : memref<?x?x?x?x?x?xf64>


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


    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i27: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i28: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i29: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i30: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i31: index):

    "scf.if"(%oi0) ({
      %rval32 = "func.call"() {callee = @rand} : () -> i32
      %rval33 = "arith.remui"(%rval32, %1000000) : (i32, i32) -> i32
      %rval34 = "arith.sitofp"(%rval33) : (i32) -> f64
      %rval35 = "arith.divf"(%rval34, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval35, %cont_degree5, %i27, %i28, %i29, %i30, %i31): (f64, memref<?x?x?x?x?xf64>, index, index, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %cont_degree5, %i27, %i28, %i29, %i30, %i31): (f64, memref<?x?x?x?x?xf64>, index, index, index, index, index) -> ()
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

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i36: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i37: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i38: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i39: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i40: index):

    "scf.for"(%0, %CONT_SZ, %1) ({
    ^bb0(%i41: index):

    "scf.if"(%oi0) ({
      %rval42 = "func.call"() {callee = @rand} : () -> i32
      %rval43 = "arith.remui"(%rval42, %1000000) : (i32, i32) -> i32
      %rval44 = "arith.sitofp"(%rval43) : (i32) -> f64
      %rval45 = "arith.divf"(%rval44, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval45, %cont_degree6, %i36, %i37, %i38, %i39, %i40, %i41): (f64, memref<?x?x?x?x?x?xf64>, index, index, index, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %cont_degree6, %i36, %i37, %i38, %i39, %i40, %i41): (f64, memref<?x?x?x?x?x?xf64>, index, index, index, index, index, index) -> ()
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

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64




affine.for %x0 = %0 to %CONT_SZ step 1 {

%x1_sum = affine.for %x1 = %x0 to %CONT_SZ step 1 iter_args(%iter_sum_x1 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%finalV50 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x1 = "arith.addf"(%finalV50, %iter_sum_x1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
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
%finalV52 = "arith.mulf"(%prod3, %tmp2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x2 = "arith.addf"(%finalV52, %iter_sum_x2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
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
%finalV54 = "arith.mulf"(%prod5, %tmp3) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x3 = "arith.addf"(%finalV54, %iter_sum_x3) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x3): (f64) -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}


affine.for %x0 = %0 to %CONT_SZ step 1 {

affine.for %x1 = %x0 to %CONT_SZ step 1 {

affine.for %x2 = %x1 to %CONT_SZ step 1 {

affine.for %x3 = %x2 to %CONT_SZ step 1 {

%x4_sum = affine.for %x4 = %x3 to %CONT_SZ step 1 iter_args(%iter_sum_x4 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%tmp2 = affine.load %cont_sum1[%x2] : memref<?xf64>

%tmp3 = affine.load %cont_sum1[%x3] : memref<?xf64>

%tmp4 = affine.load %cont_sum1[%x4] : memref<?xf64>

%prod5 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%prod6 = "arith.mulf"(%prod5, %tmp2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%prod7 = "arith.mulf"(%prod6, %tmp3) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%finalV56 = "arith.mulf"(%prod7, %tmp4) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x4 = "arith.addf"(%finalV56, %iter_sum_x4) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x4): (f64) -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
}


affine.for %x0 = %0 to %CONT_SZ step 1 {

affine.for %x1 = %x0 to %CONT_SZ step 1 {

affine.for %x2 = %x1 to %CONT_SZ step 1 {

affine.for %x3 = %x2 to %CONT_SZ step 1 {

affine.for %x4 = %x3 to %CONT_SZ step 1 {

%x5_sum = affine.for %x5 = %x4 to %CONT_SZ step 1 iter_args(%iter_sum_x5 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%tmp2 = affine.load %cont_sum1[%x2] : memref<?xf64>

%tmp3 = affine.load %cont_sum1[%x3] : memref<?xf64>

%tmp4 = affine.load %cont_sum1[%x4] : memref<?xf64>

%tmp5 = affine.load %cont_sum1[%x5] : memref<?xf64>

%prod6 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%prod7 = "arith.mulf"(%prod6, %tmp2) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%prod8 = "arith.mulf"(%prod7, %tmp3) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%prod9 = "arith.mulf"(%prod8, %tmp4) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
%finalV58 = "arith.mulf"(%prod9, %tmp5) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x5 = "arith.addf"(%finalV58, %iter_sum_x5) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x5): (f64) -> ()
}
"affine.yield"() : () -> ()
}
"affine.yield"() : () -> ()
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
    %last4 = "memref.load"(%cont_degree4, %0, %0, %0, %0) : (memref<?x?x?x?xf64>, index, index, index, index) -> f64
    "func.call"(%last4) {callee = @print_f64_cerr} : (f64) -> ()
    %last5 = "memref.load"(%cont_degree5, %0, %0, %0, %0, %0) : (memref<?x?x?x?x?xf64>, index, index, index, index, index) -> f64
    "func.call"(%last5) {callee = @print_f64_cerr} : (f64) -> ()
    %last = "memref.load"(%cont_degree6, %0, %0, %0, %0, %0, %0) : (memref<?x?x?x?x?x?xf64>, index, index, index, index, index, index) -> f64

    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
