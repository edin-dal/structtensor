; ModuleID = '<stdin>'
source_filename = "LLVMDialectModule"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: mustprogress nofree nounwind willreturn allockind("alloc,uninitialized") allocsize(0) memory(inaccessiblemem: readwrite)
declare noalias noundef ptr @malloc(i64 noundef) local_unnamed_addr #0

; Function Attrs: mustprogress nofree nounwind willreturn memory(read)
declare i32 @atoi(ptr nocapture) local_unnamed_addr #1

declare void @srand(i32) local_unnamed_addr

declare i32 @rand() local_unnamed_addr

declare void @print_i64(i64) local_unnamed_addr

declare void @print_f64_cerr(double) local_unnamed_addr

declare i64 @timer() local_unnamed_addr

declare i64 @timer_elapsed(i64) local_unnamed_addr

define void @main(i32 %0, ptr nocapture readonly %1) local_unnamed_addr {
  tail call void @srand(i32 0)
  %3 = getelementptr ptr, ptr %1, i64 1
  %4 = load ptr, ptr %3, align 8
  %5 = tail call i32 @atoi(ptr nocapture %4)
  %6 = sext i32 %5 to i64
  %7 = getelementptr ptr, ptr %1, i64 2
  %8 = load ptr, ptr %7, align 8
  %9 = tail call i32 @atoi(ptr nocapture %8)
  %10 = sext i32 %9 to i64
  %11 = getelementptr ptr, ptr %1, i64 3
  %12 = load ptr, ptr %11, align 8
  %13 = tail call i32 @atoi(ptr nocapture %12)
  %14 = sext i32 %13 to i64
  %15 = getelementptr ptr, ptr %1, i64 4
  %16 = load ptr, ptr %15, align 8
  %17 = tail call i32 @atoi(ptr nocapture %16)
  %18 = sext i32 %17 to i64
  %19 = mul nsw i64 %18, %10
  %20 = shl nsw i64 %6, 3
  %.idx = mul i64 %20, %19
  %21 = tail call ptr @malloc(i64 %.idx)
  %22 = mul nsw i64 %14, %10
  %.idx13 = mul i64 %20, %22
  %23 = tail call ptr @malloc(i64 %.idx13)
  %24 = shl nsw i64 %14, 3
  %.idx14 = mul i64 %24, %18
  %25 = tail call ptr @malloc(i64 %.idx14)
  %26 = icmp sgt i32 %5, 0
  %27 = icmp sgt i32 %9, 0
  %or.cond = select i1 %26, i1 %27, i1 false
  %28 = icmp sgt i32 %13, 0
  %or.cond60 = select i1 %or.cond, i1 %28, i1 false
  br i1 %or.cond60, label %.preheader16.us.us.preheader, label %.preheader15

.preheader16.us.us.preheader:                     ; preds = %2
  %29 = shl i64 %22, 3
  br label %.preheader16.us.us

.preheader16.us.us:                               ; preds = %.preheader16.us.us.preheader, %._crit_edge18.split.us.us.us
  %30 = phi i64 [ %48, %._crit_edge18.split.us.us.us ], [ 0, %.preheader16.us.us.preheader ]
  %31 = mul i64 %29, %30
  %32 = mul i64 %30, %22
  br label %.lr.ph.us.us.us

.lr.ph.us.us.us:                                  ; preds = %._crit_edge.us.us.us, %.preheader16.us.us
  %33 = phi i64 [ 0, %.preheader16.us.us ], [ %39, %._crit_edge.us.us.us ]
  %34 = icmp eq i64 %30, %33
  %35 = mul i64 %33, %14
  %36 = add i64 %35, %32
  br i1 %34, label %.lr.ph.split.us.us.us.us, label %.lr.ph.split.us20.us.us.preheader

.lr.ph.split.us20.us.us.preheader:                ; preds = %.lr.ph.us.us.us
  %37 = mul i64 %24, %33
  %38 = add i64 %31, %37
  %scevgep = getelementptr i8, ptr %23, i64 %38
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep, i8 0, i64 %24, i1 false)
  br label %._crit_edge.us.us.us

._crit_edge.us.us.us:                             ; preds = %.lr.ph.split.us.us.us.us, %.lr.ph.split.us20.us.us.preheader
  %39 = add nuw nsw i64 %33, 1
  %exitcond50.not = icmp eq i64 %39, %10
  br i1 %exitcond50.not, label %._crit_edge18.split.us.us.us, label %.lr.ph.us.us.us

.lr.ph.split.us.us.us.us:                         ; preds = %.lr.ph.us.us.us, %.lr.ph.split.us.us.us.us
  %40 = phi i64 [ %47, %.lr.ph.split.us.us.us.us ], [ 0, %.lr.ph.us.us.us ]
  %41 = tail call i32 @rand()
  %42 = urem i32 %41, 1000000
  %43 = sitofp i32 %42 to double
  %44 = fdiv double %43, 1.000000e+06
  %45 = add i64 %36, %40
  %46 = getelementptr double, ptr %23, i64 %45
  store double %44, ptr %46, align 8
  %47 = add nuw nsw i64 %40, 1
  %exitcond.not = icmp eq i64 %47, %14
  br i1 %exitcond.not, label %._crit_edge.us.us.us, label %.lr.ph.split.us.us.us.us

._crit_edge18.split.us.us.us:                     ; preds = %._crit_edge.us.us.us
  %48 = add nuw nsw i64 %30, 1
  %exitcond51.not = icmp eq i64 %48, %6
  br i1 %exitcond51.not, label %.preheader15, label %.preheader16.us.us

.preheader15:                                     ; preds = %._crit_edge18.split.us.us.us, %2
  %49 = icmp sgt i32 %17, 0
  %50 = icmp sgt i32 %13, 0
  %or.cond61 = select i1 %49, i1 %50, i1 false
  br i1 %or.cond61, label %.lr.ph.us, label %.preheader

.lr.ph.us:                                        ; preds = %.preheader15, %._crit_edge.us
  %51 = phi i64 [ %62, %._crit_edge.us ], [ 0, %.preheader15 ]
  %52 = mul i64 %51, %14
  br label %53

53:                                               ; preds = %.lr.ph.us, %53
  %54 = phi i64 [ 0, %.lr.ph.us ], [ %61, %53 ]
  %55 = tail call i32 @rand()
  %56 = urem i32 %55, 1000000
  %57 = sitofp i32 %56 to double
  %58 = fdiv double %57, 1.000000e+06
  %59 = add nsw i64 %54, %52
  %60 = getelementptr double, ptr %25, i64 %59
  store double %58, ptr %60, align 8
  %61 = add nuw nsw i64 %54, 1
  %exitcond52.not = icmp eq i64 %61, %14
  br i1 %exitcond52.not, label %._crit_edge.us, label %53

._crit_edge.us:                                   ; preds = %53
  %62 = add nuw nsw i64 %51, 1
  %exitcond53.not = icmp eq i64 %62, %18
  br i1 %exitcond53.not, label %.preheader, label %.lr.ph.us

.preheader:                                       ; preds = %._crit_edge.us, %.preheader15
  %63 = icmp slt i32 %9, 1
  %not. = xor i1 %26, true
  %or.cond62 = select i1 %not., i1 true, i1 %63
  %.not = xor i1 %49, true
  %brmerge = select i1 %or.cond62, i1 true, i1 %.not
  br i1 %brmerge, label %._crit_edge, label %.lr.ph25.us.us.preheader

.lr.ph25.us.us.preheader:                         ; preds = %.preheader
  %64 = shl i64 %19, 3
  %65 = add nsw i64 %6, -1
  %xtraiter = and i64 %6, 7
  %66 = icmp ult i64 %65, 7
  br i1 %66, label %._crit_edge.loopexit.unr-lcssa, label %.lr.ph25.us.us.preheader.new

.lr.ph25.us.us.preheader.new:                     ; preds = %.lr.ph25.us.us.preheader
  %unroll_iter = and i64 %6, -8
  br label %.lr.ph25.us.us

