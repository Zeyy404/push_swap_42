#!/bin/bash

total=0
runs=100
min=1000000
max=0

echo "Running $runs tests for 100 random numbers..."

for ((i=1; i<=runs; i++)); do
    result=$(./push_swap $(shuf -i 1-1000 -n 100) | wc -l)
    # echo "Test $i: $result"

    total=$((total + result))

    if (( result < min )); then
        min=$result
    fi

    if (( result > max )); then
        max=$result
    fi
done

average=$((total / runs))

echo
echo "=============================="
echo "Total runs      : $runs"
echo "Minimum         : $min"
echo "Maximum         : $max"
echo "Average         : $average"
echo "=============================="
echo

total=0
runs=100
min=1000000
max=0

echo "Running $runs tests for 500 random numbers..."

for ((i=1; i<=runs; i++)); do
    result=$(./push_swap $(shuf -i 1-1000 -n 500) | wc -l)
    # echo "Test $i: $result"

    total=$((total + result))

    if (( result < min )); then
        min=$result
    fi

    if (( result > max )); then
        max=$result
    fi
done

average=$((total / runs))

echo
echo "=============================="
echo "Total runs      : $runs"
echo "Minimum         : $min"
echo "Maximum         : $max"
echo "Average         : $average"
echo "=============================="
