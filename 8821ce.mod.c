#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};


MODULE_INFO(depends, "cfg80211");

MODULE_ALIAS("pci:v000010ECd0000B821sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010ECd0000C821sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010ECd0000C82Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010ECd0000C82Bsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "027623AF12F12634300E463");