.lr.ph25.us.us:                                   ; preds = %.lr.ph25.us.us, %.lr.ph25.us.us.preheader.new
  %67 = phi i64 [ 0, %.lr.ph25.us.us.preheader.new ], [ %83, %.lr.ph25.us.us ]
  %niter = phi i64 [ 0, %.lr.ph25.us.us.preheader.new ], [ %niter.next.7, %.lr.ph25.us.us ]
  %68 = mul i64 %64, %67
  %scevgep55 = getelementptr i8, ptr %21, i64 %68
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55, i8 0, i64 %64, i1 false)
  %69 = or i64 %67, 1
  %70 = mul i64 %64, %69
  %scevgep55.1 = getelementptr i8, ptr %21, i64 %70
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.1, i8 0, i64 %64, i1 false)
  %71 = or i64 %67, 2
  %72 = mul i64 %64, %71
  %scevgep55.2 = getelementptr i8, ptr %21, i64 %72
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.2, i8 0, i64 %64, i1 false)
  %73 = or i64 %67, 3
  %74 = mul i64 %64, %73
  %scevgep55.3 = getelementptr i8, ptr %21, i64 %74
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.3, i8 0, i64 %64, i1 false)
  %75 = or i64 %67, 4
  %76 = mul i64 %64, %75
  %scevgep55.4 = getelementptr i8, ptr %21, i64 %76
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.4, i8 0, i64 %64, i1 false)
  %77 = or i64 %67, 5
  %78 = mul i64 %64, %77
  %scevgep55.5 = getelementptr i8, ptr %21, i64 %78
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.5, i8 0, i64 %64, i1 false)
  %79 = or i64 %67, 6
  %80 = mul i64 %64, %79
  %scevgep55.6 = getelementptr i8, ptr %21, i64 %80
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.6, i8 0, i64 %64, i1 false)
  %81 = or i64 %67, 7
  %82 = mul i64 %64, %81
  %scevgep55.7 = getelementptr i8, ptr %21, i64 %82
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.7, i8 0, i64 %64, i1 false)
  %83 = add nuw nsw i64 %67, 8
  %niter.next.7 = add i64 %niter, 8
  %niter.ncmp.7 = icmp eq i64 %niter.next.7, %unroll_iter
  br i1 %niter.ncmp.7, label %._crit_edge.loopexit.unr-lcssa, label %.lr.ph25.us.us

._crit_edge.loopexit.unr-lcssa:                   ; preds = %.lr.ph25.us.us, %.lr.ph25.us.us.preheader
  %.unr = phi i64 [ 0, %.lr.ph25.us.us.preheader ], [ %83, %.lr.ph25.us.us ]
  %lcmp.mod.not = icmp eq i64 %xtraiter, 0
  br i1 %lcmp.mod.not, label %._crit_edge, label %.lr.ph25.us.us.epil

.lr.ph25.us.us.epil:                              ; preds = %._crit_edge.loopexit.unr-lcssa, %.lr.ph25.us.us.epil
  %84 = phi i64 [ %86, %.lr.ph25.us.us.epil ], [ %.unr, %._crit_edge.loopexit.unr-lcssa ]
  %epil.iter = phi i64 [ %epil.iter.next, %.lr.ph25.us.us.epil ], [ 0, %._crit_edge.loopexit.unr-lcssa ]
  %85 = mul i64 %64, %84
  %scevgep55.epil = getelementptr i8, ptr %21, i64 %85
  tail call void @llvm.memset.p0.i64(ptr align 8 %scevgep55.epil, i8 0, i64 %64, i1 false)
  %86 = add nuw nsw i64 %84, 1
  %epil.iter.next = add i64 %epil.iter, 1
  %epil.iter.cmp.not = icmp eq i64 %epil.iter.next, %xtraiter
  br i1 %epil.iter.cmp.not, label %._crit_edge, label %.lr.ph25.us.us.epil, !llvm.loop !1

._crit_edge:                                      ; preds = %._crit_edge.loopexit.unr-lcssa, %.lr.ph25.us.us.epil, %.preheader
  %87 = tail call i64 @timer()
  %88 = tail call i64 @llvm.umin.i64(i64 %6, i64 %10)
  %89 = icmp sgt i64 %88, 0
  br i1 %89, label %.lr.ph38, label %._crit_edge39

.lr.ph38:                                         ; preds = %._crit_edge
  %90 = add nsw i64 %22, %14
  %91 = add nsw i64 %19, %18
  %92 = icmp sgt i32 %13, 0
  %or.cond63 = select i1 %49, i1 %92, i1 false
  br i1 %or.cond63, label %.lr.ph35.us.us.preheader, label %._crit_edge39

.lr.ph35.us.us.preheader:                         ; preds = %.lr.ph38
  %xtraiter82 = and i64 %18, 7
  %93 = icmp ult i32 %17, 8
  %unroll_iter86 = and i64 %18, -8
  %min.iters.check = icmp ult i32 %13, 16
  %n.vec = and i64 %14, -16
  %cmp.n = icmp eq i64 %n.vec, %14
  %min.iters.check.1 = icmp ult i32 %13, 16
  %n.vec.1 = and i64 %14, -16
  %cmp.n.1 = icmp eq i64 %n.vec.1, %14
  %min.iters.check.2 = icmp ult i32 %13, 16
  %n.vec.2 = and i64 %14, -16
  %cmp.n.2 = icmp eq i64 %n.vec.2, %14
  %min.iters.check.3 = icmp ult i32 %13, 16
  %n.vec.3 = and i64 %14, -16
  %cmp.n.3 = icmp eq i64 %n.vec.3, %14
  %min.iters.check.4 = icmp ult i32 %13, 16
  %n.vec.4 = and i64 %14, -16
  %cmp.n.4 = icmp eq i64 %n.vec.4, %14
  %min.iters.check.5 = icmp ult i32 %13, 16
  %n.vec.5 = and i64 %14, -16
  %cmp.n.5 = icmp eq i64 %n.vec.5, %14
  %min.iters.check.6 = icmp ult i32 %13, 16
  %n.vec.6 = and i64 %14, -16
  %cmp.n.6 = icmp eq i64 %n.vec.6, %14
  %min.iters.check.7 = icmp ult i32 %13, 16
  %n.vec.7 = and i64 %14, -16
  %cmp.n.7 = icmp eq i64 %n.vec.7, %14
  %lcmp.mod85.not = icmp eq i64 %xtraiter82, 0
  %min.iters.check.epil = icmp ult i32 %13, 16
  %n.vec.epil = and i64 %14, -16
  %cmp.n.epil = icmp eq i64 %n.vec.epil, %14
  br label %.lr.ph35.us.us

.lr.ph35.us.us:                                   ; preds = %.lr.ph35.us.us.preheader, %._crit_edge36.split.us.us.us
  %94 = phi i64 [ %432, %._crit_edge36.split.us.us.us ], [ 0, %.lr.ph35.us.us.preheader ]
  %95 = mul i64 %94, %90
  %96 = mul i64 %94, %91
  br i1 %93, label %._crit_edge36.split.us.us.us.unr-lcssa, label %.lr.ph32.us.us.us

.lr.ph32.us.us.us:                                ; preds = %.lr.ph35.us.us, %._crit_edge33.us.us.us.7
  %97 = phi i64 [ %393, %._crit_edge33.us.us.us.7 ], [ 0, %.lr.ph35.us.us ]
  %niter87 = phi i64 [ %niter87.next.7, %._crit_edge33.us.us.us.7 ], [ 0, %.lr.ph35.us.us ]
  %98 = mul i64 %97, %14
  br i1 %min.iters.check, label %scalar.ph.preheader, label %vector.body

