import matplotlib.pyplot as plt

# Create an empty figure and axis
fig = plt.figure(figsize=(12, 0.3))
ax = fig.add_subplot(111)


# Define the labels and colors for the legend
labels = [
'Naive',
'Numpy',
'PyTorch',
'TensorFlow',
'TensorFlow (XLA)',
'TACO (Dense)',
'TACO (Sparse)',
'StructTensor',
# 'StructTensor (DL)',
# 'Numpy (Man.)',
# 'PyTorch (Man.)',
# 'TensorFlow (Man.)',
# 'TensorFlow (XLA) (Man.)'
]
colors = [
'm',
'b',
'g',
'r',
'#3D1C02',
'y',
'#6b691e',
'c',
# '#121145',
# '#9cb5f0',
# '#90e38d',
# '#e38d8d',
# '#d18243'
]

# Create a list of empty plots with the specified colors
plots = [ax.plot([], [], color=colors[i], label=labels[i], marker='o')[0] for i in range(len(labels))]

# Add a legend with the specified plots and colors
ax.legend(handles=plots, ncols=len(labels), loc='center')
for spine in ax.spines.values():
    spine.set_visible(False)
ax.tick_params(axis='both', which='both', length=0, width=0)
ax.set_xticks([])
ax.set_yticks([])

# Display the legend
plt.savefig(f"charts/legend.pdf")
plt.clf()