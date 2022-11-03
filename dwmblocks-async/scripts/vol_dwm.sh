#!/bin/bash


VOL=$(pamixer --get-volume-human | tr -d '%')

if [ "${VOL}" = "muted" ] || [ "${VOL}" = "0" ]; then
    AUDIO=""
else
    AUDIO=" ${VOL}%"
fi


echo -e "^c#bd93f9^${AUDIO}"


