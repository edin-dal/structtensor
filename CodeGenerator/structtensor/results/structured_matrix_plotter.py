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
    arg_set = int(sys.argv[5])
    mode = int(sys.argv[6])
    begin = 0
    if len(sys.argv) > 7:
        begin = int(sys.argv[7])
    scale = 1
    fig, ax = plt.subplots()
    plt.rcParams["figure.figsize"] = (10 * scale, 7 * scale)
    if log_ != 10:
        plt.xscale('log', base=log_)
    plt.yscale('log', base=10)
    df = pd.read_csv(file_path)
    end = len(df['size'].to_numpy())
    if len(sys.argv) > 8:
        end = int(sys.argv[8])
    df[df == 0] = 1
    dl_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['dl'].to_numpy()[begin:end] / 1e6
    })
    st_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['st'].to_numpy()[begin:end] / 1e6
    })
    nst_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['nst'].to_numpy()[begin:end] / 1e6
    })
    taco_dense_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['taco_dense'].to_numpy()[begin:end] / 1e6
    })
    taco_sparse_df = pd.DataFrame({
        'x_axis': df['size'].to_numpy()[begin:end],
        'y_axis': df['taco_sparse'].to_numpy()[begin:end] / 1e6
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
    
    if arg_set != 0:
        numpy_man_df = pd.DataFrame({
            'x_axis': df['size'].to_numpy()[begin:end],
            'y_axis': df['numpy_man'].to_numpy()[begin:end] / 1e6
        })
        pytorch_man_df = pd.DataFrame({
            'x_axis': df['size'].to_numpy()[begin:end],
            'y_axis': df['pytorch_man'].to_numpy()[begin:end] / 1e6
        })
        tf_man_df = pd.DataFrame({
            'x_axis': df['size'].to_numpy()[begin:end],
            'y_axis': df['tf_man'].to_numpy()[begin:end] / 1e6
        })
        tf_jit_man_df = pd.DataFrame({
            'x_axis': df['size'].to_numpy()[begin:end],
            'y_axis': df['tf_jit_man'].to_numpy()[begin:end] / 1e6
        })
    if df['size'].to_numpy()[begin] > 1000:
        sz = [int(x / 1000) for x in df['size'].to_numpy()]
        ax.set_xticks(df['size'].to_numpy()[begin:end], sz[begin:end])
    else:
        ax.set_xticks(df['size'].to_numpy()[begin:end])
    ax.plot('x_axis', 'y_axis', data=nst_df, label="Naive", color='m', marker='o')
    if arg_set < 2:
        ax.plot('x_axis', 'y_axis', data=numpy_df, label="Numpy", color='b', marker='o')
        ax.plot('x_axis', 'y_axis', data=pytorch_df, label="PyTorch", color='g', marker='o')
        ax.plot('x_axis', 'y_axis', data=tf_df, label="TensorFlow", color='r', marker='o')
        ax.plot('x_axis', 'y_axis', data=tf_jit_df, label="TensorFlow (XLA)", color='#3D1C02', marker='o')
    if arg_set == 0 or arg_set == 2:
        ax.plot('x_axis', 'y_axis', data=taco_dense_df, label="TACO (Dense)", color='y', marker='o')
        ax.plot('x_axis', 'y_axis', data=taco_sparse_df, label="TACO (Sparse)", color='#6b691e', marker='o')
    if mode == 0:
        ax.plot('x_axis', 'y_axis', data=st_df, label="StructTensor", color='c', marker='o')
    if mode == 1:
        ax.plot('x_axis', 'y_axis', data=dl_df, label="StructTensor", color='c', marker='o')
    if arg_set == 2:
        ax.plot('x_axis', 'y_axis', data=numpy_man_df, label="Numpy", color='b', marker='o')
        ax.plot('x_axis', 'y_axis', data=pytorch_man_df, label="PyTorch", color='g', marker='o')
        ax.plot('x_axis', 'y_axis', data=tf_man_df, label="TensorFlow", color='r', marker='o')
        ax.plot('x_axis', 'y_axis', data=tf_jit_man_df, label="TensorFlow (XLA)", color='#3D1C02', marker='o')
    if df['size'].to_numpy()[begin] > 1000:
        plt.xlabel(r'# Features ($\times 10^3$)')
    else:
        plt.xlabel('# Features')
    plt.ylabel('Time (s)')
    pos = ax.get_position()
    # ax.set_position([pos.x0, pos.y0, pos.width * 0.1, pos.height * 0.1])
    # ax.legend(loc='upper center', bbox_to_anchor=(0.5, 1.35), ncol=3)
    plt.title(title)
    plt.grid(axis='y', color = 'gray', linestyle = '--', linewidth = 0.4)
    plt.subplots_adjust(left=0.15, bottom=0.15, right=0.95, top=0.9)
    plt.savefig(f"charts/{out_name}.pdf")
    plt.clf()
