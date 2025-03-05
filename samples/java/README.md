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

Go to the console folder and run the following command:
```bash
gradle run
```