for((i = 1;;i++)); do
    echo $i
    ./Generator/test_gen $i > input.txt
    diff -w <(./test < input.txt) <(./brute < input.txt) || break
done
