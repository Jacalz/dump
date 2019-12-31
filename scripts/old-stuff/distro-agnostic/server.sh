#! /bin/bash
# A shell script for starting and taking care of a minecraft server
# server.sh: version 1.3.1

echo "Cleaning up the logs"
rm -r ~/server/logs/*

echo "Starting the server"
cd ~/server/
java -jar -Xms2048M -Xmx6144M server.jar nogui

echo "Backing up the server"
cd $HOME
zip -r server.zip server
mv $HOME/server.zip $HOME/Documents/minecraft-server.zip
