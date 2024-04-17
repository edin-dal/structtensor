"builtin.module"() ({
    "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "puts", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "atoi", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = (i32) -> (), sym_name = "srand", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = () -> (i32), sym_name = "rand", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = (i32) -> (), sym_name = "print_i32", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = (i64) -> (), sym_name = "print_i64", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = () -> (i64), sym_name = "timer", sym_visibility = "private"} : () -> ()
    "func.func"() ({}) {function_type = (i64) -> (i64), sym_name = "timer_elapsed", sym_visibility = "private"} : () -> ()
    
    
    "func.func"() ({
        ^bb0(%argc : i32, %argv : !llvm.ptr<!llvm.ptr<i8>>):
        %0 = "arith.constant"() {"value" = 0 : index} : () -> index
        %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
        %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
        %1 = "arith.constant"() {"value" = 1 : index} : () -> index

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

        // "func.call"(%Mi32) {callee = @print_i32} : (i32) -> ()
        // "func.call"(%Ni32) {callee = @print_i32} : (i32) -> ()
        // "func.call"(%Pi32) {callee = @print_i32} : (i32) -> ()
        // "func.call"(%Qi32) {callee = @print_i32} : (i32) -> ()
        // "func.call"(%Ii32) {callee = @print_i32} : (i32) -> ()
        // "func.call"(%Ji32) {callee = @print_i32} : (i32) -> ()

        "func.call"(%zi32) {callee = @srand} : (i32) -> ()

        // %ooo = "func.call"() {callee = @rand} : () -> i32
        // "func.call"(%ooo) {callee = @print_i32} : (i32) -> ()
        %stime = "func.call"() {callee = @timer} : () -> i64
        %1000000 = "arith.constant"() {"value" = 1000000 : i32} : () -> i32
        %f1000000 = "arith.constant"() {"value" = 1000000.0 : f64} : () -> f64
        "scf.for"(%0, %M, %1) ({
        ^bb0(%i0: index):
            "scf.for"(%0, %N, %1) ({
            ^bb0(%i1: index):
                "scf.for"(%0, %P, %1) ({
                ^bb0(%i2: index):
                    %rval1 = "func.call"() {callee = @rand} : () -> i32
                    %rval2 = "arith.remui"(%rval1, %1000000) : (i32, i32) -> i32
                    %rval3 = "arith.sitofp"(%rval2) : (i32) -> f64
                    %rval4 = "arith.divf"(%rval3, %f1000000) : (f64, f64) -> f64
                    "memref.store"(%rval4, %B, %i0, %i1, %i2): (f64, memref<?x?x?xf64>, index, index, index) -> ()
                    "scf.yield"(): () -> ()
                }): (index, index, index) -> ()
                "scf.yield"(): () -> ()
            }): (index, index, index) -> ()
            "scf.yield"(): () -> ()
        }): (index, index, index) -> ()
        %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
        "func.call"(%time) {callee = @print_i64} : (i64) -> ()


        %i = "arith.addi"(%0, %I) : (index, index) -> index 
        %cmpval2 = "arith.cmpi"(%i, %M) {predicate = 2 : i64} : (index, index) -> i1
        "scf.if"(%cmpval2) ({

        %j = "arith.addi"(%0, %J) : (index, index) -> index 
        %cmpval3 = "arith.cmpi"(%j, %Q) {predicate = 2 : i64} : (index, index) -> i1
        "scf.if"(%cmpval3) ({

        %k_sum = "scf.for"(%0, %N, %1, %zerof) ({
        ^bb0(%k: index, %iter_sum_k: f64):

        %l_sum = "scf.for"(%0, %P, %1, %zerof) ({
        ^bb0(%l: index, %iter_sum_l: f64):

        %tmp0 = "memref.load"(%B, %i, %k, %l) : (memref<?x?x?xf64>, index, index, index) -> f64

        %tmp1 = "memref.load"(%C, %k, %j) : (memref<?x?xf64>, index, index) -> f64

        %tmp2 = "memref.load"(%D, %l, %j) : (memref<?x?xf64>, index, index) -> f64

        %prod3 = "arith.mulf"(%tmp0, %tmp1) : (f64, f64) -> f64
        %finalV4 = "arith.mulf"(%prod3, %tmp2) : (f64, f64) -> f64


        %new_sum_l = "arith.addf"(%finalV4, %iter_sum_l) : (f64, f64) -> f64
        "scf.yield"(%new_sum_l): (f64) -> ()
        }) : (index, index, index, f64) -> f64
        %new_sum_k = "arith.addf"(%l_sum, %iter_sum_k) : (f64, f64) -> f64
        "scf.yield"(%new_sum_k): (f64) -> ()
        }) : (index, index, index, f64) -> f64
        %preVal6 = "memref.load"(%A, %i, %j) : (memref<?x?xf64>, index, index) -> f64
        %peqVal5 = "arith.addf"(%k_sum, %preVal6) : (f64, f64) -> f64
        "memref.store"(%peqVal5, %A, %i, %j) : (f64, memref<?x?xf64>, index, index) -> ()
        "scf.yield"() : () -> ()
        }, {"scf.yield"(): () -> ()}) : (i1) -> ()
        "scf.yield"() : () -> ()
        }, {"scf.yield"(): () -> ()}) : (i1) -> ()

        "func.return"() : () -> ()
        })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()