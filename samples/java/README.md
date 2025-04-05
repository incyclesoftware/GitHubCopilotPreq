Java sample for Copilot
=======================

Installing Gradle
-----------------

1. To install Gradle, you'll need to download the Gradle binary distribution from the [Gradle website](https://gradle.org/releases/).
2. Unzip the distribution to a directory of your choice.
3. Add the `bin` and the parent directories of the unzipped distribution to your `PATH` environment variable.
    example:
    ```bash
    PATH=$PATH:/opt/gradle:/opt/gradle/bin
    ```
4. Verify the installation by running `gradle -v` in a terminal window.


Running the samples
-------------------

1. The console app (TDR session for Java):

    Go to the console folder and run the following command:
    ```bash
    gradle run
    ```

2. The web app (TDR session for Java):

    Go to the jsp folder and run the following command:
    ```bash
    gradle appRun
    ```
    
    If you can run the web app, you can access it at `http://localhost:8080/`.
    For the session you will need to install and test Node JS as well. You can find the installation for Linux [here](../../scripts/install_node.sh), for Windows, you can find the installation [here](https://nodejs.org/en/download/).
    After installation, you can test it by following the instructions in the [Node JS README](../../samples/nodejs/README.md).

    