vector.body:                                      ; preds = %.lr.ph32.us.us.us, %vector.body
  %index = phi i64 [ %index.next, %vector.body ], [ 0, %.lr.ph32.us.us.us ]
  %vec.phi = phi <4 x double> [ %113, %vector.body ], [ zeroinitializer, %.lr.ph32.us.us.us ]
  %vec.phi64 = phi <4 x double> [ %114, %vector.body ], [ zeroinitializer, %.lr.ph32.us.us.us ]
  %vec.phi65 = phi <4 x double> [ %115, %vector.body ], [ zeroinitializer, %.lr.ph32.us.us.us ]
  %vec.phi66 = phi <4 x double> [ %116, %vector.body ], [ zeroinitializer, %.lr.ph32.us.us.us ]
  %99 = add nsw i64 %index, %98
  %100 = getelementptr double, ptr %25, i64 %99
  %wide.load = load <4 x double>, ptr %100, align 8
  %101 = getelementptr double, ptr %100, i64 4
  %wide.load67 = load <4 x double>, ptr %101, align 8
  %102 = getelementptr double, ptr %100, i64 8
  %wide.load68 = load <4 x double>, ptr %102, align 8
  %103 = getelementptr double, ptr %100, i64 12
  %wide.load69 = load <4 x double>, ptr %103, align 8
  %104 = add i64 %index, %95
  %105 = getelementptr double, ptr %23, i64 %104
  %wide.load70 = load <4 x double>, ptr %105, align 8
  %106 = getelementptr double, ptr %105, i64 4
  %wide.load71 = load <4 x double>, ptr %106, align 8
  %107 = getelementptr double, ptr %105, i64 8
  %wide.load72 = load <4 x double>, ptr %107, align 8
  %108 = getelementptr double, ptr %105, i64 12
  %wide.load73 = load <4 x double>, ptr %108, align 8
  %109 = fmul fast <4 x double> %wide.load70, %wide.load
  %110 = fmul fast <4 x double> %wide.load71, %wide.load67
  %111 = fmul fast <4 x double> %wide.load72, %wide.load68
  %112 = fmul fast <4 x double> %wide.load73, %wide.load69
  %113 = fadd fast <4 x double> %109, %vec.phi
  %114 = fadd fast <4 x double> %110, %vec.phi64
  %115 = fadd fast <4 x double> %111, %vec.phi65
  %116 = fadd fast <4 x double> %112, %vec.phi66
  %index.next = add nuw i64 %index, 16
  %117 = icmp eq i64 %index.next, %n.vec
  br i1 %117, label %middle.block, label %vector.body, !llvm.loop !3

middle.block:                                     ; preds = %vector.body
  %bin.rdx = fadd fast <4 x double> %114, %113
  %bin.rdx74 = fadd fast <4 x double> %115, %bin.rdx
  %bin.rdx75 = fadd fast <4 x double> %116, %bin.rdx74
  %118 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75)
  br i1 %cmp.n, label %._crit_edge33.us.us.us, label %scalar.ph.preheader

scalar.ph.preheader:                              ; preds = %.lr.ph32.us.us.us, %middle.block
  %.ph = phi double [ 0.000000e+00, %.lr.ph32.us.us.us ], [ %118, %middle.block ]
  %.ph76 = phi i64 [ 0, %.lr.ph32.us.us.us ], [ %n.vec, %middle.block ]
  br label %scalar.ph

scalar.ph:                                        ; preds = %scalar.ph.preheader, %scalar.ph
  %119 = phi double [ %128, %scalar.ph ], [ %.ph, %scalar.ph.preheader ]
  %120 = phi i64 [ %129, %scalar.ph ], [ %.ph76, %scalar.ph.preheader ]
  %121 = add nsw i64 %120, %98
  %122 = getelementptr double, ptr %25, i64 %121
  %123 = load double, ptr %122, align 8
  %124 = add i64 %120, %95
  %125 = getelementptr double, ptr %23, i64 %124
  %126 = load double, ptr %125, align 8
  %127 = fmul fast double %126, %123
  %128 = fadd fast double %127, %119
  %129 = add nuw nsw i64 %120, 1
  %exitcond57.not = icmp eq i64 %129, %14
  br i1 %exitcond57.not, label %._crit_edge33.us.us.us, label %scalar.ph, !llvm.loop !6

._crit_edge33.us.us.us:                           ; preds = %scalar.ph, %middle.block
  %.lcssa = phi double [ %118, %middle.block ], [ %128, %scalar.ph ]
  %130 = add i64 %97, %96
  %131 = getelementptr double, ptr %21, i64 %130
  %132 = load double, ptr %131, align 8
  %133 = fadd fast double %132, %.lcssa
  store double %133, ptr %131, align 8
  %134 = or i64 %97, 1
  %135 = mul i64 %134, %14
  br i1 %min.iters.check.1, label %scalar.ph.preheader.1, label %vector.body.1

vector.body.1:                                    ; preds = %._crit_edge33.us.us.us, %vector.body.1
  %index.1 = phi i64 [ %index.next.1, %vector.body.1 ], [ 0, %._crit_edge33.us.us.us ]
  %vec.phi.1 = phi <4 x double> [ %150, %vector.body.1 ], [ zeroinitializer, %._crit_edge33.us.us.us ]
  %vec.phi64.1 = phi <4 x double> [ %151, %vector.body.1 ], [ zeroinitializer, %._crit_edge33.us.us.us ]
  %vec.phi65.1 = phi <4 x double> [ %152, %vector.body.1 ], [ zeroinitializer, %._crit_edge33.us.us.us ]
  %vec.phi66.1 = phi <4 x double> [ %153, %vector.body.1 ], [ zeroinitializer, %._crit_edge33.us.us.us ]
  %136 = add nsw i64 %index.1, %135
  %137 = getelementptr double, ptr %25, i64 %136
  %wide.load.1 = load <4 x double>, ptr %137, align 8
  %138 = getelementptr double, ptr %137, i64 4
  %wide.load67.1 = load <4 x double>, ptr %138, align 8
  %139 = getelementptr double, ptr %137, i64 8
  %wide.load68.1 = load <4 x double>, ptr %139, align 8
  %140 = getelementptr double, ptr %137, i64 12
  %wide.load69.1 = load <4 x double>, ptr %140, align 8
  %141 = add i64 %index.1, %95
  %142 = getelementptr double, ptr %23, i64 %141
  %wide.load70.1 = load <4 x double>, ptr %142, align 8
  %143 = getelementptr double, ptr %142, i64 4
  %wide.load71.1 = load <4 x double>, ptr %143, align 8
  %144 = getelementptr double, ptr %142, i64 8
  %wide.load72.1 = load <4 x double>, ptr %144, align 8
  %145 = getelementptr double, ptr %142, i64 12
  %wide.load73.1 = load <4 x double>, ptr %145, align 8
  %146 = fmul fast <4 x double> %wide.load70.1, %wide.load.1
  %147 = fmul fast <4 x double> %wide.load71.1, %wide.load67.1
  %148 = fmul fast <4 x double> %wide.load72.1, %wide.load68.1
  %149 = fmul fast <4 x double> %wide.load73.1, %wide.load69.1
  %150 = fadd fast <4 x double> %146, %vec.phi.1
  %151 = fadd fast <4 x double> %147, %vec.phi64.1
  %152 = fadd fast <4 x double> %148, %vec.phi65.1
  %153 = fadd fast <4 x double> %149, %vec.phi66.1
  %index.next.1 = add nuw i64 %index.1, 16
  %154 = icmp eq i64 %index.next.1, %n.vec.1
  br i1 %154, label %middle.block.1, label %vector.body.1, !llvm.loop !3

middle.block.1:                                   ; preds = %vector.body.1
  %bin.rdx.1 = fadd fast <4 x double> %151, %150
  %bin.rdx74.1 = fadd fast <4 x double> %152, %bin.rdx.1
  %bin.rdx75.1 = fadd fast <4 x double> %153, %bin.rdx74.1
  %155 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.1)
  br i1 %cmp.n.1, label %._crit_edge33.us.us.us.1, label %scalar.ph.preheader.1

scalar.ph.preheader.1:                            ; preds = %middle.block.1, %._crit_edge33.us.us.us
  %.ph.1 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us ], [ %155, %middle.block.1 ]
  %.ph76.1 = phi i64 [ 0, %._crit_edge33.us.us.us ], [ %n.vec.1, %middle.block.1 ]
  br label %scalar.ph.1

scalar.ph.1:                                      ; preds = %scalar.ph.1, %scalar.ph.preheader.1
  %156 = phi double [ %165, %scalar.ph.1 ], [ %.ph.1, %scalar.ph.preheader.1 ]
  %157 = phi i64 [ %166, %scalar.ph.1 ], [ %.ph76.1, %scalar.ph.preheader.1 ]
  %158 = add nsw i64 %157, %135
  %159 = getelementptr double, ptr %25, i64 %158
  %160 = load double, ptr %159, align 8
  %161 = add i64 %157, %95
  %162 = getelementptr double, ptr %23, i64 %161
  %163 = load double, ptr %162, align 8
  %164 = fmul fast double %163, %160
  %165 = fadd fast double %164, %156
  %166 = add nuw nsw i64 %157, 1
  %exitcond57.not.1 = icmp eq i64 %166, %14
  br i1 %exitcond57.not.1, label %._crit_edge33.us.us.us.1, label %scalar.ph.1, !llvm.loop !6

