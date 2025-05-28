# ARCHIVED
This fix was mainlined a couple of months after I published this. You shouldn't need to build this module by hand any more.

https://github.com/torvalds/linux/blob/master/drivers/hid/hid-xiaomi.c

# hid_mimouse
Fixes Mi Silent Mouse side buttons.
## Prerequisites (on Ubuntu, Debian)
    $ sudo apt install build-essential linux-headers-generic dkms
(If you use a non-generic kernel, you should install the headers for that. DKMS is optional.)
## Building
    $ make
## Installing
    $ sudo make install
## DKMS
    $ sudo dkms add .
    $ sudo dkms install hid_mimouse/1.0
## Uninstalling
    $ make uninstall
## Uninstalling DKMS
    $ sudo dkms remove hid_mimouse/1.0 --all
