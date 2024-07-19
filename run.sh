exec_dir=./object_files/
text_dir=./text_files/

make 1>/dev/null

vectors="50"
speed="0.1"

while getopts ":n:s:" opt; do 
    case $opt in 
        n) vectors="$OPTARG" ;;
        s) speed="$OPTARG" ;;
    esac
done

echo "waiting for the drawing to complete"
${exec_dir}/input > ${text_dir}/dataPoints.txt
echo "data collected from the drawing"

python3 getCoefficients.py $vectors > ${text_dir}/coeff.txt
echo "converted into function"

sed -i "2i\
${speed}" "${text_dir}/coeff.txt"

echo "displaying ... "
${exec_dir}/output < ${text_dir}/coeff.txt
echo "closed"

