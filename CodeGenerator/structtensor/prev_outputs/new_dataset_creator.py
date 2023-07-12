from operator import index
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split

if __name__ == '__main__':
    for i in [0.25, 1]:
        with open(f'datasets/retailer/Inventory_{i}.tbl', 'w') as f_train:
            with open('datasets/retailer/Inventory.tbl', 'r') as g:
                train, test = train_test_split(g.readlines(), train_size=i - 1e-8, test_size=1 - i + 1e-8, random_state=0)
                if i != 1:
                    f_train.writelines(train)
                else:
                    f_train.writelines(train + test)
                

    for i in [0.25, 1]:
        with open(f'datasets/favorita/Sales_{i}.tbl', 'w') as f_train:
            with open('datasets/favorita/Sales.tbl', 'r') as g:
                train, test = train_test_split(g.readlines(), train_size=i - 1e-8, test_size=1 - i + 1e-8, random_state=0)
                f_train.writelines(train)
                if i != 1:
                    f_train.writelines(train)
                else:
                    f_train.writelines(train + test)
                

