import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import os
import sys

if __name__ == '__main__':
    retailer_file_path = sys.argv[1]
    favorita_file_path = sys.argv[2]
    out_name = sys.argv[3]
    title = sys.argv[4]
    begin = 0
    fig, ax = plt.subplots()
    scale = 1 / 2
    plt.rcParams["figure.figsize"] = (10 * scale, 7 * scale)
    r_df = pd.read_csv(retailer_file_path)
    end = len(r_df['size'].to_numpy())
    r_df['size'] = r_df['size'] * 100
    r_df['stM'] = r_df['stM'] / 1e6
    r_df['stU'] = r_df['stU'] / 1e6
    r_df['stR'] = (r_df['stR'] - r_df['nstR']) / 1e6
    r_df['nstM'] = r_df['nstM'] / 1e6
    r_df['nstU'] = r_df['nstU'] / 1e6

    f_df = pd.read_csv(favorita_file_path)
    f_df['size'] = f_df['size'] * 100
    f_df['stM'] = f_df['stM'] / 1e6
    f_df['stU'] = f_df['stU'] / 1e6
    f_df['stR'] = (f_df['stR'] - f_df['nstR']) / 1e6
    f_df['nstM'] = f_df['nstM'] / 1e6
    f_df['nstU'] = f_df['nstU'] / 1e6

    df = pd.concat([r_df, f_df])
    
    width = 0.35
    x = np.arange(2 * (end - begin))
    labels = ['Retailer (Small)', 'Retailer (Full)', 'Favorita (Small)', 'Favorita (Full)']
    
    # ax.bar(x - width / 2, df['nstM'], width, label='StructTensor (Naive): Multiplication', hatch='|||', color='m', alpha=0.99)
    # ax.bar(x - width / 2, df['nstU'], width, label='StructTensor (Naive): Addition', hatch='\\\\\\', bottom=df['nstM'], color='m', alpha=0.99)
    
    # ax.bar(x + width / 2, df['stM'], width, label='StructTensor: Multiplication', hatch='|||', color='c', alpha=0.99)
    # bar = ax.bar(x + width / 2, df['stU'], width, label='StructTensor: Addition', hatch='\\\\\\', bottom=df['stM'], color='c', alpha=0.99)
    # ax.bar(x + width / 2, df['stR'], width, label='StructTensor: Reconstruction', hatch='...', bottom=df['stU'], color='c', alpha=0.99)

    ax.bar(x - width / 2, df['nstM'], width, label='StructTensor (Naive): Multiplication', color='darkmagenta', alpha=0.99)
    ax.bar(x - width / 2, df['nstU'], width, label='StructTensor (Naive): Addition', bottom=df['nstM'], color='m', alpha=0.99)
    
    ax.bar(x + width / 2, df['stM'], width, label='StructTensor: Multiplication', color='c', alpha=0.99)
    bar = ax.bar(x + width / 2, df['stU'], width, label='StructTensor: Addition', bottom=df['stM'], color='aqua', alpha=0.99)
    ax.bar(x + width / 2, df['stR'], width, label='StructTensor: Reconstruction', bottom=df['stU'], color='navy', alpha=0.99)


    speedup = (df['nstM'] + df['nstU']) / (df['stM'] + df['stU'] + df['stR'])
    bar_label = [f'{s:.2f}x' for s in speedup.to_numpy()]
    ax.bar_label(bar, padding=3, labels=bar_label, fontsize=10)



    ax.set_xticks(x, labels)
    # plt.plot('x_axis', 'y_axis', data=st_df, label="Structured", color='c', marker='o')
    # plt.plot('x_axis', 'y_axis', data=nst_df, label="Non-structured", color='m', marker='o')
    plt.xlabel('Dataset')
    plt.ylabel('Time (s)')
    if 'R' not in out_name:
        plt.legend(loc=1)
    plt.title(title)
    plt.grid(axis='y', color = 'gray', linestyle = '--', linewidth = 0.4)
    plt.subplots_adjust(left=0.15, bottom=0.15, right=0.95, top=0.9)
    plt.savefig(f"charts/{out_name}.pdf")
    plt.clf()
