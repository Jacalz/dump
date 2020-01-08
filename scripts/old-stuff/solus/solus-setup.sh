#! /bin/bash
# A script for the first install of Solus that removes packages that I don't use, updates the system, rmoves orphan packages and sets up a simple development enviroment.
# solus-setup.sh: version 2.1.0

# Confirm block for confirmation in shell script:
confirm() {
    read -r -p "${1:-Are you sure? [y/N]} " response
    case "$response" in
        [yY][eE][sS]|[yY])
            true
            ;;
        *)
            false
            ;;
    esac
}

echo "Cleaning up file system tools and installing f2fs-tools"
	# File system tools in Solus are named "progs", "-tools" or "-progs"!
	sudo eopkg rm -y squashfs-tools resierfsprogs btrfs-progs xfs-progs
	sudo eopkg it f2fs-tools exfat-utils

confirm "Do you wish to remove printer drivers from the system?" && sudo eopkg rm hplip-drivers system-config-printer gutenprint canon-ufriilt-common -y

confirm "Do you want to remove bluetooth support?" && sudo eopkg rm blueman bluez bluetooth

echo "Removing unneeded packages from the system"
	# Packages to remove for Solus Budgie and most systems:
	sudo eopkg rm -y openvpn orca onboard libreoffice-draw seahorse vpnc metacity gnome-icon-theme transmission thunderbird xorg-driver-video-vmware xorg-driver-input-wacom dconf-editor hexchat
	sudo eopkg rm -y xorg-driver-input-synaptics && sudo eopkg it xorg-driver-input-libinput

echo "Updating system with lates packages"
	sudo eopkg up -y

echo "Checking for packages that got left behind"
	sudo eopkg rmo -y

echo "Restarting system in order to apply kernel updates"
	reboot
