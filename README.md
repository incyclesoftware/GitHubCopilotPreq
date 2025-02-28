Copilot Ubuntu scripts
=======================

This repository contains scripts to install and configure Ubuntu 24.04 LTS for Copilot sessions with InCycle.
Note that these scripts are intended to be run on an Ubuntu 24.04 LTS installation, lower versions may not work.

Included scripts
----------------

### All scripts must be run as root

Main Ubuntu script, including C++ components:
------------

```bash
sudo .scripts/ubuntu.sh
```

This will install the following components:

- Git
- Curl
- Docker
- Docker Compose
- build-essential
- CMake
- G++
- GTest
- boost
- JDK 21
- Python, including notebooks and keras
- .net core 8.0

Run this for C++/JDK sessions.

### Testing the scripts:

There are test samples in the `samples` folder.

1. boost test run `make` in the `samples/boost` folder. Run `make run` to execute the test. 

    you can test the server running `telnet localhost 25252`.
2. gtest test: run `make` in the `samples/gtest` folder. Run `make run` to execute the test.
3. docker test: `run docker_nginx.sh` from `samples/docker/scripts/` folder. Run `curl localhost:10080` to test the server.
4. docker-compose test: `run docker_compose up` from `samples/docker/compose/`


### All the scripts below require the main script to be run first.

Node.js script
-----------------

```bash
sudo .scripts/install_node.sh
```

This will install the following components:

- Node.js
- NPM

For Node.js sessions, incuding Angular, React, Vue.js, etc.

Go script
------------

```bash
sudo .scripts/install_go.sh
```

This will install the following components:

- Go

For Go sessions, including gin, echo, etc.
