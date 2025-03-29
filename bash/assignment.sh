#!/bin/sh


for i in `seq 1 3`
do
   read -p "Enter names $i " name
   echo $name >> namesnew.txt
done

#read filename < namesnew.txt

#echo
#echo "Unsorted names from $filename"
#while read line
#do
 # echo $line
#done <$filename

echo 

echo "A-Z sorted names"

sorted=$(sort namesnew.txt)

echo "$sorted" > sorted.txt

cat sorted.txt




