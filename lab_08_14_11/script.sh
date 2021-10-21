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

pos_path=./func_tests/pos*args.txt

echo
echo
echo "####################"
echo -e "#  ${GREEN}POSITIVE TESTS${NC}  #"
echo "####################"

for obj in $pos_path
do
	if [ -f "$obj" ]
    then
        count=$(($count + 1))
	fi

done

echo "Number of tests: $count"
echo

for (( i = 0; i <= $count; i++))
do
    if [ $i -lt $ten ]
    then
        obj="${func_path}pos_0${i}_args.txt"
	    if [ -f "$obj" ]
        then
			cat_rez=$(cat ${func_path}pos_0${i}_args.txt)
			echo ${cat_rez}
			./app ${cat_rez} #> ${func_path}pos_0${i}_out.txt
            if [ $? -eq 0 ]
            then
				obj_rez="${func_path}pos_0${i}_rez.txt"
				obj_out="${func_path}pos_0${i}_out.txt"

				if [ -f "$obj_rez" ]
		        then
					diff $obj_rez $obj_out
					if [ $? -eq 0 ]
					then
						echo -e "${i} ${GREEN}SUCCESS${NC}"
					else
						echo -e "${i} ${RED}FAIL${NC}"
					fi
				else
					echo -e "${i} ${RED}FAIL${NC}"
				fi
            else
                echo -e "${i} ${RED}FAIL${NC}"
            fi
        fi
    else
        obj="${func_path}pos_${i}_args.txt"
	    if [ -f "$obj" ]
        then
			cat_rez=$(cat ${func_path}pos_${i}_args.txt)
			./app ${cat_rez} #> ${func_path}pos_${i}_out.txt
			if [ $? -eq 0 ]
            then
				obj_rez="${func_path}pos_${i}_rez.txt"
				obj_out="${func_path}pos_${i}_out.txt"

				if [ -f "$obj_rez" ]
		        then
					diff $obj_rez $obj_out
					if [ $? -eq 0 ]
					then
						echo -e "${i} ${GREEN}SUCCESS${NC}"
					else
						echo -e "${i} ${RED}FAIL${NC}"
					fi
				else
					echo -e "${i} ${RED}FAIL${NC}"
				fi
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
echo -e "#  ${RED}NEGATIVE TESTS${NC}  #"
echo "####################"

neg_path=./func_tests/neg*args.txt

for obj in $neg_path
do

	if [ -f "$obj" ]
    then
        count=$(($count + 1))
	fi

done

echo "Number of tests: $count"
echo

for (( i = 0; i <= $count; i++))
do
    if [ $i -lt $ten ]
    then
        obj="${func_path}neg_0${i}_args.txt"
	    if [ -f "$obj" ]
        then
			cat_rez=$(cat ${func_path}neg_0${i}_args.txt)
			./app ${cat_rez} #> ${func_path}neg_0${i}_out.txt
			if [ $? -eq 0 ]
            then
				echo -e "${i} ${RED}FAIL${NC}"
            else
				obj_rez="${func_path}neg_0${i}_rez.txt"
				obj_out="${func_path}neg_0${i}_out.txt"

				if [ -f "$obj_rez" ]
		        then
					diff $obj_rez $obj_out
					if [ $? -eq 0 ]
					then
						echo -e "${i} ${GREEN}SUCCESS${NC}"
					else
						echo -e "${i} ${RED}FAIL${NC}"
					fi
				else
					echo -e "${i} ${RED}FAIL${NC}"
				fi
            fi
        fi
    else
        obj="${func_path}neg_${i}_args.txt"
	    if [ -f "$obj" ]
        then
			cat_rez=$(cat ${func_path}neg_${i}_args.txt)
			./app ${cat_rez} #> ${func_path}neg_${i}_out.txt
			if [ $? -eq 0 ]
            then
				echo -e "${i} ${RED}FAIL${NC}"
            else
				obj_rez="${func_path}neg_${i}_rez.txt"
				obj_out="${func_path}neg_${i}_out.txt"

				if [ -f "$obj_rez" ]
		        then
					diff $obj_rez $obj_out
					if [ $? -eq 0 ]
					then
						echo -e "${i} ${GREEN}SUCCESS${NC}"
					else
						echo -e "${i} ${RED}FAIL${NC}"
					fi
				else
					echo -e "${i} ${RED}FAIL${NC}"
				fi
            fi
        fi
    fi
done
echo
echo
