#!/bin/ksh
file=$1
outfile=$2
num_of_chars=`wc -c $file | cut -d" " -f1`
first_half=`expr $num_of_chars / 2`
second_half=`expr $num_of_chars - $first_half`
echo "Number_of_characters_in first_half=$first_half and second_half=$second_half"
echo "Total chars=$num_of_chars"
head -c $first_half $file > out.txt
echo "kanhaiya" >>out.txt
tail -c $second_half  $file >> out.txt
num_of_chars=`wc -c $outfile | cut -d" " -f1`
echo "Total chars after insertion=$num_of_chars"
