#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;

// name, mode, parent, show
// functino to generate data for the /proc file
// create a virtual file with proc_count as our show function
// remove the virtual file
static int proc_count(struct seq_file *m, void *v){
	// TODO: it's all yours
	// count the # process on your computer that is running rn
	seq_printf(m, "TEXT")
	return 0;
}

static int __init proc_count_init(void)
{
	// called when the module is insmod-ed into kernel: writing new virtual file "proc_count" into directory
	entry = proc_create_single("count", 0, NULL, proc_count);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	// clean up function to remove the account
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Lyla Liu");
MODULE_DESCRIPTION("CS111 lab0 count proc number");
MODULE_LICENSE("GPL");
