from audioop import mul
from re import M
import numpy as np
import math

dataFile = open("dataPoints.txt", "rt")

filteredFile = open("filteredData.txt", "wt")

dataPoints = []

with open("dataPoints.txt", "rt") as file:
    for line in file:
        real, imag = map(int, line.split(','))
        num = complex(real, imag)
        dataPoints.append(num)

while len(dataPoints) % 3 != 1:
    dataPoints.pop()

# print(len(dataPoints))

coordinateMatrix = []

for i in range(len(dataPoints)//3):
    coordinateMatrix.append(dataPoints[3*i:3*i+4])

Matrix = np.array(coordinateMatrix)

# print(Matrix)

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
        matrix.append(list)

    return matrix

multiplier = np.array(generateMultiplier(5,3))

# print(Matrix[0:4])
# print(multiplier)

# print( np.dot( ( np.transpose(multiplier) * np.transpose(Matrix[0:11])  )))
convertedData =  Matrix.dot(multiplier ) 
convertedData = convertedData.flatten()

#filteredFile.write(np.array2string(convertedData))

for i in range(convertedData.size):
    filteredFile.write(str(convertedData[i]))
    filteredFile.write(f"\n")
print(convertedData.size)
# print( np.dot( ( (multiplier) * (Matrix[0:11])  )))


