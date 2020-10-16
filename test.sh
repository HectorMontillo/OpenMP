#!/bin/bash
echo "Bash version ${BASH_VERSION}..."

for n in {1..5}
  do
    echo "Bench #$n"
    printf "n\tseq\topen\n"
    for i in {10..800..10}
      do 
        printf "%s\t" $i
        ./seq $i
        ./openmp $i

done
done