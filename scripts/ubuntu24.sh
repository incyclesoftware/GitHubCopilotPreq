apt-get update
# apt-get dist-upgrade -y
apt-get install -y build-essential linux-headers-generic libxmltooling-dev gdb gdbserver cmake libcppunit-dev libclang-dev  openjdk-21-jdk clang-tools llvm nasm cmake net-tools valgrind -y
apt-get install -y libboost-all-dev scons libecryptfs-dev libssl-dev libcurlpp-dev libclang-dev python3-venv libusb-1.0-0-dev libusb-0.1-4 linux-tools-generic libavformat-dev libavcodec-dev libavutil-dev libavfilter-dev libswscale-dev libswresample-dev libpostproc-dev libavdevice-dev ffmpeg -y
apt-get install -y ruby python3 ruby-dev python3-pip python3-notebook python3-sklearn python3-keras-applications zip unzip ninja-build python3-sphinx flex bison
# Add Docker's official GPG key:
sudo apt-get update
sudo apt-get install ca-certificates curl -y
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc

# Add the repository to Apt sources:
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
  $(. /etc/os-release && echo "${UBUNTU_CODENAME:-$VERSION_CODENAME}") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update
## add googoe tests globally here
git clone https://github.com/google/googletest.git
cd googletest/
cmake .
sudo make install

sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin docker-compose
sudo usermod -aG docker $USER
apt-get install -y dotnet-sdk-8.0
apt-get autoremove -y

echo "you must reboot to use docker as a user."
