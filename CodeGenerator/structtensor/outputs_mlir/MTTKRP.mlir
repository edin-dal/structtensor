"func.func"() ({
^bb0(%M : index, %Q: index, %N: index, %P: index, %A : memref<?x?xf64>, %B : memref<?x?x?xf64>, %C : memref<?x?xf64>, %D : memref<?x?xf64>):
%zero = "arith.constant"() {"value" = 0 : index} : () -> index
%zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
%one = "arith.constant"() {"value" = 1 : index} : () -> index

"scf.for"(%zero, %M, %one) ({
^bb0(%i: index):
    "scf.for"(%zero, %Q, %one) ({
    ^bb0(%j: index):
        %ksum = "scf.for"(%zero, %N, %one, %zerof) ({
        ^bb0(%k: index, %iter_sumk : f64):
            %lsum = "scf.for"(%zero, %P, %one, %zerof) ({
            ^bb0(%l: index, %iter_suml : f64):
                %b = "memref.load"(%B, %i, %k, %l) : (memref<?x?x?xf64>, index, index, index) -> f64
                %c = "memref.load"(%C, %k, %j) : (memref<?x?xf64>, index, index) -> f64
                %d = "memref.load"(%D, %l, %j) : (memref<?x?xf64>, index, index) -> f64
                %sum1 = "arith.mulf"(%b, %c) : (f64, f64) -> f64
                %sum2 = "arith.mulf"(%sum1, %d) : (f64, f64) -> f64
                %new_sum = "arith.addf"(%iter_suml, %sum2) : (f64, f64) -> f64
                "scf.yield"(%new_sum) : (f64) -> ()
            }) : (index, index, index, f64) -> f64
            %new_sumk = "arith.addf"(%lsum, %iter_sumk) : (f64, f64) -> f64
            "scf.yield"(%new_sumk) : (f64) -> ()
        }) : (index, index, index, f64) -> (f64)
        "memref.store"(%ksum, %A, %i, %j) : (f64, memref<?x?xf64>, index, index) -> ()
        "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()
    "scf.yield"() : () -> ()
}) : (index, index, index) -> ()

"func.return"() : () -> ()
})  {function_type = (index, index, index, index, memref<?x?xf64>, memref<?x?x?xf64>, memref<?x?xf64>, memref<?x?xf64>) -> (), sym_name = "myfunc", sym_visibility = "private"} : () -> ()