cd gfx || exit
clear
grit tiles.png -gt -gB4 -Mw 2 -Mh 2
#grit block.png -gt -gB4 -Mw 2 -Mh 2
cd ..
make
#sleep 1
open blockperson.gba -a mgba