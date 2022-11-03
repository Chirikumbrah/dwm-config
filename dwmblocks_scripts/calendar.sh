#!/bin/bash

DATEFMT=${TIMEFMT:-"+%a %d %b"}
FULLDATEFMT=${FULLDATEFMT:-"+%A %d %B %Y"}
COLOR="^c#f1fa8c^"
ICON=""

case $BLOCK_BUTTON in 
	1) notify-send "^c#f1fa8c^ $(date "$FULLDATEFMT" | awk '{ print tolower($0) }')" ;;
	3) notify-send "Calendar" ;; 
esac 

echo "$COLOR$ICON $(date "$DATEFMT" | awk '{ print tolower($0) }')"