._crit_edge33.us.us.us.1:                         ; preds = %scalar.ph.1, %middle.block.1
  %.lcssa.1 = phi double [ %155, %middle.block.1 ], [ %165, %scalar.ph.1 ]
  %167 = add i64 %134, %96
  %168 = getelementptr double, ptr %21, i64 %167
  %169 = load double, ptr %168, align 8
  %170 = fadd fast double %169, %.lcssa.1
  store double %170, ptr %168, align 8
  %171 = or i64 %97, 2
  %172 = mul i64 %171, %14
  br i1 %min.iters.check.2, label %scalar.ph.preheader.2, label %vector.body.2

vector.body.2:                                    ; preds = %._crit_edge33.us.us.us.1, %vector.body.2
  %index.2 = phi i64 [ %index.next.2, %vector.body.2 ], [ 0, %._crit_edge33.us.us.us.1 ]
  %vec.phi.2 = phi <4 x double> [ %187, %vector.body.2 ], [ zeroinitializer, %._crit_edge33.us.us.us.1 ]
  %vec.phi64.2 = phi <4 x double> [ %188, %vector.body.2 ], [ zeroinitializer, %._crit_edge33.us.us.us.1 ]
  %vec.phi65.2 = phi <4 x double> [ %189, %vector.body.2 ], [ zeroinitializer, %._crit_edge33.us.us.us.1 ]
  %vec.phi66.2 = phi <4 x double> [ %190, %vector.body.2 ], [ zeroinitializer, %._crit_edge33.us.us.us.1 ]
  %173 = add nsw i64 %index.2, %172
  %174 = getelementptr double, ptr %25, i64 %173
  %wide.load.2 = load <4 x double>, ptr %174, align 8
  %175 = getelementptr double, ptr %174, i64 4
  %wide.load67.2 = load <4 x double>, ptr %175, align 8
  %176 = getelementptr double, ptr %174, i64 8
  %wide.load68.2 = load <4 x double>, ptr %176, align 8
  %177 = getelementptr double, ptr %174, i64 12
  %wide.load69.2 = load <4 x double>, ptr %177, align 8
  %178 = add i64 %index.2, %95
  %179 = getelementptr double, ptr %23, i64 %178
  %wide.load70.2 = load <4 x double>, ptr %179, align 8
  %180 = getelementptr double, ptr %179, i64 4
  %wide.load71.2 = load <4 x double>, ptr %180, align 8
  %181 = getelementptr double, ptr %179, i64 8
  %wide.load72.2 = load <4 x double>, ptr %181, align 8
  %182 = getelementptr double, ptr %179, i64 12
  %wide.load73.2 = load <4 x double>, ptr %182, align 8
  %183 = fmul fast <4 x double> %wide.load70.2, %wide.load.2
  %184 = fmul fast <4 x double> %wide.load71.2, %wide.load67.2
  %185 = fmul fast <4 x double> %wide.load72.2, %wide.load68.2
  %186 = fmul fast <4 x double> %wide.load73.2, %wide.load69.2
  %187 = fadd fast <4 x double> %183, %vec.phi.2
  %188 = fadd fast <4 x double> %184, %vec.phi64.2
  %189 = fadd fast <4 x double> %185, %vec.phi65.2
  %190 = fadd fast <4 x double> %186, %vec.phi66.2
  %index.next.2 = add nuw i64 %index.2, 16
  %191 = icmp eq i64 %index.next.2, %n.vec.2
  br i1 %191, label %middle.block.2, label %vector.body.2, !llvm.loop !3

middle.block.2:                                   ; preds = %vector.body.2
  %bin.rdx.2 = fadd fast <4 x double> %188, %187
  %bin.rdx74.2 = fadd fast <4 x double> %189, %bin.rdx.2
  %bin.rdx75.2 = fadd fast <4 x double> %190, %bin.rdx74.2
  %192 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.2)
  br i1 %cmp.n.2, label %._crit_edge33.us.us.us.2, label %scalar.ph.preheader.2

scalar.ph.preheader.2:                            ; preds = %middle.block.2, %._crit_edge33.us.us.us.1
  %.ph.2 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us.1 ], [ %192, %middle.block.2 ]
  %.ph76.2 = phi i64 [ 0, %._crit_edge33.us.us.us.1 ], [ %n.vec.2, %middle.block.2 ]
  br label %scalar.ph.2

scalar.ph.2:                                      ; preds = %scalar.ph.2, %scalar.ph.preheader.2
  %193 = phi double [ %202, %scalar.ph.2 ], [ %.ph.2, %scalar.ph.preheader.2 ]
  %194 = phi i64 [ %203, %scalar.ph.2 ], [ %.ph76.2, %scalar.ph.preheader.2 ]
  %195 = add nsw i64 %194, %172
  %196 = getelementptr double, ptr %25, i64 %195
  %197 = load double, ptr %196, align 8
  %198 = add i64 %194, %95
  %199 = getelementptr double, ptr %23, i64 %198
  %200 = load double, ptr %199, align 8
  %201 = fmul fast double %200, %197
  %202 = fadd fast double %201, %193
  %203 = add nuw nsw i64 %194, 1
  %exitcond57.not.2 = icmp eq i64 %203, %14
  br i1 %exitcond57.not.2, label %._crit_edge33.us.us.us.2, label %scalar.ph.2, !llvm.loop !6

._crit_edge33.us.us.us.2:                         ; preds = %scalar.ph.2, %middle.block.2
  %.lcssa.2 = phi double [ %192, %middle.block.2 ], [ %202, %scalar.ph.2 ]
  %204 = add i64 %171, %96
  %205 = getelementptr double, ptr %21, i64 %204
  %206 = load double, ptr %205, align 8
  %207 = fadd fast double %206, %.lcssa.2
  store double %207, ptr %205, align 8
  %208 = or i64 %97, 3
  %209 = mul i64 %208, %14
  br i1 %min.iters.check.3, label %scalar.ph.preheader.3, label %vector.body.3

vector.body.3:                                    ; preds = %._crit_edge33.us.us.us.2, %vector.body.3
  %index.3 = phi i64 [ %index.next.3, %vector.body.3 ], [ 0, %._crit_edge33.us.us.us.2 ]
  %vec.phi.3 = phi <4 x double> [ %224, %vector.body.3 ], [ zeroinitializer, %._crit_edge33.us.us.us.2 ]
  %vec.phi64.3 = phi <4 x double> [ %225, %vector.body.3 ], [ zeroinitializer, %._crit_edge33.us.us.us.2 ]
  %vec.phi65.3 = phi <4 x double> [ %226, %vector.body.3 ], [ zeroinitializer, %._crit_edge33.us.us.us.2 ]
  %vec.phi66.3 = phi <4 x double> [ %227, %vector.body.3 ], [ zeroinitializer, %._crit_edge33.us.us.us.2 ]
  %210 = add nsw i64 %index.3, %209
  %211 = getelementptr double, ptr %25, i64 %210
  %wide.load.3 = load <4 x double>, ptr %211, align 8
  %212 = getelementptr double, ptr %211, i64 4
  %wide.load67.3 = load <4 x double>, ptr %212, align 8
  %213 = getelementptr double, ptr %211, i64 8
  %wide.load68.3 = load <4 x double>, ptr %213, align 8
  %214 = getelementptr double, ptr %211, i64 12
  %wide.load69.3 = load <4 x double>, ptr %214, align 8
  %215 = add i64 %index.3, %95
  %216 = getelementptr double, ptr %23, i64 %215
  %wide.load70.3 = load <4 x double>, ptr %216, align 8
  %217 = getelementptr double, ptr %216, i64 4
  %wide.load71.3 = load <4 x double>, ptr %217, align 8
  %218 = getelementptr double, ptr %216, i64 8
  %wide.load72.3 = load <4 x double>, ptr %218, align 8
  %219 = getelementptr double, ptr %216, i64 12
  %wide.load73.3 = load <4 x double>, ptr %219, align 8
  %220 = fmul fast <4 x double> %wide.load70.3, %wide.load.3
  %221 = fmul fast <4 x double> %wide.load71.3, %wide.load67.3
  %222 = fmul fast <4 x double> %wide.load72.3, %wide.load68.3
  %223 = fmul fast <4 x double> %wide.load73.3, %wide.load69.3
  %224 = fadd fast <4 x double> %220, %vec.phi.3
  %225 = fadd fast <4 x double> %221, %vec.phi64.3
  %226 = fadd fast <4 x double> %222, %vec.phi65.3
  %227 = fadd fast <4 x double> %223, %vec.phi66.3
  %index.next.3 = add nuw i64 %index.3, 16
  %228 = icmp eq i64 %index.next.3, %n.vec.3
  br i1 %228, label %middle.block.3, label %vector.body.3, !llvm.loop !3

