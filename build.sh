#!/bin/bash
# Run the script with `bash build.sh`.
# Builds the graphics using grit, runs make, then opens mgba.

PROGNAME=$0

usage() {
  cat << EOF >&2
Usage: $PROGNAME [-f] [-s <seconds>]

-f       : Load game in flatpak version of mgba (default is using Mac's open command).
-s <time>: Number of seconds to sleep after compiling before loading the emulator.
EOF
  exit 1
}

# Check arguments
while getopts fs: o; do
  case $o in
    (f) flatpak=True;;
    (s) sleep=$OPTARG;;
    (*) usage;;
  esac
done

# Start building
cd gfx || exit
clear
#grit background.png -gt -gB4 -Mw 2 -Mh 2
#grit tiles.png -gt -gB4 -Mw 2 -Mh 2
#grit block.png -gt -gB4 -Mw 2 -Mh 2
cd ..
make

# Wait for a few seconds
sleep "$sleep"s
if [[ -n "$sleep" ]]; then
  sleep $sleep s
fi

if [[ -n "$flatpak" ]]; then
  flatpak run io.mgba.mGBA Blockperson.gba
else
  open blockperson.gba -a mgba
fi