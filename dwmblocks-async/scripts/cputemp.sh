#!/bin/bash

 
TEMP=$(cat /sys/class/thermal/thermal_zone0/temp)
echo "^c#8be9fd^ $(($TEMP / 1000))°C"
