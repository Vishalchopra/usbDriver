/** File:	usbDriver.c
  * Author:	Vishal Chopra
  * Date:	01-july-2017
  * Brief:	This is USB driver file, contains initilization and working of the driver.
**/
 
/*****************Header File**************************/
#include <linux/module.h>
#include <linux/init.h>
//#include <linux/kernel.h>
#include <linux/usb.h>

#define USB_VENDOR_ID 0xff00
#define USB_PRODUCT_ID 0xff00

static struct usb_device_id id_table[] = {
	{USB_DEVICE(USB_VENDOR_ID, USB_PRODUCT_ID)},
	{}
};

MODULE_DEVICE_TABLE(usb, id_table); //inform user space tool which device this driver can control

static struct usb_device_id usb_id[] = {
	{.driver_info = 42},
	{}
};

struct usb_driver usb_driver = {
	.name = "USB Driver",
	.id_table = usb_id
};


/******************Initialization of the module*************************/
static int __init usbInitilize(void)
{
	int result;
	printk(KERN_INFO "Initialization of USB driver is done\n");
	result = usb_register(&usb_driver);
	if (result){
		printk(KERN_INFO "Unable to register\n");
		goto err;
	} else {
		printk(KERN_INFO "Driver is register\n");
	}
	return 0;
err:
	return result;
}

static void __exit usbExit(void)
{
	usb_deregister(&usb_driver);
	printk(KERN_INFO "Bye Bye USB driver is unloaded\n");
}

/**********License**************/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vish Chopra");
MODULE_DESCRIPTION("USB driver");


module_init(usbInitilize);
module_exit(usbExit);
