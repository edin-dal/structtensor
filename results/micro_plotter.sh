# !/bin/sh

python3 micro_plotter.py "MTTKRP_final_results_fixed_i.csv" "MTTKRP_fixed_i" "MTTKRP: Fixed i" 10
python3 micro_plotter.py "MTTKRP_final_results_fixed_ij.csv" "MTTKRP_fixed_ij" "MTTKRP: Fixed i & j" 10
python3 micro_plotter.py "MTTKRP_final_results_fixed_j.csv" "MTTKRP_fixed_j" "MTTKRP: Fixed j" 10
python3 micro_plotter.py "THP_results_diag(plane).csv" "THP_diag(plane)" "THP: Digonal (Plane)" 10
python3 micro_plotter.py "THP_results_fixed_i.csv" "THP_fixed_i" "THP: Fixed i" 10
python3 micro_plotter.py "THP_results_fixed_j.csv" "THP_fixed_j" "THP: Fixed j" 10
python3 micro_plotter.py "TTM_final_results_diag(plane).csv" "TTM_diag(plane)" "TTM: Diagonal (Plane)" 10
python3 micro_plotter.py "TTM_final_results_fixed_j.csv" "TTM_fixed_j" "TTM: Fixed j" 10
python3 micro_plotter.py "TTM_final_results_upper_trinagular(half_cube).csv" "TTM_results_upper_trinagular(half_cube)" "TTM: Upper Trinagular (Half Cube)" 10
# python3 plotter.py "results/TTV_final_results_diag(line).csv" "TTV_diag(line)" "TTV: Diagonal (Line)" 10
# python3 plotter.py "results/TTV_final_results_fixed_ij.csv" "TTV_fixed_ij" "TTV: Fixed i & j" 10
# python3 plotter.py "results/TTV_final_results_upper_trinagular(half_cube).csv" "TTV_upper_trinagular" "TTV: Upper Trinagular (Half Cube)" 10