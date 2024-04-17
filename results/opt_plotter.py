import matplotlib.pyplot as plt
import numpy as np

kernels = ['1D Convolution (Kernel Size = 16)', 'MTTKRP: Fixed i', 'Population Growth Model']
labels = ['Naive', 'No opt', 'CM', 'DL', 'CM + DL']
colors_list = ['m', '#c982cf', 'c', '#32a887', '#121145']
times = {
    'Naive': np.array([1187411, 1750010861, 1187207]),
    'No Optimization': np.array([457, 1842631, 646]),
    'Code Motion': np.array([456, 999640, 593]),
    'Data Layout': np.array([905, 1816888, 54]),
    'Both': np.array([812, 997492, 49])
}

memory_peak = {
    'Naive': np.array([2.417 * 2 ** 20, 7.488 * 2 ** 20, 2.415 * 2 ** 20]),
    'No Optimization': np.array([2.417 * 2 ** 20, 7.488 * 2 ** 20, 2.415 * 2 ** 20]),
    'Code Motion': np.array([2.417 * 2 ** 20, 7.488 * 2 ** 20, 2.415 * 2 ** 20]),
    'Data Layout': np.array([352.5, 30.64 * 2 ** 10, 633.5]),
    'Both': np.array([352.5, 30.64 * 2 ** 10, 633.5])
}

# To use memory peak instead of time, uncomment the following line:
# times = memory_peak

for k, v in times.items():
    if k == 'Naive':
        continue
    times[k] = times['Naive'] / v
times['Naive'] = times['Naive'] / times['Naive']

colors = {k: v for k, v in zip(list(times.keys()), colors_list)}

x = np.arange(len(kernels)) * 2
width = 0.25  # the width of the bars
multiplier = 0


fig, ax = plt.subplots(layout='constrained')

for i, (opt, time) in enumerate(times.items()):
    offset = width * multiplier
    rects = ax.bar(x + offset - 0.25, time, width, label=opt, color=colors[opt], edgecolor='black')
    if i != 0:
    # if i not in [0, 1, 2]:
        bar_label = [f'{s:.2f}x' for s in time]
        ax.bar_label(ax.containers[i], label_type='center', rotation=90, color='white', labels=bar_label)
    else:
        ax.bar_label(ax.containers[i], label_type='center', rotation=90, color='white')
    multiplier += 1

# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_ylabel('Speed-up')
# ax.set_ylabel('Compression')
# ax.set_yscale('log', base=10)
# ax.set_xlabel('Kernel')
ax.set_title('Evaluation of Optimization Impact on Performance')
# ax.set_title('Evaluation of Optimization Impact on Memory Peak')
ax.set_xticks(x + width, kernels)
ax.legend(loc='upper left', ncols=3)
plt.savefig(f"charts/opt.pdf")
plt.clf()