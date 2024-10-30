import os
import numpy as np
import matplotlib.pyplot as plt
import subprocess

# Define constants
INPUT_CSV = 'input.csv'
OUTPUT_CSV = 'output.csv'
DFT_EXECUTABLE = 'main_dft.exe'

# Define the paths
base_dir = os.path.dirname(os.path.abspath(__file__))  # Get the path of the current script
data_dir = os.path.join(base_dir, '../simulation_data/')  # Data folder is at the same level as scripts
bin_dir = os.path.join(base_dir, '../echocancellation/build/DebugNoOpt')    # Bin folder is also at the same level





