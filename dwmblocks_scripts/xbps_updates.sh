#!/bin/bash

ICON=""
COLOR="^c#ffb86c^"
UPDATES="$(xbps-install -nuMS | wc -l)"

if [[ "$UPDATES" -eq 0 ]]; then
    echo ""
else
    echo "$COLOR$ICON $UPDATES"
fi
