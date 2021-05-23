obj-m += hid-mimouse.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
install:
	cp $(shell pwd)/hid-mimouse.ko /lib/modules/$(shell uname -r)/kernel/drivers/hid/
	depmod -a
uninstall:
	rm $(shell pwd)/hid-mimouse.ko /lib/modules/$(shell uname -r)/kernel/drivers/hid/hid-mimouse.ko
	depmod -a
dkms:
	make -C $(INCLUDEDIR) M=$(PWD) modules

