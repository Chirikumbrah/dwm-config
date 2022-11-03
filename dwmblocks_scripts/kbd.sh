#!/bin/bash

CAPS=$(xset -q | sed -n 's/^.*Caps Lock:\s*\(\S*\).*$/\1/p')
COLOR="^c#50fa7b^" 
ICON=""

if [[ "$CAPS" = on ]]; then
    LAYOUT="$(xkblayout-state print %s | awk '{print toupper($0)}')"
else
    LAYOUT="$(xkblayout-state print %s | awk '{print $0}')"
fi

echo "$COLOR$ICON $LAYOUT"
