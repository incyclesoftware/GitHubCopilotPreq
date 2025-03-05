CPP samples for Copilot
=======================

In this folder you will find the samples for the Copilot sessions that are related to C++.
Make sure you run the ubuntu24 or ubuntu24-lite script before running the samples.

Boost example
--------------

 To run this sample, you need to be in the boost folder and run the following commands:

```bash
make run
```

An echo server will start in port 25252. You can test it by running the following command:

```bash
telnet localhost 25252
```

You can type any message and the server will echo it back to you.

GTest example
--------------

To run this sample, you need to be in the gtest folder and run the following commands:

```bash
make run
```

This will run the tests and show the results (all of which should pass).

cmake example
--------------

To run this sample, you need to be in the cmake folder and run the following commands:

```bash
mkdir build
cd build
cmake ..
make
./CopilotReady
```

This will build the project and run the executable.