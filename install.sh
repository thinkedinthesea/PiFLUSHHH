#! /bin/bash
#
#THINKEDINTHESEA
#PiFUN
#
#rev03122019
#rev10092020
#
if [ $(id -u) -ne 0 ]; then
	echo "Installer must be run as root."
	echo "Try 'sudo bash $0'"
	exit 1
fi
clear
#
echo "------------------------------------------------------------------"
echo "This script downloads and install"
echo "POWERMYPI-UNO python script"
echo
echo "- Update package index files (apt-get update)."
echo "- Install Python libraries."
echo "- Install powermypi_uno.py script in /usr/local/bin."
echo
echo "WARNING:"
echo "After install complete, shutdown and connect POWERMYPI-UNO board."
echo "------------------------------------------------------------------"
echo
echo -n "CONTINUE? [y/N] "
read
if [[ ! "$REPLY" =~ ^(yes|y|Y)$ ]]; then
	echo "Cancelled."
	exit 0
fi
#
echo -n "Downloading, installing powermypi_uno..."
# Download to tmpfile because might already be running
curl -f -s -o /tmp/powermypi_uno.py https://raw.githubusercontent.com/thinkedinthesea/PowermyPi-UNO/master/powermypi_uno.py
if [ $? -eq 0 ]; then
	mv /tmp/powermypi_uno.py /usr/local/bin
	chmod 755 /usr/local/bin/powermypi_uno.py
	echo "OK"
else
	echo "ERROR"
fi
#
echo -n "Performing other system configuration..."
echo
echo
apt update
apt install python3-pip
pip3 install rpi.gpio
echo
echo
echo "Add cronjob..."
echo
##
crontab -l | grep -v "@reboot sudo /usr/bin/python3 /usr/local/bin/powermypi_uno.py &" | crontab -
crontab -l | { cat; echo "@reboot sudo /usr/bin/python3 /usr/local/bin/powermypi_uno.py &"; } | crontab -
##
echo
echo -n "SHUTDOWN NOW? [y/N]"
read
if [[ "$REPLY" =~ ^(yes|y|Y)$ ]]; then
	echo "Shutdown started..."
	shutdown
#else
	echo
	echo "Done"
fi
