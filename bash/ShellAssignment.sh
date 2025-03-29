#!/bin/sh

> names.txt #clears/creates name.txt file

echo "Enter the number of students:"
read n
echo

echo "Enter the names: "
echo "Type 'exit' to exit from name entry: "

count=0

while [ $count -lt $n ];do

  read name
  
  #checks for exit command
  if [ "$name" = "exit" ];then
    echo "Exit command received"
    break
  fi
  
  echo "$name" >> names.txt  #Append names to names.txt without overwriting
  count=$((count + 1))
done

sort names.txt > sorted_names.txt  #sorts the names and stores in sorted_names.txt 
echo
echo
echo "Sorted_names:"
cat sorted_names.txt  #displays sorted names
