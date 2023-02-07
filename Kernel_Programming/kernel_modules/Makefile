obj-m = module1.o

kishore:
	make -C /lib/modules/$(shell uname -r)/build  M=$(shell pwd)  modules
	#make -C /usr/src/linux-headers-5.15.0.58-generic m=$(shell pwd) modules


clean:
	rm -rf *.o *.ko *.mod.c
