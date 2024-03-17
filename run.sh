exec_dir=./object_files/
text_dir=./text_files/


# g++ main.cpp -I/home/shasankbt/simplecpp/include -L/home/shasankbt/simplecpp/lib -lsprite -lX11 -o 

make 

${exec_dir}/input > ${text_dir}/dataPoints.txt
python3 getCoefficients.py 50 > ${text_dir}/coeff.txt

${exec_dir}/output < ${text_dir}/coeff.txt

