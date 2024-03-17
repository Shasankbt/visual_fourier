#   used to convert a set of data points from a file named dataPoints.txt
#   input file format : coordinates seperated by commas (',')
#   output : complex numbers representing the coordinates
#   
#   converts a subset of dataset (can be given as argument) and morphs into 5 points
#   using bezier curves
#
#   command $ : python3 bezier.py [optional]{subset_size}

import numpy as np
import sys

# getting the length of subsets
arguments = sys.argv
if len(arguments) == 1:
    subsetLength = 3
if len(arguments) == 2:
    subsetLength = int(arguments[1])
    if subsetLength <= 1:
        print("give valid subset size (>1)")


# --------------------- extracting and prepping matrix ---------------------------------
dataPoints = []

with open("text_files/dataPoints.txt", "rt") as file:
    for line in file:
        real, imag = map(int, line.split(','))
        num = complex(real, imag)
        dataPoints.append(num)

while len(dataPoints) % subsetLength != 1:
    dataPoints.pop()

# print(len(dataPoints))

coordinateMatrix = []

for i in range(len(dataPoints)//subsetLength):
    coordinateMatrix.append(dataPoints[ subsetLength * i : subsetLength * (i+1) + 1 ])

Matrix = np.array(coordinateMatrix)


# ------------------------------ converting / morphing ------------------------------
def nCr(n, r):
    result = 1
    for i in range(r):
        result *= (n - i)
        result //= (i + 1)
    return result

def generateMultiplier(out_points, in_points):
    matrix = []
    for i in range(in_points+1):
        list = []
        for t in range(out_points):
            list.append( pow(t/out_points, i) * pow(1-t/out_points, in_points - i) * nCr(in_points,i))
            # here we intentionally leave out the last term in binomial expansion
            # since it will result in same point which will be repeated in the next subset
        matrix.append(list)

    return matrix

multiplier = np.array(generateMultiplier(5,subsetLength))

convertedData =  Matrix.dot(multiplier ) 

# -------------------------------- decompressing and output --------------------------------------
convertedData = convertedData.flatten()

# writting into a file :
# filteredFile = open("filteredData.txt", "wt")
# for i in range(convertedData.size):
#     filteredFile.write(str(convertedData[i]))
#     filteredFile.write(f"\n")
# print(convertedData.size)

# printing :
[print(convertedData[i]) for i in range(convertedData.size)]
    



