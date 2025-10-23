"""

E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot, and saves it to a file named "myplot.png"

Inputs: the named file "sample_data_3vars.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6

"""

import pandas as pd
import matplotlib.pyplot as plt

# choose which plot to create and save by uncommenting the appropriate lines
plot_fname = "mflops"
# plot_fname = "memory_bandwidth"
# plot_fname = "memory_latency"

fname = "mflops.csv"
# fname = "memory_bandwidth.csv"
# fname = "memory_latency.csv"

df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)

print("var names =", var_names)

# split the df into individual vars
# assumption: column order - 0=problem size, 1=blas time, 2=basic time

problem_sizes = df[var_names[0]].values.tolist()
code1_time = df[var_names[1]].values.tolist()
code2_time = df[var_names[2]].values.tolist()
code3_time = df[var_names[3]].values.tolist()

plt.figure()

plt.title("Comparison of 3 Sum Algorithms (MFLOPS)")
# plt.title("Comparison of 3 Sum Algorithms (Memory Bandwidth)")
# plt.title("Comparison of 3 Sum Algorithms (Memory Latency)")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(code1_time, "r-o")
plt.plot(code2_time, "b-x")
plt.plot(code3_time, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
# plt.ylabel("runtime")
plt.ylabel("MFLOPS")
# plt.ylabel("Memory Bandwidth %")
# plt.ylabel("Memory Latency (ns)")

varNames = [var_names[1], var_names[2], var_names[3]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')

# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)


plt.show()

# EOF
