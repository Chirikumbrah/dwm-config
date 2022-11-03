#!/bin/bash

statusLine=$(amixer get Capture | tail -n 1)
status=$(echo "${statusLine}" | grep -wo "off")
COLOR="^c#FF92DF^"

if [[ "${status}" = "off" ]]; then
      MIC=""
else
      MIC=""
fi

echo "$COLOR$MIC"
