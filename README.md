# A Kernel Seedling
This project creates a `/proc/count` file in the Linux kernel that displays the current number of running processes (or tasks).
The module allows `/proc/count` to return an integer representing the number of running processes when you use the command `cat /proc/count`.

## Building
To build the module, use the following command:
```shell
make
```

## Running
```shell
sudo insmod proc_count.ko
cat /proc/count
```
The result is an integer representing the number of running processes

Sample Result: 
cat /proc/count          
183

## Cleaning Up
```shell
sudo rmmod proc_count
make clean
```

## Testing
```python
python -m unittest
```

Sample result:
```
...
----------------------------------------------------------------------
Ran 3 tests in 2.761s

OK
```


Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

```shell
uname -r -s -v
```
uname -r -s -v
Linux 5.14.8-arch1-1 #1 SMP PREEMPT Sun, 26 Sep 2021 19:36:15 +0000


modinfo proc_count.ko    
filename:       /home/cs111/Downloads/lab0/proc_count.ko
license:        GPL
description:    CS111 lab0 count proc number
author:         Lyla Liu
srcversion:     8FA7F768BBE9157C78B1BEA
depends:        
retpoline:      Y
name:           proc_count
vermagic:       5.14.8-arch1-1 SMP preempt mod_unload