#!/bin/bash

GREEN='\033[1;32m'
NC='\033[0m'
RED='\033[1;31m'

ten=10

func_path=./func_tests/

####################
#  POSITIVE TESTS  #
####################

count=0

pos_path=./func_tests/pos*in.txt

echo
echo
echo "####################"
echo "#  POSITIVE TESTS  #"
echo "####################"
echo "Number of tests: $count"
echo

for obj in $pos_path
do
	if [ -f "$obj" ]
    then
        count=$(($count + 1))
	fi

done

for (( i = 0; i <= $count; i++))
do
    if [ $i -lt $ten ]
    then
        obj="${func_path}pos_0${i}_in.txt"
	    if [ -f "$obj" ]
        then
			./app < ${func_path}pos_0${i}_in.txt > ${func_path}pos_0${i}_out.txt
            if [ $? -eq 0 ]
            then
                echo -e "${i} ${GREEN}SUCCESS${NC}"
            else
                echo -e "${i} ${RED}FAIL${NC}"
            fi
        fi
    else
        obj="${func_path}pos_${i}_in.txt"
	    if [ -f "$obj" ]
        then
            ./app < ${func_path}pos_${i}_in.txt > ${func_path}pos_${i}_out.txt
            if [ $? -eq 0 ]
            then
                echo -e "${i} ${GREEN}SUCCESS${NC}"
            else
                echo -e "${i} ${RED}FAIL${NC}"
            fi
        fi
    fi
done

####################
#  NEGATIVE TESTS  #
####################

count=0

echo
echo "####################"
echo "#  NEGATIVE TESTS  #"
echo "####################"
echo "Number of tests: $count"
echo

neg_path=./func_tests/neg*in.txt

for obj in $neg_path
do

	if [ -f "$obj" ]
    then
        count=$(($count + 1))
	fi

done

for (( i = 0; i <= $count; i++))
do
    if [ $i -lt $ten ]
    then
        obj="${func_path}neg_0${i}_in.txt"
	    if [ -f "$obj" ]
        then
            ./app < ${func_path}neg_0${i}_in.txt > ${func_path}neg_0${i}_out.txt
            if [ $? -ne 0 ]
            then
                echo -e "${i} ${GREEN}SUCCESS${NC}"
            else
                echo -e "${i} ${RED}FAIL${NC}"
            fi
        fi
    else
        obj="${func_path}neg_${i}_in.txt"
	    if [ -f "$obj" ]
        then
			./app < ${func_path}neg_${i}_in.txt > ${func_path}neg_${i}_out.txt
            if [ $? -ne 0 ]
            then
                echo -e "${i} ${GREEN}SUCCESS${NC}"
            else
                echo -e "${i} ${RED}FAIL${NC}"
            fi
        fi
    fi
done
echo
echo
