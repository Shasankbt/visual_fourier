#   gets the data from dataPoints.txt or filteredData.txt (#commented) and extracts out 
#   the coefficients in the expansion f(t) = Σ (k=-n to +n) c(k) * e^i(2πkt)
#   
#   output format: polar form , seperated by space
#                  {modulus} {phase}
#   order of output :   c(0) \n c(1) \n c(-1) ...... \n c(n) \n c(-n)
#
#   command : $ python3 getCoefficients.py {n}[optional, default = 10]

import numpy as np
import math
import sys

dataPoints = []
dataCount = 0 

arguments = sys.argv    # getting the count of frequencies
if len(arguments) == 1:
    n = 11  #deffault : c[-10],..,c[0],c[1],..,c[10]
elif len(arguments) == 2:
    n = int(arguments[1]) + 1
    if n <= -1:
        print("give valid subset size (>=0)")
        exit()
else :
    print(f"correct command \n")

# ---------------------- taking input from file -------------------

# coordinates in the input file :
with open("text_files/dataPoints.txt", "rt") as file:
    for line in file:
        real, imag = map(int, line.split(','))
        num = complex(real, imag)
        dataPoints.append(complex(real, imag))
        dataCount += 1

# # complex numbers in the input file:
# with open("filteredData.txt", "rt") as file:
#     for line in file:
#         dataPoints.append(complex(line))
#         dataCount += 1

# ------------------------ colculating coefficients ------------------------------------------

data = np.array(dataPoints)
pi = math.pi

multiplier = []
for i in range(-n, n+1):
    row = []
    for j in range(dataCount):
        row.append( complex(math.cos( (-i)*2*pi*(j/dataCount)) , math.sin( (-i)*2*pi*(j/dataCount))) )
    multiplier.append(row)

multiplier = np.array(multiplier)
coeff = (1/dataCount) *  np.dot(multiplier, data)

# --------------------- converting the coefficients into polar form & output-----------------------
def polar(num):
    mod = math.sqrt( pow(num.real,2) + pow(num.imag,2) )
    if num.imag > 0:
        phase = np.arccos(num.real / mod)
    else :
        phase = -1 * np.arccos(num.real / mod)
    
    return str(mod) + " " + str(phase)


# writing to a file :
# coefficientFile = open("text_files/coeff.txt", "wt")

# coefficientFile.write(polar(coeff[n]))
# coefficientFile.write(f"\n")
# for i in range(1,n):
#     coefficientFile.write(polar(coeff[n+i]))
#     coefficientFile.write(f"\n")
#     coefficientFile.write(polar(coeff[n-i]))
#     coefficientFile.write(f"\n")

# output to terminal :
print(n)
print(polar(coeff[n]))
for i in range(1,n):
    print(polar(coeff[n+i]))
    print(polar(coeff[n-i]))

# --------------------------- Plotting the data (#commented out) -------------------------------------

# def plot(coefficients ,n , time):
#     pi = math.pi
#     value = complex(0,0)
#     for i in range(-n, n+1):
#         value += coefficients[i+n] * complex( math.cos(2*pi*i*time), math.sin(2*pi*i*time));
#     return value

# complex_numbers = [plot(coeff, n, i/20) for i in range(20)]
# print(complex_numbers)

# import matplotlib.pyplot as plt

# # Separate real and imaginary parts
# real_parts = [z.real for z in complex_numbers]
# imaginary_parts = [z.imag for z in complex_numbers]

# # Plot
# plt.scatter(real_parts, imaginary_parts, color='blue')
# plt.xlabel('Real Part')
# plt.ylabel('Imaginary Part')
# plt.title('Plot of Complex Numbers')
# plt.grid(True)

# # Invert axes
# plt.gca().invert_yaxis()

# plt.show()