middle.block.3:                                   ; preds = %vector.body.3
  %bin.rdx.3 = fadd fast <4 x double> %225, %224
  %bin.rdx74.3 = fadd fast <4 x double> %226, %bin.rdx.3
  %bin.rdx75.3 = fadd fast <4 x double> %227, %bin.rdx74.3
  %229 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.3)
  br i1 %cmp.n.3, label %._crit_edge33.us.us.us.3, label %scalar.ph.preheader.3

scalar.ph.preheader.3:                            ; preds = %middle.block.3, %._crit_edge33.us.us.us.2
  %.ph.3 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us.2 ], [ %229, %middle.block.3 ]
  %.ph76.3 = phi i64 [ 0, %._crit_edge33.us.us.us.2 ], [ %n.vec.3, %middle.block.3 ]
  br label %scalar.ph.3

scalar.ph.3:                                      ; preds = %scalar.ph.3, %scalar.ph.preheader.3
  %230 = phi double [ %239, %scalar.ph.3 ], [ %.ph.3, %scalar.ph.preheader.3 ]
  %231 = phi i64 [ %240, %scalar.ph.3 ], [ %.ph76.3, %scalar.ph.preheader.3 ]
  %232 = add nsw i64 %231, %209
  %233 = getelementptr double, ptr %25, i64 %232
  %234 = load double, ptr %233, align 8
  %235 = add i64 %231, %95
  %236 = getelementptr double, ptr %23, i64 %235
  %237 = load double, ptr %236, align 8
  %238 = fmul fast double %237, %234
  %239 = fadd fast double %238, %230
  %240 = add nuw nsw i64 %231, 1
  %exitcond57.not.3 = icmp eq i64 %240, %14
  br i1 %exitcond57.not.3, label %._crit_edge33.us.us.us.3, label %scalar.ph.3, !llvm.loop !6

._crit_edge33.us.us.us.3:                         ; preds = %scalar.ph.3, %middle.block.3
  %.lcssa.3 = phi double [ %229, %middle.block.3 ], [ %239, %scalar.ph.3 ]
  %241 = add i64 %208, %96
  %242 = getelementptr double, ptr %21, i64 %241
  %243 = load double, ptr %242, align 8
  %244 = fadd fast double %243, %.lcssa.3
  store double %244, ptr %242, align 8
  %245 = or i64 %97, 4
  %246 = mul i64 %245, %14
  br i1 %min.iters.check.4, label %scalar.ph.preheader.4, label %vector.body.4

vector.body.4:                                    ; preds = %._crit_edge33.us.us.us.3, %vector.body.4
  %index.4 = phi i64 [ %index.next.4, %vector.body.4 ], [ 0, %._crit_edge33.us.us.us.3 ]
  %vec.phi.4 = phi <4 x double> [ %261, %vector.body.4 ], [ zeroinitializer, %._crit_edge33.us.us.us.3 ]
  %vec.phi64.4 = phi <4 x double> [ %262, %vector.body.4 ], [ zeroinitializer, %._crit_edge33.us.us.us.3 ]
  %vec.phi65.4 = phi <4 x double> [ %263, %vector.body.4 ], [ zeroinitializer, %._crit_edge33.us.us.us.3 ]
  %vec.phi66.4 = phi <4 x double> [ %264, %vector.body.4 ], [ zeroinitializer, %._crit_edge33.us.us.us.3 ]
  %247 = add nsw i64 %index.4, %246
  %248 = getelementptr double, ptr %25, i64 %247
  %wide.load.4 = load <4 x double>, ptr %248, align 8
  %249 = getelementptr double, ptr %248, i64 4
  %wide.load67.4 = load <4 x double>, ptr %249, align 8
  %250 = getelementptr double, ptr %248, i64 8
  %wide.load68.4 = load <4 x double>, ptr %250, align 8
  %251 = getelementptr double, ptr %248, i64 12
  %wide.load69.4 = load <4 x double>, ptr %251, align 8
  %252 = add i64 %index.4, %95
  %253 = getelementptr double, ptr %23, i64 %252
  %wide.load70.4 = load <4 x double>, ptr %253, align 8
  %254 = getelementptr double, ptr %253, i64 4
  %wide.load71.4 = load <4 x double>, ptr %254, align 8
  %255 = getelementptr double, ptr %253, i64 8
  %wide.load72.4 = load <4 x double>, ptr %255, align 8
  %256 = getelementptr double, ptr %253, i64 12
  %wide.load73.4 = load <4 x double>, ptr %256, align 8
  %257 = fmul fast <4 x double> %wide.load70.4, %wide.load.4
  %258 = fmul fast <4 x double> %wide.load71.4, %wide.load67.4
  %259 = fmul fast <4 x double> %wide.load72.4, %wide.load68.4
  %260 = fmul fast <4 x double> %wide.load73.4, %wide.load69.4
  %261 = fadd fast <4 x double> %257, %vec.phi.4
  %262 = fadd fast <4 x double> %258, %vec.phi64.4
  %263 = fadd fast <4 x double> %259, %vec.phi65.4
  %264 = fadd fast <4 x double> %260, %vec.phi66.4
  %index.next.4 = add nuw i64 %index.4, 16
  %265 = icmp eq i64 %index.next.4, %n.vec.4
  br i1 %265, label %middle.block.4, label %vector.body.4, !llvm.loop !3

middle.block.4:                                   ; preds = %vector.body.4
  %bin.rdx.4 = fadd fast <4 x double> %262, %261
  %bin.rdx74.4 = fadd fast <4 x double> %263, %bin.rdx.4
  %bin.rdx75.4 = fadd fast <4 x double> %264, %bin.rdx74.4
  %266 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.4)
  br i1 %cmp.n.4, label %._crit_edge33.us.us.us.4, label %scalar.ph.preheader.4

scalar.ph.preheader.4:                            ; preds = %middle.block.4, %._crit_edge33.us.us.us.3
  %.ph.4 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us.3 ], [ %266, %middle.block.4 ]
  %.ph76.4 = phi i64 [ 0, %._crit_edge33.us.us.us.3 ], [ %n.vec.4, %middle.block.4 ]
  br label %scalar.ph.4

scalar.ph.4:                                      ; preds = %scalar.ph.4, %scalar.ph.preheader.4
  %267 = phi double [ %276, %scalar.ph.4 ], [ %.ph.4, %scalar.ph.preheader.4 ]
  %268 = phi i64 [ %277, %scalar.ph.4 ], [ %.ph76.4, %scalar.ph.preheader.4 ]
  %269 = add nsw i64 %268, %246
  %270 = getelementptr double, ptr %25, i64 %269
  %271 = load double, ptr %270, align 8
  %272 = add i64 %268, %95
  %273 = getelementptr double, ptr %23, i64 %272
  %274 = load double, ptr %273, align 8
  %275 = fmul fast double %274, %271
  %276 = fadd fast double %275, %267
  %277 = add nuw nsw i64 %268, 1
  %exitcond57.not.4 = icmp eq i64 %277, %14
  br i1 %exitcond57.not.4, label %._crit_edge33.us.us.us.4, label %scalar.ph.4, !llvm.loop !6

._crit_edge33.us.us.us.4:                         ; preds = %scalar.ph.4, %middle.block.4
  %.lcssa.4 = phi double [ %266, %middle.block.4 ], [ %276, %scalar.ph.4 ]
  %278 = add i64 %245, %96
  %279 = getelementptr double, ptr %21, i64 %278
  %280 = load double, ptr %279, align 8
  %281 = fadd fast double %280, %.lcssa.4
  store double %281, ptr %279, align 8
  %282 = or i64 %97, 5
  %283 = mul i64 %282, %14
  br i1 %min.iters.check.5, label %scalar.ph.preheader.5, label %vector.body.5

