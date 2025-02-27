#!/bin/bash
if [ "$1" = "" ]; then
  node_version=$(curl  https://nodejs.org/en/|grep -Po "v(\d+\.\d+\.\d)"|head -n 1)
else
  node_version=$1
fi

if [ "$node_version" = "" ]; then
  echo "Could not find node version!"
  exit 1
fi

wget https://nodejs.org/dist/$node_version/node-$node_version-linux-x64.tar.xz
sudo apt-get install -y build-essential libkrb5-dev
tar -xf node-$node_version-linux-x64.tar.xz
cd node-$node_version-linux-x64
sudo cp -R bin/* /usr/bin/
sudo cp -R lib/* /usr/lib/
sudo cp -R share/* /usr/share/
sudo cp -R include/* /usr/include/
sudo npm install gulp -g
rm -rf node-$node_version
sudo npm install -g npm@11.1.0

