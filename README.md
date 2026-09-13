# Realtek RTL8821CE Driver

> [!NOTE]
> This is a fork of [tomaspinho/rtl8821ce](https://github.com/tomaspinho/rtl8821ce), which has been archived by its maintainer. This fork adds support for Linux kernel 7.x+.

## Changes from upstream

The following fixes were applied to support newer kernels:

- **`pppoe_hdr.tag` and `pppoe_tag.tag_data`** — removed from kernel space in 7.x, replaced with pointer arithmetic
- **cfg80211 callbacks** — `net_device *` → `wireless_dev *` for `add_key`, `get_key`, `del_key`, `set_default_mgmt_key`, `get_station`, `add_station`, `del_station`, `change_station`, `dump_station`
- **AppleTalk AARP** (`struct elapaarp`) — removed from kernel space in 7.2, wrapped in `#ifdef CONFIG_ATALK`
- **`strncpy`** → `strscpy` (deprecated in newer kernels)
- **`remain_on_channel`** — new `const u8 *rx_addr` parameter and return type changed from `s32` to `int`

## Intent
Targeting Linux 4.14+ with active fixes for kernels up to 7.x. Developed and tested on Arch Linux.

## Disclaimer
The maintainers of this repository are not Realtek employees. This is a community-maintained fork. Use at your own risk.

## DKMS

This driver can be installed using [DKMS](http://linux.dell.com/dkms/), which will automatically recompile and install the kernel module when a new kernel is installed.

## Installation

Make sure you have a proper build environment and `dkms` installed.

### Arch Linux

```bash
sudo pacman -Syu linux-headers dkms bc
```

Clone and install:

```bash
git clone https://github.com/sewaustav/rtl8821ce.git
cd rtl8821ce
sudo ./dkms-install.sh
```

### Ubuntu & Debian

```bash
sudo apt install bc module-assistant build-essential dkms
sudo m-a prepare
git clone https://github.com/sewaustav/rtl8821ce.git
cd rtl8821ce
sudo ./dkms-install.sh
```

## Removal

```bash
cd rtl8821ce
sudo ./dkms-remove.sh
```

## Upgrading

```bash
sudo ./dkms-remove.sh
git pull
make clean
sudo ./dkms-install.sh
```

## Possible issues

### Wi-Fi not working for kernel >= 5.9

The built-in `rtw88` module has poor compatibility with most revisions of the 8821ce chip and may cause system crashes. Blacklist it:

blacklist rtw88_8821ce


Add this to `/etc/modprobe.d/blacklist.conf`, then reinstall the driver and reboot.

### PCIe Active State Power Management

May conflict with this driver. To disable, add `pcie_aspm=off` to `GRUB_CMDLINE_LINUX_DEFAULT` in `/etc/default/grub` and update grub.

### Lenovo Yoga laptops

The `ideapad-laptop` module may conflict with this driver:

```bash
sudo modprobe -r ideapad_laptop
```

### Secure Boot

Either disable Secure Boot in BIOS, or sign the compiled `.ko` with a MOK key.

### Unstable connection

Set the BSSID explicitly in your network manager. Disable NetworkManager connectivity check by adding to `/var/lib/NetworkManager/NetworkManager-intern.conf`:

[connectivity]
.set.enabled=false


### Wi-Fi and Bluetooth after suspend

Known unfixable issue due to missing power management in the Realtek driver.

### Monitor mode

Not supported and will not be added.

## Reporting issues

Enable debug logging before reporting:

CONFIG_RTW_DEBUG = y


Edit `Makefile` or set `MAKEFLAGS="CONFIG_RTW_DEBUG = y"` before compilation.

## License

GPL v2. Original code Copyright(c) 2012-2020 Realtek Corporation.  
Fork maintained by community contributors. See [tomaspinho/rtl8821ce](https://github.com/tomaspinho/rtl8821ce) for original repository.