Docker samples for Copilot
============================

Docker
------

To test your docker installation, you can run the following command:

```bash
sh scripts/run_docker_nginx.sh
```

This will start a docker container with nginx and expose it on port 10080. You can test it by opening a browser and going to `http://localhost:10080`.

Note: in some systems, you might be blocked from accessing localhost or non https sites.
In that case use the curl command:

```bash
curl localhost:10080
```

Docker compose
--------------

To test your docker-compose installation, you can run the following command:

from within the compose folder, run:

```bash
docker-compose up
```

You should be able to see MySql and redis running.