vector.body.5:                                    ; preds = %._crit_edge33.us.us.us.4, %vector.body.5
  %index.5 = phi i64 [ %index.next.5, %vector.body.5 ], [ 0, %._crit_edge33.us.us.us.4 ]
  %vec.phi.5 = phi <4 x double> [ %298, %vector.body.5 ], [ zeroinitializer, %._crit_edge33.us.us.us.4 ]
  %vec.phi64.5 = phi <4 x double> [ %299, %vector.body.5 ], [ zeroinitializer, %._crit_edge33.us.us.us.4 ]
  %vec.phi65.5 = phi <4 x double> [ %300, %vector.body.5 ], [ zeroinitializer, %._crit_edge33.us.us.us.4 ]
  %vec.phi66.5 = phi <4 x double> [ %301, %vector.body.5 ], [ zeroinitializer, %._crit_edge33.us.us.us.4 ]
  %284 = add nsw i64 %index.5, %283
  %285 = getelementptr double, ptr %25, i64 %284
  %wide.load.5 = load <4 x double>, ptr %285, align 8
  %286 = getelementptr double, ptr %285, i64 4
  %wide.load67.5 = load <4 x double>, ptr %286, align 8
  %287 = getelementptr double, ptr %285, i64 8
  %wide.load68.5 = load <4 x double>, ptr %287, align 8
  %288 = getelementptr double, ptr %285, i64 12
  %wide.load69.5 = load <4 x double>, ptr %288, align 8
  %289 = add i64 %index.5, %95
  %290 = getelementptr double, ptr %23, i64 %289
  %wide.load70.5 = load <4 x double>, ptr %290, align 8
  %291 = getelementptr double, ptr %290, i64 4
  %wide.load71.5 = load <4 x double>, ptr %291, align 8
  %292 = getelementptr double, ptr %290, i64 8
  %wide.load72.5 = load <4 x double>, ptr %292, align 8
  %293 = getelementptr double, ptr %290, i64 12
  %wide.load73.5 = load <4 x double>, ptr %293, align 8
  %294 = fmul fast <4 x double> %wide.load70.5, %wide.load.5
  %295 = fmul fast <4 x double> %wide.load71.5, %wide.load67.5
  %296 = fmul fast <4 x double> %wide.load72.5, %wide.load68.5
  %297 = fmul fast <4 x double> %wide.load73.5, %wide.load69.5
  %298 = fadd fast <4 x double> %294, %vec.phi.5
  %299 = fadd fast <4 x double> %295, %vec.phi64.5
  %300 = fadd fast <4 x double> %296, %vec.phi65.5
  %301 = fadd fast <4 x double> %297, %vec.phi66.5
  %index.next.5 = add nuw i64 %index.5, 16
  %302 = icmp eq i64 %index.next.5, %n.vec.5
  br i1 %302, label %middle.block.5, label %vector.body.5, !llvm.loop !3

middle.block.5:                                   ; preds = %vector.body.5
  %bin.rdx.5 = fadd fast <4 x double> %299, %298
  %bin.rdx74.5 = fadd fast <4 x double> %300, %bin.rdx.5
  %bin.rdx75.5 = fadd fast <4 x double> %301, %bin.rdx74.5
  %303 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.5)
  br i1 %cmp.n.5, label %._crit_edge33.us.us.us.5, label %scalar.ph.preheader.5

scalar.ph.preheader.5:                            ; preds = %middle.block.5, %._crit_edge33.us.us.us.4
  %.ph.5 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us.4 ], [ %303, %middle.block.5 ]
  %.ph76.5 = phi i64 [ 0, %._crit_edge33.us.us.us.4 ], [ %n.vec.5, %middle.block.5 ]
  br label %scalar.ph.5

scalar.ph.5:                                      ; preds = %scalar.ph.5, %scalar.ph.preheader.5
  %304 = phi double [ %313, %scalar.ph.5 ], [ %.ph.5, %scalar.ph.preheader.5 ]
  %305 = phi i64 [ %314, %scalar.ph.5 ], [ %.ph76.5, %scalar.ph.preheader.5 ]
  %306 = add nsw i64 %305, %283
  %307 = getelementptr double, ptr %25, i64 %306
  %308 = load double, ptr %307, align 8
  %309 = add i64 %305, %95
  %310 = getelementptr double, ptr %23, i64 %309
  %311 = load double, ptr %310, align 8
  %312 = fmul fast double %311, %308
  %313 = fadd fast double %312, %304
  %314 = add nuw nsw i64 %305, 1
  %exitcond57.not.5 = icmp eq i64 %314, %14
  br i1 %exitcond57.not.5, label %._crit_edge33.us.us.us.5, label %scalar.ph.5, !llvm.loop !6

._crit_edge33.us.us.us.5:                         ; preds = %scalar.ph.5, %middle.block.5
  %.lcssa.5 = phi double [ %303, %middle.block.5 ], [ %313, %scalar.ph.5 ]
  %315 = add i64 %282, %96
  %316 = getelementptr double, ptr %21, i64 %315
  %317 = load double, ptr %316, align 8
  %318 = fadd fast double %317, %.lcssa.5
  store double %318, ptr %316, align 8
  %319 = or i64 %97, 6
  %320 = mul i64 %319, %14
  br i1 %min.iters.check.6, label %scalar.ph.preheader.6, label %vector.body.6

vector.body.6:                                    ; preds = %._crit_edge33.us.us.us.5, %vector.body.6
  %index.6 = phi i64 [ %index.next.6, %vector.body.6 ], [ 0, %._crit_edge33.us.us.us.5 ]
  %vec.phi.6 = phi <4 x double> [ %335, %vector.body.6 ], [ zeroinitializer, %._crit_edge33.us.us.us.5 ]
  %vec.phi64.6 = phi <4 x double> [ %336, %vector.body.6 ], [ zeroinitializer, %._crit_edge33.us.us.us.5 ]
  %vec.phi65.6 = phi <4 x double> [ %337, %vector.body.6 ], [ zeroinitializer, %._crit_edge33.us.us.us.5 ]
  %vec.phi66.6 = phi <4 x double> [ %338, %vector.body.6 ], [ zeroinitializer, %._crit_edge33.us.us.us.5 ]
  %321 = add nsw i64 %index.6, %320
  %322 = getelementptr double, ptr %25, i64 %321
  %wide.load.6 = load <4 x double>, ptr %322, align 8
  %323 = getelementptr double, ptr %322, i64 4
  %wide.load67.6 = load <4 x double>, ptr %323, align 8
  %324 = getelementptr double, ptr %322, i64 8
  %wide.load68.6 = load <4 x double>, ptr %324, align 8
  %325 = getelementptr double, ptr %322, i64 12
  %wide.load69.6 = load <4 x double>, ptr %325, align 8
  %326 = add i64 %index.6, %95
  %327 = getelementptr double, ptr %23, i64 %326
  %wide.load70.6 = load <4 x double>, ptr %327, align 8
  %328 = getelementptr double, ptr %327, i64 4
  %wide.load71.6 = load <4 x double>, ptr %328, align 8
  %329 = getelementptr double, ptr %327, i64 8
  %wide.load72.6 = load <4 x double>, ptr %329, align 8
  %330 = getelementptr double, ptr %327, i64 12
  %wide.load73.6 = load <4 x double>, ptr %330, align 8
  %331 = fmul fast <4 x double> %wide.load70.6, %wide.load.6
  %332 = fmul fast <4 x double> %wide.load71.6, %wide.load67.6
  %333 = fmul fast <4 x double> %wide.load72.6, %wide.load68.6
  %334 = fmul fast <4 x double> %wide.load73.6, %wide.load69.6
  %335 = fadd fast <4 x double> %331, %vec.phi.6
  %336 = fadd fast <4 x double> %332, %vec.phi64.6
  %337 = fadd fast <4 x double> %333, %vec.phi65.6
  %338 = fadd fast <4 x double> %334, %vec.phi66.6
  %index.next.6 = add nuw i64 %index.6, 16
  %339 = icmp eq i64 %index.next.6, %n.vec.6
  br i1 %339, label %middle.block.6, label %vector.body.6, !llvm.loop !3

