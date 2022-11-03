#!/bin/bash

ORANGE="^c#ffb86c^"
PURPLE="^c#bd93f9^"
ROOT_SIGN="/"
USER_SIGN="~"

case $1 in

    -u)
        DIR=/home/yr/yrData
        LABEL="$PURPLE$USER_SIGN"
        ;;

    -r)
        DIR=/
        LABEL="$ORANGE$ROOT_SIGN"
        ;;
esac

LOCAL_FLAG="-l"
if [ "$1" = "-n" ] || [ "$2" = "-n" ]; then
    LOCAL_FLAG=""
fi

USAGE=$(df -h -P $LOCAL_FLAG "$DIR" | awk '/\/.*/ { print $4; exit 0 }')

echo "$LABEL $USAGE"

