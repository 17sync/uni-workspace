#!/bin/bash

FIFO="myfifo.txt"
if [ ! -p "$FIFO" ]; then
    mkfifo "$FIFO" || { echo "Error creating FIFO"; exit 1; }
fi

cleanup(){
    echo
    echo "Producer exiting..."
    exit 0
}

trap cleanup INT
echo "Producer started. Type messages (type 'quit' to exit)."

while true
do
    read input

    if echo "$input" > "$FIFO"; then
        :
    else
        echo "Error writing to FIFO (consumer may not be running)."
        exit 1
    fi

    if [ "$input" = "quit" ]; then
        break
    fi
done
