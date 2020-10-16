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
echo "PiFLUSHHH python script"
echo
echo "- Update package index files (apt-get update)."
echo "- Install Python libraries."
echo "- Install script in /usr/local/bin."
echo
echo "WARNING:"
echo "After install complete, shutdown and connect PiFLUSHHH board."
echo "------------------------------------------------------------------"
echo
echo -n "CONTINUE? [y/N] "
read
if [[ ! "$REPLY" =~ ^(yes|y|Y)$ ]]; then
	echo "Cancelled."
	exit 0
fi
#
echo -n "Downloading, installing piFLUSHHH..."
# Download to tmpfile because might already be running
curl -f -s -o /tmp/piflush.py https://raw.githubusercontent.com/thinkedinthesea/PiFLUSHHH/main/piflushhh.py
curl -f -s -o /tmp/powermypi_uno.py https://raw.githubusercontent.com/thinkedinthesea/PiFLUSHHH/main/powermypi_uno.py
curl -f -s -o /tmp/led.py https://raw.githubusercontent.com/thinkedinthesea/PiFLUSHHH/main/led.py
if [ $? -eq 0 ]; then
	mv /tmp/piflushhh.py /usr/local/bin
	chmod 755 /usr/local/bin/piflushhh.py
	mv /tmp/powermypi_uno.py /usr/local/bin
	chmod 755 /usr/local/bin/powermypi_uno.py
	mv /tmp/led.py /usr/local/bin
	chmod 755 /usr/local/bin/led.py
	echo "OK"
else
	echo "ERROR"
	echo "Cancelled."
	exit 0
fi
#
echo -n "Performing other system configuration..."
echo
echo
apt update
apt install python3-pip
pip3 install rpi.gpio rpi_ws281x adafruit-circuitpython-neopixel
echo
echo
echo "Add cronjob..."
echo
##
crontab -l | grep -v "@reboot sudo /usr/bin/python3 /usr/local/bin/piflushhh.py &" | crontab -
crontab -l | { cat; echo "@reboot sudo /usr/bin/python3 /usr/local/bin/piflushhh.py &"; } | crontab -
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