middle.block.6:                                   ; preds = %vector.body.6
  %bin.rdx.6 = fadd fast <4 x double> %336, %335
  %bin.rdx74.6 = fadd fast <4 x double> %337, %bin.rdx.6
  %bin.rdx75.6 = fadd fast <4 x double> %338, %bin.rdx74.6
  %340 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.6)
  br i1 %cmp.n.6, label %._crit_edge33.us.us.us.6, label %scalar.ph.preheader.6

scalar.ph.preheader.6:                            ; preds = %middle.block.6, %._crit_edge33.us.us.us.5
  %.ph.6 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us.5 ], [ %340, %middle.block.6 ]
  %.ph76.6 = phi i64 [ 0, %._crit_edge33.us.us.us.5 ], [ %n.vec.6, %middle.block.6 ]
  br label %scalar.ph.6

scalar.ph.6:                                      ; preds = %scalar.ph.6, %scalar.ph.preheader.6
  %341 = phi double [ %350, %scalar.ph.6 ], [ %.ph.6, %scalar.ph.preheader.6 ]
  %342 = phi i64 [ %351, %scalar.ph.6 ], [ %.ph76.6, %scalar.ph.preheader.6 ]
  %343 = add nsw i64 %342, %320
  %344 = getelementptr double, ptr %25, i64 %343
  %345 = load double, ptr %344, align 8
  %346 = add i64 %342, %95
  %347 = getelementptr double, ptr %23, i64 %346
  %348 = load double, ptr %347, align 8
  %349 = fmul fast double %348, %345
  %350 = fadd fast double %349, %341
  %351 = add nuw nsw i64 %342, 1
  %exitcond57.not.6 = icmp eq i64 %351, %14
  br i1 %exitcond57.not.6, label %._crit_edge33.us.us.us.6, label %scalar.ph.6, !llvm.loop !6

._crit_edge33.us.us.us.6:                         ; preds = %scalar.ph.6, %middle.block.6
  %.lcssa.6 = phi double [ %340, %middle.block.6 ], [ %350, %scalar.ph.6 ]
  %352 = add i64 %319, %96
  %353 = getelementptr double, ptr %21, i64 %352
  %354 = load double, ptr %353, align 8
  %355 = fadd fast double %354, %.lcssa.6
  store double %355, ptr %353, align 8
  %356 = or i64 %97, 7
  %357 = mul i64 %356, %14
  br i1 %min.iters.check.7, label %scalar.ph.preheader.7, label %vector.body.7

vector.body.7:                                    ; preds = %._crit_edge33.us.us.us.6, %vector.body.7
  %index.7 = phi i64 [ %index.next.7, %vector.body.7 ], [ 0, %._crit_edge33.us.us.us.6 ]
  %vec.phi.7 = phi <4 x double> [ %372, %vector.body.7 ], [ zeroinitializer, %._crit_edge33.us.us.us.6 ]
  %vec.phi64.7 = phi <4 x double> [ %373, %vector.body.7 ], [ zeroinitializer, %._crit_edge33.us.us.us.6 ]
  %vec.phi65.7 = phi <4 x double> [ %374, %vector.body.7 ], [ zeroinitializer, %._crit_edge33.us.us.us.6 ]
  %vec.phi66.7 = phi <4 x double> [ %375, %vector.body.7 ], [ zeroinitializer, %._crit_edge33.us.us.us.6 ]
  %358 = add nsw i64 %index.7, %357
  %359 = getelementptr double, ptr %25, i64 %358
  %wide.load.7 = load <4 x double>, ptr %359, align 8
  %360 = getelementptr double, ptr %359, i64 4
  %wide.load67.7 = load <4 x double>, ptr %360, align 8
  %361 = getelementptr double, ptr %359, i64 8
  %wide.load68.7 = load <4 x double>, ptr %361, align 8
  %362 = getelementptr double, ptr %359, i64 12
  %wide.load69.7 = load <4 x double>, ptr %362, align 8
  %363 = add i64 %index.7, %95
  %364 = getelementptr double, ptr %23, i64 %363
  %wide.load70.7 = load <4 x double>, ptr %364, align 8
  %365 = getelementptr double, ptr %364, i64 4
  %wide.load71.7 = load <4 x double>, ptr %365, align 8
  %366 = getelementptr double, ptr %364, i64 8
  %wide.load72.7 = load <4 x double>, ptr %366, align 8
  %367 = getelementptr double, ptr %364, i64 12
  %wide.load73.7 = load <4 x double>, ptr %367, align 8
  %368 = fmul fast <4 x double> %wide.load70.7, %wide.load.7
  %369 = fmul fast <4 x double> %wide.load71.7, %wide.load67.7
  %370 = fmul fast <4 x double> %wide.load72.7, %wide.load68.7
  %371 = fmul fast <4 x double> %wide.load73.7, %wide.load69.7
  %372 = fadd fast <4 x double> %368, %vec.phi.7
  %373 = fadd fast <4 x double> %369, %vec.phi64.7
  %374 = fadd fast <4 x double> %370, %vec.phi65.7
  %375 = fadd fast <4 x double> %371, %vec.phi66.7
  %index.next.7 = add nuw i64 %index.7, 16
  %376 = icmp eq i64 %index.next.7, %n.vec.7
  br i1 %376, label %middle.block.7, label %vector.body.7, !llvm.loop !3

middle.block.7:                                   ; preds = %vector.body.7
  %bin.rdx.7 = fadd fast <4 x double> %373, %372
  %bin.rdx74.7 = fadd fast <4 x double> %374, %bin.rdx.7
  %bin.rdx75.7 = fadd fast <4 x double> %375, %bin.rdx74.7
  %377 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.7)
  br i1 %cmp.n.7, label %._crit_edge33.us.us.us.7, label %scalar.ph.preheader.7

scalar.ph.preheader.7:                            ; preds = %middle.block.7, %._crit_edge33.us.us.us.6
  %.ph.7 = phi double [ 0.000000e+00, %._crit_edge33.us.us.us.6 ], [ %377, %middle.block.7 ]
  %.ph76.7 = phi i64 [ 0, %._crit_edge33.us.us.us.6 ], [ %n.vec.7, %middle.block.7 ]
  br label %scalar.ph.7

scalar.ph.7:                                      ; preds = %scalar.ph.7, %scalar.ph.preheader.7
  %378 = phi double [ %387, %scalar.ph.7 ], [ %.ph.7, %scalar.ph.preheader.7 ]
  %379 = phi i64 [ %388, %scalar.ph.7 ], [ %.ph76.7, %scalar.ph.preheader.7 ]
  %380 = add nsw i64 %379, %357
  %381 = getelementptr double, ptr %25, i64 %380
  %382 = load double, ptr %381, align 8
  %383 = add i64 %379, %95
  %384 = getelementptr double, ptr %23, i64 %383
  %385 = load double, ptr %384, align 8
  %386 = fmul fast double %385, %382
  %387 = fadd fast double %386, %378
  %388 = add nuw nsw i64 %379, 1
  %exitcond57.not.7 = icmp eq i64 %388, %14
  br i1 %exitcond57.not.7, label %._crit_edge33.us.us.us.7, label %scalar.ph.7, !llvm.loop !6

._crit_edge33.us.us.us.7:                         ; preds = %scalar.ph.7, %middle.block.7
  %.lcssa.7 = phi double [ %377, %middle.block.7 ], [ %387, %scalar.ph.7 ]
  %389 = add i64 %356, %96
  %390 = getelementptr double, ptr %21, i64 %389
  %391 = load double, ptr %390, align 8
  %392 = fadd fast double %391, %.lcssa.7
  store double %392, ptr %390, align 8
  %393 = add nuw nsw i64 %97, 8
  %niter87.next.7 = add i64 %niter87, 8
  %niter87.ncmp.7 = icmp eq i64 %niter87.next.7, %unroll_iter86
  br i1 %niter87.ncmp.7, label %._crit_edge36.split.us.us.us.unr-lcssa, label %.lr.ph32.us.us.us

._crit_edge36.split.us.us.us.unr-lcssa:           ; preds = %._crit_edge33.us.us.us.7, %.lr.ph35.us.us
  %.unr84 = phi i64 [ 0, %.lr.ph35.us.us ], [ %393, %._crit_edge33.us.us.us.7 ]
  br i1 %lcmp.mod85.not, label %._crit_edge36.split.us.us.us, label %.lr.ph32.us.us.us.epil

