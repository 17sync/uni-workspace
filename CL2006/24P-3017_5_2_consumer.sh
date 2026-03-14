#!/bin/bash

FIFO="myfifo.txt"
if [ ! -p "$FIFO" ]; then
    mkfifo "$FIFO" || { echo "Error creating FIFO"; exit 1; }
fi

cleanup(){
    echo
    echo "Consumer exiting..."
    exit 0
}

trap cleanup INT
echo "Consumer waiting for messages..."

while true
do
    if read line < "$FIFO"; then
        if [ "$line" = "quit" ]; then
            echo "Goodbye from consumer!"
            break
        fi
        echo "Received: $line"
    else
        echo "Read error or producer closed."
        break
    fi
done
