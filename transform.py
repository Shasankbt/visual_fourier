import numpy as np
import math

pi = math.pi

dataPoints = []
dataCount = 0 

with open("dataPoints.txt", "rt") as file:
    for line in file:
        real, imag = map(int, line.split(','))
        num = complex(real, imag)
        dataPoints.append(complex(real, imag))
        dataCount += 1

# with open("filteredData.txt", "rt") as file:
#     for line in file:
#         # real, imag = map(int, line.split(','))
#         # num = complex(real, imag)
#         dataPoints.append(complex(line))
#         dataCount += 1


data = np.array(dataPoints)
multiplier = []

n = 50 # int(input("enter the number 'n' : "))

for i in range(-n, n+1):
    row = []
    for j in range(dataCount):
        row.append( complex(math.cos( (-i)*2*pi*(j/dataCount)) , math.sin( (-i)*2*pi*(j/dataCount))) )
    multiplier.append(row)

multiplier = np.array(multiplier)
coeff = (1/dataCount) *  np.dot(multiplier, data)


def polar(num):
    # return str(num.real)
     # print(f"{num.real} {pow(num.imag,2)}")
    mod = math.sqrt( pow(num.real,2) + pow(num.imag,2) )
    if num.imag > 0:
        phase = np.arccos(num.real / mod)
    else :
        phase = -1 * np.arccos(num.real / mod)
    
    return str(mod) + " " + str(phase)

coefficientFile = open("coeff.txt", "wt")

# coefficientFile.write(str(coeff[n].real))

coefficientFile.write(polar(coeff[n]))
#coefficientFile.write(f"\t -c({0})")

coefficientFile.write(f"\n")
for i in range(1,n):
    coefficientFile.write(polar(coeff[n+i]))
    #coefficientFile.write(f"\t -c({i})")
    coefficientFile.write(f"\n")
    coefficientFile.write(polar(coeff[n-i]))
    #coefficientFile.write(f"\t -c({-i})")
    coefficientFile.write(f"\n")
    

#print(tempData)

#print(tempData.size)

# for i in range(-n, n+1):
#     coeff.update({f"c[{i}]" : tempData[i+n]})

# [print(f"{x}\t:  {coeff[x]}") for x in coeff]

# x = complex(0,0)
# for i in range(-n, n+1):
#     x += (coeff[f"c[{i}]"])

# print("this is x")
# print(x)

def draw(coefficients ,n , time):
    pi = math.pi
    value = complex(0,0)
    for i in range(-n, n+1):
        value += coefficients[i+n] * complex( math.cos(2*pi*i*time), math.sin(2*pi*i*time));
    return value

# print(draw(coeff, n, 0))


# print(sum(coeff))

# for i in range(0,n+1):
#     print(draw(coeff,i,0))
#     print(draw(coeff,-i,0))


# complex_numbers = [draw(coeff, n, i/20) for i in range(20)]
# print(complex_numbers)

# # for i in range(62):
# #     print(i, end=" ")
# #     print(draw(coeff, n, i/62))


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

# # Invert both axes
# # plt.gca().invert_xaxis()
# plt.gca().invert_yaxis()


# plt.show()

