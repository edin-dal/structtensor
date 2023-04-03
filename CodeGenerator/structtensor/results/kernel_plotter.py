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
    st_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['st'].to_numpy()[begin:end] / 1e6
    })
    nst_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['nst'].to_numpy()[begin:end] / 1e6
    })
    taco_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['taco'].to_numpy()[begin:end] / 1e6
    })
    if ("PR2" in out_name):
        taco_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end - 2],
        'y_axis': df['taco'].to_numpy()[begin:end - 2] / 1e6
    })
    numpy_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['numpy'].to_numpy()[begin:end] / 1e6
    })
    pytorch_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['pytorch'].to_numpy()[begin:end] / 1e6
    })
    tf_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['tf'].to_numpy()[begin:end] / 1e6
    })
    tf_jit_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['tf_jit'].to_numpy()[begin:end] / 1e6
    })
    plt.xticks(df['size'].to_numpy()[begin:end])
    plt.plot('x_axis', 'y_axis', data=nst_df, label="Naive", color='m', marker='o')
    plt.plot('x_axis', 'y_axis', data=numpy_df, label="Numpy", color='b', marker='o')
    plt.plot('x_axis', 'y_axis', data=pytorch_df, label="PyTorch", color='g', marker='o')
    plt.plot('x_axis', 'y_axis', data=tf_df, label="TensorFlow", color='r', marker='o')
    plt.plot('x_axis', 'y_axis', data=tf_jit_df, label="TensorFlow (XLA)", color='#3D1C02', marker='o')
    plt.plot('x_axis', 'y_axis', data=taco_df, label="TACO (Dense)", color='y', marker='o')
    plt.plot('x_axis', 'y_axis', data=st_df, label="StructTensor", color='c', marker='o')
    plt.xlabel('# Features')
    plt.ylabel('Time (s)')
    if out_name == 'LR_Covar':
        plt.legend(loc=4, ncol=1, fontsize='small')
    plt.title(title)
    plt.grid(axis='y', color = 'gray', linestyle = '--', linewidth = 0.4)
    plt.subplots_adjust(left=0.15, bottom=0.15, right=0.95, top=0.9)
    plt.savefig(f"charts/{out_name}.pdf")
    plt.clf()
