import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import os
import sys

if __name__ == '__main__':
    file_path = sys.argv[1]
    out_name = sys.argv[2]
    title = sys.argv[3]
    log_ = int(sys.argv[4])
    begin = 0
    if len(sys.argv) > 5:
        begin = int(sys.argv[5])
    scale = 1 / 2
    plt.rcParams["figure.figsize"] = (10 * scale, 7 * scale)
    if log_ != 10:
        plt.xscale('log', base=log_)
    plt.yscale('log', base=10)
    df = pd.read_csv(file_path)
    end = len(df['size'].to_numpy())
    if len(sys.argv) > 6:
        end = int(sys.argv[6])
    st_begin = np.where(df['our'].to_numpy()[begin:end] == 0)[0][-1] + 1 if len(np.where(df['our'].to_numpy()[begin:end] == 0)[0]) != 0 else begin
    st_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[st_begin:end],
        'y_axis': df['our'].to_numpy()[st_begin:end] / 1e6
    })
    dl_st_begin = np.where(df['our_sparse'].to_numpy()[begin:end] == 0)[0][-1] + 1 if len(np.where(df['our_sparse'].to_numpy()[begin:end] == 0)[0]) != 0 else begin
    dl_st_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[dl_st_begin:end],
        'y_axis': df['our_sparse'].to_numpy()[dl_st_begin:end] / 1e6
    })
    nst_begin = np.where(df['naive'].to_numpy()[begin:end] == 0)[0][-1] + 1 if len(np.where(df['naive'].to_numpy()[begin:end] == 0)[0]) != 0 else begin
    nst_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[nst_begin:end],
        'y_axis': df['naive'].to_numpy()[nst_begin:end] / 1e6
    })
    taco_smart_begin = np.where(df['taco_smart'].to_numpy()[begin:end] == 0)[0][-1] + 1 if len(np.where(df['taco_smart'].to_numpy()[begin:end] == 0)[0]) != 0 else begin
    taco_smart_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[taco_smart_begin:end],
        'y_axis': df['taco_smart'].to_numpy()[taco_smart_begin:end] / 1e6
    })
    taco_sparse_begin = np.where(df['taco_sparse'].to_numpy()[begin:end] == 0)[0][-1] + 1 if len(np.where(df['taco_sparse'].to_numpy()[begin:end] == 0)[0]) != 0 else begin
    taco_sparse_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[taco_sparse_begin:end],
        'y_axis': df['taco_sparse'].to_numpy()[taco_sparse_begin:end] / 1e6
    })
    taco_dense_begin = np.where(df['taco_dense'].to_numpy()[begin:end] == 0)[0][-1] + 1 if len(np.where(df['taco_dense'].to_numpy()[begin:end] == 0)[0]) != 0 else begin
    taco_dense_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[taco_dense_begin:end],
        'y_axis': df['taco_dense'].to_numpy()[taco_dense_begin:end] / 1e6
    })
   
   
    plt.xticks(df['size'].to_numpy()[begin:end])
    plt.plot('x_axis', 'y_axis', data=taco_dense_df, label="TACO (Dense)", color='y', marker='o')
    plt.plot('x_axis', 'y_axis', data= taco_sparse_df, label="TACO (Sparse)", color='#703be7', marker='o')
    plt.plot('x_axis', 'y_axis', data=taco_smart_df, label="TACO (Smart)", color='#6e750e', marker='o')
    plt.plot('x_axis', 'y_axis', data=nst_df, label="Naive", color='m', marker='o')
    # plt.plot('x_axis', 'y_axis', data=st_df, label="StructTensor", color='c', marker='o')
    # plt.plot('x_axis', 'y_axis', data=dl_st_df, label="StructTensor (DL)", color='#121145', marker='o')
    plt.plot('x_axis', 'y_axis', data=dl_st_df, label="StructTensor", color='c', marker='o')
    plt.xlabel('Dimension Size')
    plt.ylabel('Time (s)')
    if "TTM: Upper" in title:
        plt.legend()
    plt.title(title)
    plt.grid(axis='y', color = 'gray', linestyle = '--', linewidth = 0.4)
    plt.subplots_adjust(left=0.15, bottom=0.15, right=0.95, top=0.9)
    plt.savefig(f"charts/{out_name}.pdf")
    plt.clf()