#!/bin/bash

COLOR="^c#FF92DF^"

BATTERY_STATE=$(upower -i "$(upower -e | grep 'BAT')" | grep -E "state|to full" | awk '{print $2}')
BATTERY_POWER=$(upower -i "$(upower -e | grep 'BAT')" | grep -E "percentage" | awk '{print $2}' | tr -d '%')

if [[ "${BATTERY_STATE}" = "pending-charge" ]]; then
    BAT=" ${BATTERY_POWER}%"

elif [[ "${BATTERY_STATE}" = "discharging" && "${BATTERY_POWER}" -gt 80 ]]; then
    BAT=" ${BATTERY_POWER}%"

elif [[ "${BATTERY_STATE}" = "discharging" && "${BATTERY_POWER}" -gt 60 ]]; then
    BAT=" ${BATTERY_POWER}%"

elif [[ "${BATTERY_STATE}" = "discharging" && "${BATTERY_POWER}" -gt 40 ]]; then
    BAT=" ${BATTERY_POWER}%"

elif [[ "${BATTERY_STATE}" = "discharging" && "${BATTERY_POWER}" -gt 20 ]]; then
    BAT=" ${BATTERY_POWER}%"

elif [[ "${BATTERY_STATE}" = "discharging" && "${BATTERY_POWER}" -gt 10 ]]; then
    BAT=" ${BATTERY_POWER}%"

elif [[ "${BATTERY_STATE}" = "discharging" && "${BATTERY_POWER}" -le 10 ]]; then
    BAT=" ${BATTERY_POWER}%"

else
    BAT=" ${BATTERY_POWER}%"
fi

echo "$COLOR$BAT"
