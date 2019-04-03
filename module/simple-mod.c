#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "simple-mod.h"

MODULE_AUTHOR("Vedad Hadzic");
MODULE_DESCRIPTION("Simple and extendable IOCTL device");
MODULE_LICENSE("MIT");

static bool device_busy = false;

static int device_open(struct inode *inode, struct file *file) 
{
  /* Check if device is busy */
  if (device_busy == true) 
    return -EBUSY;

  /* Lock module */
  try_module_get(THIS_MODULE);
  device_busy = true;

  return 0;
}

static int device_release(struct inode *inode, struct file *file) 
{
  /* Unlock module */
  device_busy = false;

  module_put(THIS_MODULE);

  return 0;
}

static long device_ioctl(struct file *file, unsigned int ioctl_num, 
                         unsigned long ioctl_param)
{
  switch (ioctl_num) 
  {
    case SIMPLEMOD_IOCTL_HELLO:
    {
      return ((long)'o' << 24) | ((long)'l' << 16) | 
             ((long)'e' <<  8) | ((long)'h' <<  0);
    }
    
    default:
      return -1;
  }

  return 0;
}


static struct file_operations f_ops = 
{
  .unlocked_ioctl = device_ioctl,
  .open = device_open,
  .release = device_release
};

static struct miscdevice misc_dev = 
{
  .minor = MISC_DYNAMIC_MINOR,
  .name = SIMPLEMOD_DEVICE_NAME,
  .fops = &f_ops,
  .mode = S_IRWXUGO,
};


int init_module(void) 
{
  /* Register device */
  int r = misc_register(&misc_dev);
  if (r != 0) 
  {
    printk(KERN_ALERT "[simplemod-module] Failed registering device with %d\n", r);
    return 1;
  }

  printk(KERN_INFO "[simplemod-module] Loaded.\n");

  return 0;
}

void cleanup_module(void) 
{
  misc_deregister(&misc_dev);

  printk(KERN_INFO "[simplemod-module] Removed.\n");
}
