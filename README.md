Copilot setup scripts for Ubuntu 24.04 LTS
==========================================

This repo contains Copilot scripts for Copilot sessions led by InCycle. Please select the appropriate script for your session(s).

C++/JDK sessions
-----------------

There are 2 scripts, **you only need to run one** of them:

1. `scripts/ubuntu24-lite.sh` - this is the basic script, it will install the following components:
    - Git
    - Curl
    - Docker.io (an older version, but maintened by Ubuntu)
    - Docker Compose    (an older version, but maintened by Ubuntu)
    - build-essential
    - CMake
    - G++
    - GTest
    - boost
    - JDK 21
    - Python

This version is recommended for users who want to stick with the default Ubuntu packages.

2. `scripts/ubuntu24.sh` - this is the advanced script, it will install the following components:
    - Git
    - Curl
    - Docker (most recent one from docker)
    - Docker Compose
    - build-essential
    - CMake
    - G++
    - GTest
    - boost
    - JDK 21
    - Python, including notebooks and keras
    - .Net core 8.0

This version is recommended for users who want the most recent versions of the components, plus additional components like .Net.

### Notes

1. You **do not** need to run the other scripts if you are only running C++/JDK sessions.
2. The script must be run as root.
3. For C++ session please run just **one** of the scripts above. If you run both, you will just install the advanced version.

Node.js sessions
----------------

`scripts/install_node.sh` - this script will install the following components:
    - Node.js
    - NPM.

### Notes

1. You do not need to run the C++/JDK script before if you are only running Node.js sessions. without C++ components. Basic C++ components are installed by this script.
2. The script must be run as root.
3. If you do need C++ components, you must run the C++/JDK script first.


Go sessions
-----------

`scripts/install_go.sh` - this script will install the following components:
    - Go

### Notes

1. You do not need to run the C++/JDK script before if you are only running Go sessions. without C++ components.
2. The script must be run as root.
3. If you do need C++ components, you must run the C++/JDK script first.
