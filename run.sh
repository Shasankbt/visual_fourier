exec_dir=./object_files/
text_dir=./text_files/


# g++ main.cpp -I/home/shasankbt/simplecpp/include -L/home/shasankbt/simplecpp/lib -lsprite -lX11 -o 

make 

vectors="50"
speed="0.1"

while getopts ":n:s:" opt; do 
    case $opt in 
        n) vectors="$OPTARG" ;;
        s) speed="$OPTARG" ;;
    esac
done

echo $speed

${exec_dir}/input > ${text_dir}/dataPoints.txt
python3 getCoefficients.py $vectors > ${text_dir}/coeff.txt

sed -i "2i\
${speed}" "${text_dir}/coeff.txt"

${exec_dir}/output < ${text_dir}/coeff.txt

