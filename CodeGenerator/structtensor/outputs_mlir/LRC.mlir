
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


    %stime = "func.call"() {callee = @timer} : () -> i64




affine.for %x0 = %0 to %CONT_SZ step 1 {

%x1_sum = affine.for %x1 = %x0 to %CONT_SZ step 1 iter_args(%iter_sum_x1 = %zerof) -> (f64) {

%tmp0 = affine.load %cont_sum1[%x0] : memref<?xf64>

%tmp1 = affine.load %cont_sum1[%x1] : memref<?xf64>

%finalV12 = "arith.mulf"(%tmp0, %tmp1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64


%new_sum_x1 = "arith.addf"(%finalV12, %iter_sum_x1) {"fastmath" = #arith.fastmath<fast>} : (f64, f64) -> f64
"affine.yield"(%new_sum_x1): (f64) -> ()
}
"affine.yield"() : () -> ()
}

    %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
    
    %last = "memref.load"(%cont_degree2, %0, %0) : (memref<?x?xf64>, index, index) -> f64

    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
