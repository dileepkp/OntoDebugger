#!/bin/bash

sourcename="$1";
patterns="$2";
outbreaks="$3";
echo "set listsize 1" > "$3";
grep -En "$2" "$1" | \
  cut -d: -f1 | \
#echo "commands\n" >> "$3" | \
  sed "s/^\(.\+\)$/break $1:\1/g" 1>>"$3" ;

#commands\n silent\n list\n continue \n end \n break
