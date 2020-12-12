#! /bin/bash

# Perform removal of unnecessary packages and do full system upgrade
sudo eopkg rmf squashfs-tools resierfsprog dconf-editor hexchat transmission thunderbird xorg-driver-video-vmware xorg-driver-input-wacom openvpn orca onboard vpnc
sudo eopkg up 
sudo eopkg rmo

# Install everything needed for Go, C/C++, tinyGo and Fyne development
# Manually add Go, C/C++, clangd, Helium Icon Theme and One Dark Pro extensions to VSCode
# Manually set font to jetbrains-mono in VSCode
sudo eopkg it -y vscode golang git micro llvm-clang docker jetbrains-mono gcc-avr avr-libc avrdude
micro -plugin install go
sudo eopkg it -y -c system.devel mesalib-devel libxrandr-devel libxcursor-devel libxi-devel libxinerama-devel
go install honnef.co/go/tools/cmd/staticcheck fyne.io/fyne/cmd/fyne github.com/fyne-io/fyne-cross
sudo ln -s ~/go/bin/fyne /usr/bin/fyne
git config --global user.name "Edit Me"
git config --global user.email editme@example.com
git config --global core.editor micro

# Manually set up SSH and PGP keys for Git

# Install papirus icons (for usage on KDE)
sudo eopkg it papirus-icon-theme

# Install media related software
sudo eopkg it -y rawtherapee inkscape gimp entangle 
sudo eopkg it -y obs peek handbrake vlc
sudo eopkg it -y libreoffice-math
sudo eopkg it -y picard easytag
sudo eopkg it -y dolphin-emu godot

# Install system utilities
# File system tools in Solus are named "progs", "-tools" or "-progs".
# TODO: Replace exfat-utils with exfat-progs when it lands upstream
sudo eopkg it f2fs-tools exfat-utils btrfs-progs xfs-progs gnome-multiwriter

# Set up flatpak
sudo eopkg it -y flatpak xdg-desktop-portal-gtk xdg-desktop-portal-kde && flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
