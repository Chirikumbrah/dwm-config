#!/bin/bash

ICON=""
COLOR="^c#FF92DF^"
UPDATES="$(xbps-install -nuMS | wc -l)"

echo "$COLOR$ICON $UPDATES"
