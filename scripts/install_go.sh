#!/bin/bash

sudo apt-get update
if [ "$1" = "" ]; then
	go_version=$(curl https://go.dev/dl/ | grep -Po "go(\d+\.\d+\.\d)" |head -n 1|cut -c 3-20)
else
	go_version=$1
fi
clear
echo "Looking for Go version "$go_version
wget https://storage.googleapis.com/golang/go$go_version.linux-amd64.tar.gz
tar -xf go$go_version.linux-amd64.tar.gz
rm -rf /usr/local/go
cp -R go /usr/local/
rm -rf go go$go_version.linux-amd64.tar.gz
entry=$(cat /etc/profile|grep /usr/local/go)
if [ "$entry" = "" ]; then
	echo "adding an entry"
	echo "export PATH=$PATH:/usr/local/go/bin" >> /etc/profile
else
	echo "go root set up."
fi

echo "you must log out and log back in to use go"
