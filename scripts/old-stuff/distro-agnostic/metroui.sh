#! /bin/bash
# This script is what creates the MetroUI files for Darwin/Linux and Redmond
# This script is very basic and doesn't even work right now...

echo "Downloading Metro for Steam 4 and the unofficial patch"
    mkdir /home/jacalz/MetroUI/
    cd /home/jacalz/MetroUI/
    wget https://metroforsteam.com/downloads/4.2.4.zip
    unzip /home/jacalz/MetroUI/4.2.4.zip
    git clone https://github.com/redsigma/UPMetroSkin.git

echo "Merging the two projects in to one"
    mv -f Metro_4.2.4 UPMetroSkin

echo "Creating the files for Darwin/Linux"


echo "Creating the files for Redmond (Windows)"
