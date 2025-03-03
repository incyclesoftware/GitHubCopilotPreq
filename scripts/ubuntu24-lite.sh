apt-get update
# apt-get dist-upgrade -y
apt-get install -y build-essential linux-headers-generic libxmltooling-dev gdb gdbserver cmake libcppunit-dev libclang-dev  openjdk-21-jdk clang-tools llvm nasm cmake net-tools valgrind -y
apt-get install -y libboost-all-dev scons libecryptfs-dev libssl-dev libcurlpp-dev libclang-dev linux-tools-generic  libswscale-dev libswresample-dev libpostproc-dev libavdevice-dev ffmpeg -y
apt-get install -y python3 python3-pip zip unzip ninja-build flex bison

## google tests
git clone https://github.com/google/googletest.git
cd googletest/
cmake .
sudo make install

apt-get install docker.io docker-compose -y
sudo usermod -aG docker $USER
apt-get autoremove -y
sudo usermod -aG docker $USER
echo "you must reboot to use docker as a user."
