# !/bin/bash
# . env/bin/activate

python plot/oopsla_plotter.py out/LR_Covar.csv LR_Covar "Linear Regression - Creation" 10
python plot/oopsla_plotter.py out/LR_Covar_add.csv LR_Covar_add "Linear Regression - Addition" 10
python plot/oopsla_plotter.py out/PR2_Covar.csv PR2_Covar "Polynomial Regression Degree 2 - Creation" 10
python plot/oopsla_plotter.py out/PR2_Covar_add.csv PR2_Covar_add "Polynomial Regression Degree 2 - Addition" 10
python plot/oopsla_plotter.py out/PR3_Covar.csv PR3_Covar "Polynomial Regression Degree 3 - Creation" 10
python plot/oopsla_plotter.py out/PR3_Covar_add.csv PR3_Covar_add "Polynomial Regression Degree 3 - Addition" 10

# python plot/oopsla_IFAQ.py out/IFAQ_LR.csv IFAQ_LR "Linear Regression" 10
# python plot/oopsla_IFAQ.py out/IFAQ.csv IFAQ "Polynomial Regression Degree 2" 10
