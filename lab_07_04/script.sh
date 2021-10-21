#!/bin/bash

GREEN='\033[1;32m'
NC='\033[0m'
RED='\033[1;31m'

ten=10

####################
#  POSITIVE TESTS  #
####################

count=0

for obj in ./func_tests/pos*in.txt
do

	if [ -f "$obj" ]
    then
        count=$(($count + 1))
	fi

done

echo
echo $count
echo "####################"
echo "#  POSITIVE TESTS  #"
echo "####################"
echo

for (( i = 0; i <= $count; i++))
do
    if [ $i -lt $ten ]
    then
        obj="./func_tests/pos_0${i}_in.txt"
	    if [ -f "$obj" ]
        then
            if [ -f "./func_tests/pos_0${i}_args.txt" ]
            then
                cat_rez=$(cat ./func_tests/pos_0${i}_args.txt)
                ./app ${cat_rez} > ./func_tests/pos_0${i}_out.txt
                if [ $? -eq 0 ]
                then
                    echo -e "${i} ${GREEN}SUCCESS${NC}"
                else
                    echo -e "${i} ${RED}FAIL${NC}"
                fi
            fi
        fi
    else
        obj="./func_tests/pos_${i}_in.txt"
	    if [ -f "$obj" ]
        then
            if [ -f "./func_tests/pos_${i}_args.txt" ]
            then
                cat_rez=$(cat ./func_tests/pos_${i}_args.txt)
                ./app ${cat_rez} > ./func_tests/pos_${i}_out.txt
                if [ $? -eq 0 ]
                then
                    echo -e "${i} ${GREEN}SUCCESS${NC}"
                else
                    echo -e "${i} ${RED}FAIL${NC}"
                fi
            fi
        fi
    fi
done

####################
#  NEGATIVE TESTS  #
####################

count=0
for obj in ./func_tests/neg*in.txt
do

	if [ -f "$obj" ]
    then
        count=$(($count + 1))
	fi

done

echo
echo $count
echo "####################"
echo "#  NEGATIVE TESTS  #"
echo "####################"
echo

for (( i = 0; i <= $count; i++))
do
    if [ $i -lt $ten ]
    then
        obj="./func_tests/neg_0${i}_in.txt"
	    if [ -f "$obj" ]
        then
            if [ -f "./func_tests/neg_0${i}_args.txt" ]
            then
                cat_rez=$(cat ./func_tests/neg_0${i}_args.txt)
                ./app ${cat_rez} > ./func_tests/neg_0${i}_out.txt
                if [ $? -ne 0 ]
                then
                    echo -e "${i} ${GREEN}SUCCESS${NC}"
                else
                    echo -e "${i} ${RED}FAIL${NC}"
                fi
            fi
        fi
    else
        obj="./func_tests/neg_${i}_in.txt"
	    if [ -f "$obj" ]
        then
            if [ -f "./func_tests/neg_${i}_args.txt" ]
            then
                cat_rez=$(cat ./func_tests/neg_${i}_args.txt)
                ./app ${cat_rez} > ./func_tests/neg_${i}_out.txt
                if [ $? -ne 0 ]
                then
                    echo -e "${i} ${GREEN}SUCCESS${NC}"
                else
                    echo -e "${i} ${RED}FAIL${NC}"
                fi
            fi
        fi
    fi
done
