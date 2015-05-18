# Open command for linux 
This command imitates the apple "open" command.

Example:
```bash
open file.jpg
```

This will open file.jpg in the native image viewer


## Dependencies
you must have gksudo    (gksu package on archlinux) 
for sopen to work properly


## Installing

to compile and install type:

make install

native compile is static, if you want to dynamiclly compile 
(smaller binary) you can change the C_FLAGS in the makefile

## Settings

All native programs can be set in the extension_map.setting file prior to installation.

This file may be edited after installation as well in the users home directory under .extension_map.setting 

The format of the file must stay the same
```bash
.extension "/usr/bin/program"
```

for example:
```bash
.jpg "/usr/bin/eog"
```

To open Eye of Gnome when a jpg file is called


