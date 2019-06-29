g++ gen.cpp -o gen
g++ std.cpp -o std
g++ test.cpp -o test

while true; do
    ./gen > test.in
    ./std < test.in > std.out
    ./test < test.in > test.out

    if diff std.out test.out; then 
        printf "Accepted\n"
    else
        printf "Wrong Answer\n"
        break
    fi
done

