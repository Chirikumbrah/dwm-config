#!/bin/bash

statusLine=$(amixer get Capture | tail -n 1)
status=$(echo "${statusLine}" | grep -wo "off")

if [[ "${status}" = "off" ]]; then
      MIC=""
else
      MIC=""
fi

echo "^c#FF92DF^${MIC}"
