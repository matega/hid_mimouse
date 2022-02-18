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
