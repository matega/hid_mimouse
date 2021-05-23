# hid_mimouse
Fixes Mi Silent Mouse side buttons.
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
