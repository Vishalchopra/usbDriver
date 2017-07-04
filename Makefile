INSTALLDIR=$(shell pwd)/modules
obj-m := lkm.o
lkm-objs := usbDriver.o 


all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd *.symvers *.order $(INSTALLDIR)
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	@rm -rf $(INSTALLDIR)
	
