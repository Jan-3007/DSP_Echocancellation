Ubuntu 24.04 hat keine Pakete für libncurses5/libncursesw5 

Try:

cd /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin
./arm-none-eabi-gdb

Output:

./arm-none-eabi-gdb: error while loading shared libraries: libncursesw.so.5: cannot open shared object file: No such file or directory


Lösung:

Installiere die Pakete: 

sudo apt-get install libncurses*

find /usr/ -name *libncurses* | grep libncurses

Erzeuge symlinks für jeweilig gefundene Version:

sudo ln -s -f /usr/lib/x86_64-linux-gnu/libncurses.so.6.4 /usr/lib/libncurses.so.5
sudo ln -s -f /usr/lib/x86_64-linux-gnu/libncursesw.so.6.4 /usr/lib/libtinfo.so.5
sudo ln -s -f /usr/lib/x86_64-linux-gnu/libncursesw.so.6.4 /usr/lib/libncursesw.so.5

Try:
cd /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin
./arm-none-eabi-gdb

Output:

GNU gdb (Arm GNU Toolchain 13.3.Rel1 (Build arm-13.24)) 14.2.90.20240526-git
Copyright (C) 2023 Free Software Foundation, Inc.

...

(gdb) 