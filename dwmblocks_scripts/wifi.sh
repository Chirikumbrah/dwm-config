#!/bin/bash

COLOR=""
CONNENTION="$(nmcli con show --active | grep -E "wifi|ethernet" | awk '{ print $3 }')"

if [[ "$CONNENTION" = "wifi" ]]; then
    ICON=""
elif [[ "$CONNENTION" = "ethernet" ]]; then
    ICON=""
else
    ICON=""
fi

echo "$ICON"
