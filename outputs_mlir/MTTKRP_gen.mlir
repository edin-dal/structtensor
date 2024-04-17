"func.func"() ({
^bb0(%M : index, %Q: index, %N: index, %P: index, %I: index, %J: index, %A : memref<?x?xf64>, %B : memref<?x?x?xf64>, %C : memref<?x?xf64>, %D : memref<?x?xf64>):
%0 = "arith.constant"() {"value" = 0 : index} : () -> index
%zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
%1 = "arith.constant"() {"value" = 1 : index} : () -> index

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
})  {function_type = (index, index, index, index, index, index, memref<?x?xf64>, memref<?x?x?xf64>, memref<?x?xf64>, memref<?x?xf64>) -> (), sym_name = "myfunc", sym_visibility = "private"} : () -> ()