.lr.ph32.us.us.us.epil:                           ; preds = %._crit_edge36.split.us.us.us.unr-lcssa, %._crit_edge33.us.us.us.epil
  %394 = phi i64 [ %431, %._crit_edge33.us.us.us.epil ], [ %.unr84, %._crit_edge36.split.us.us.us.unr-lcssa ]
  %epil.iter83 = phi i64 [ %epil.iter83.next, %._crit_edge33.us.us.us.epil ], [ 0, %._crit_edge36.split.us.us.us.unr-lcssa ]
  %395 = mul i64 %394, %14
  br i1 %min.iters.check.epil, label %scalar.ph.preheader.epil, label %vector.body.epil

vector.body.epil:                                 ; preds = %.lr.ph32.us.us.us.epil, %vector.body.epil
  %index.epil = phi i64 [ %index.next.epil, %vector.body.epil ], [ 0, %.lr.ph32.us.us.us.epil ]
  %vec.phi.epil = phi <4 x double> [ %410, %vector.body.epil ], [ zeroinitializer, %.lr.ph32.us.us.us.epil ]
  %vec.phi64.epil = phi <4 x double> [ %411, %vector.body.epil ], [ zeroinitializer, %.lr.ph32.us.us.us.epil ]
  %vec.phi65.epil = phi <4 x double> [ %412, %vector.body.epil ], [ zeroinitializer, %.lr.ph32.us.us.us.epil ]
  %vec.phi66.epil = phi <4 x double> [ %413, %vector.body.epil ], [ zeroinitializer, %.lr.ph32.us.us.us.epil ]
  %396 = add nsw i64 %index.epil, %395
  %397 = getelementptr double, ptr %25, i64 %396
  %wide.load.epil = load <4 x double>, ptr %397, align 8
  %398 = getelementptr double, ptr %397, i64 4
  %wide.load67.epil = load <4 x double>, ptr %398, align 8
  %399 = getelementptr double, ptr %397, i64 8
  %wide.load68.epil = load <4 x double>, ptr %399, align 8
  %400 = getelementptr double, ptr %397, i64 12
  %wide.load69.epil = load <4 x double>, ptr %400, align 8
  %401 = add i64 %index.epil, %95
  %402 = getelementptr double, ptr %23, i64 %401
  %wide.load70.epil = load <4 x double>, ptr %402, align 8
  %403 = getelementptr double, ptr %402, i64 4
  %wide.load71.epil = load <4 x double>, ptr %403, align 8
  %404 = getelementptr double, ptr %402, i64 8
  %wide.load72.epil = load <4 x double>, ptr %404, align 8
  %405 = getelementptr double, ptr %402, i64 12
  %wide.load73.epil = load <4 x double>, ptr %405, align 8
  %406 = fmul fast <4 x double> %wide.load70.epil, %wide.load.epil
  %407 = fmul fast <4 x double> %wide.load71.epil, %wide.load67.epil
  %408 = fmul fast <4 x double> %wide.load72.epil, %wide.load68.epil
  %409 = fmul fast <4 x double> %wide.load73.epil, %wide.load69.epil
  %410 = fadd fast <4 x double> %406, %vec.phi.epil
  %411 = fadd fast <4 x double> %407, %vec.phi64.epil
  %412 = fadd fast <4 x double> %408, %vec.phi65.epil
  %413 = fadd fast <4 x double> %409, %vec.phi66.epil
  %index.next.epil = add nuw i64 %index.epil, 16
  %414 = icmp eq i64 %index.next.epil, %n.vec.epil
  br i1 %414, label %middle.block.epil, label %vector.body.epil, !llvm.loop !3

middle.block.epil:                                ; preds = %vector.body.epil
  %bin.rdx.epil = fadd fast <4 x double> %411, %410
  %bin.rdx74.epil = fadd fast <4 x double> %412, %bin.rdx.epil
  %bin.rdx75.epil = fadd fast <4 x double> %413, %bin.rdx74.epil
  %415 = tail call fast double @llvm.vector.reduce.fadd.v4f64(double -0.000000e+00, <4 x double> %bin.rdx75.epil)
  br i1 %cmp.n.epil, label %._crit_edge33.us.us.us.epil, label %scalar.ph.preheader.epil

scalar.ph.preheader.epil:                         ; preds = %middle.block.epil, %.lr.ph32.us.us.us.epil
  %.ph.epil = phi double [ 0.000000e+00, %.lr.ph32.us.us.us.epil ], [ %415, %middle.block.epil ]
  %.ph76.epil = phi i64 [ 0, %.lr.ph32.us.us.us.epil ], [ %n.vec.epil, %middle.block.epil ]
  br label %scalar.ph.epil

scalar.ph.epil:                                   ; preds = %scalar.ph.epil, %scalar.ph.preheader.epil
  %416 = phi double [ %425, %scalar.ph.epil ], [ %.ph.epil, %scalar.ph.preheader.epil ]
  %417 = phi i64 [ %426, %scalar.ph.epil ], [ %.ph76.epil, %scalar.ph.preheader.epil ]
  %418 = add nsw i64 %417, %395
  %419 = getelementptr double, ptr %25, i64 %418
  %420 = load double, ptr %419, align 8
  %421 = add i64 %417, %95
  %422 = getelementptr double, ptr %23, i64 %421
  %423 = load double, ptr %422, align 8
  %424 = fmul fast double %423, %420
  %425 = fadd fast double %424, %416
  %426 = add nuw nsw i64 %417, 1
  %exitcond57.not.epil = icmp eq i64 %426, %14
  br i1 %exitcond57.not.epil, label %._crit_edge33.us.us.us.epil, label %scalar.ph.epil, !llvm.loop !6

._crit_edge33.us.us.us.epil:                      ; preds = %scalar.ph.epil, %middle.block.epil
  %.lcssa.epil = phi double [ %415, %middle.block.epil ], [ %425, %scalar.ph.epil ]
  %427 = add i64 %394, %96
  %428 = getelementptr double, ptr %21, i64 %427
  %429 = load double, ptr %428, align 8
  %430 = fadd fast double %429, %.lcssa.epil
  store double %430, ptr %428, align 8
  %431 = add nuw nsw i64 %394, 1
  %epil.iter83.next = add i64 %epil.iter83, 1
  %epil.iter83.cmp.not = icmp eq i64 %epil.iter83.next, %xtraiter82
  br i1 %epil.iter83.cmp.not, label %._crit_edge36.split.us.us.us, label %.lr.ph32.us.us.us.epil, !llvm.loop !7

._crit_edge36.split.us.us.us:                     ; preds = %._crit_edge33.us.us.us.epil, %._crit_edge36.split.us.us.us.unr-lcssa
  %432 = add nuw nsw i64 %94, 1
  %exitcond59.not = icmp eq i64 %432, %88
  br i1 %exitcond59.not, label %._crit_edge39, label %.lr.ph35.us.us

._crit_edge39:                                    ; preds = %._crit_edge36.split.us.us.us, %.lr.ph38, %._crit_edge
  %433 = tail call i64 @timer_elapsed(i64 %87)
  %434 = load double, ptr %21, align 8
  tail call void @print_f64_cerr(double %434)
  tail call void @print_i64(i64 %433)
  ret void
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i64 @llvm.umin.i64(i64, i64) #2

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #3

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare double @llvm.vector.reduce.fadd.v4f64(double, <4 x double>) #4

attributes #0 = { mustprogress nofree nounwind willreturn allockind("alloc,uninitialized") allocsize(0) memory(inaccessiblemem: readwrite) "alloc-family"="malloc" }
attributes #1 = { mustprogress nofree nounwind willreturn memory(read) }
attributes #2 = { mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #3 = { nocallback nofree nounwind willreturn memory(argmem: write) }
attributes #4 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }

!llvm.module.flags = !{!0}

!0 = !{i32 2, !"Debug Info Version", i32 3}
!1 = distinct !{!1, !2}
!2 = !{!"llvm.loop.unroll.disable"}
!3 = distinct !{!3, !4, !5}
!4 = !{!"llvm.loop.isvectorized", i32 1}
!5 = !{!"llvm.loop.unroll.runtime.disable"}
!6 = distinct !{!6, !5, !4}
!7 = distinct !{!7, !2}
