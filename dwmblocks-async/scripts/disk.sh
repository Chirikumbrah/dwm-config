#!/bin/bash

case $1 in

    -u)
        DIR=/home/yr/yrData
        LABEL="^c#bd93f9^~"
        ;;

    -r)
        DIR=/
        LABEL="^c#ffb86c^/"
        ;;
esac

LOCAL_FLAG="-l"
if [ "$1" = "-n" ] || [ "$2" = "-n" ]; then
    LOCAL_FLAG=""
fi

USAGE=$(df -h -P $LOCAL_FLAG "$DIR" | awk '/\/.*/ { print $4; exit 0 }')

echo "$LABEL $USAGE"

