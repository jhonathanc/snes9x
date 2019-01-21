# snes9x
A port of Snes9x-gtk to PS2

# Build dependencies:

1) PS2SDK (Follow the instructions on ps2toolchain readme to install it: https://github.com/ps2dev/ps2toolchain);

2) PS2SDK-PORTS (Clone repository at "https://github.com/ps2dev/ps2sdk-ports" then "make && make install");

3) gsKit (Follow the instrucitions on gsKit readme to install it: https://github.com/ps2dev/gsKit);

4) image (Clone repository at "https://github.com/jhonathanc/image" then "make && make install");

5) smscddvd (Clone repository at "https://github.com/jhonathanc/smscdvd" then "make && make install");

6) Go to "$PS2DEV/ps2sdk/ee/lib/", do a copy of "libc.a" and rename the copy to "libn.a".

7) modules.tgz: A tar.gz file with IRX files on root of it, renamed to modules.tgz. Put it inside "YOUR_FOLDER/snes9x/ps2/".
