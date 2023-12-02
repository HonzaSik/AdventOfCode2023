#!/bin/bash
set -e # Exit on any error

for day in day*/ ; do
    day_executable=${day%/}

    if ! cd "$day"; then
        echo "Failed to enter directory $day"
        continue
    fi

    if [ -f makefile ]; then
        make || { echo "Make failed for $day_executable"; continue; }
    fi

    if [ -f "$day_executable" ]; then
        echo -e "\033[0;32m============= \033[0;31m START $day_executable output \033[0;32m =================\033[0m"
        if ! ./"$day_executable" < "$day_executable".txt; then
            echo "Execution failed for $day_executable"
        fi
    else
        echo "Executable for $day_executable does not exist."
    fi

    echo -e "\033[0;32m============= \033[0;31m END of $day_executable output \033[0;32m ================\033[0m"

    if [ -f makefile ]; then
        make clean
    fi

    cd ..
done
