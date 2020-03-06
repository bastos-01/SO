#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
CONTADOR="0"
MEDIA="0"
while true; do
 echo -n "Enter your score [0-10] ('q' to quit) ('r' to reset): "
 read SCORE;
 if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
 echo "Try again: "
 elif [[ "$SCORE" == "q" ]]; then
 echo "Sum: $SUM."
 echo "Mean: $MEDIA."
 break
 elif [[ "$SCORE" == "r" ]]; then
 CONTADOR="0"
 SUM="0"
 MEDIA="0"
 echo "Values set to 0."
 else
 CONTADOR=$((CONTADOR + 1))
 SUM=$((SUM + SCORE))
 MEDIA=$((SUM / CONTADOR))
 fi
done
echo "Exiting."