#!/bin/bash
echo "Bash version ${BASH_VERSION}..."

for n in {1..5}
  do
    echo "Bench #$n"
    printf "n\tseq\topen\n"
    for i in {100..1000..100}
      do 
        printf "%s\t" $i
        ./seq $i
        #./openmp $i
        ./openmp2 $i
done
    for i in {2000..5000..1000}
      do 
        printf "%s\t" $i
        ./seq $i
        #./openmp $i
        ./openmp2 $i

done
done