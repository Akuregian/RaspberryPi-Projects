# Install Docker on Raspberry Pi
## Installing Docker on Raspberry Pi is just a matter of running a few commands.
1. First, download the Docker installation script using the following curl command :
    ```
    curl -fsSL https://get.docker.com -o get-docker.sh

    ```

  - Once the download is complete, execute the script by typing:

    ```
    sh get-docker.sh
    ```
2. ## Executing the Docker Command Without Sudo [OPTIONAL] 

    run : ``` sudo usermod -aG docker $USER ```
    - ``` $USER ``` is an environment variable that holds your username. You dont need to change anything, just run the command
3. ## Test That Everything Worked
    ``` docker container run hello-world ```
    
    
- More Info can be found: https://linuxize.com/post/how-to-install-and-use-docker-on-raspberry-pi/


### ---------------------------------------------------------------------------------------------------------------------
-  Now you can add Docker Images to containers and create the enviroment you desire.
## Commands:
    - Add New Images --> Go To Docker Hub and grab the command...  ' docker pull [ImageName]  '
    - View All Images: docker image ls
    - run a container: docker container run [docker-container]
## Docker-Compose:
    - Is used for defining and running multi-container Docker applications. With Compose, you use a YAML file to configure your application’s services. 
    
    - Then, with a single command, you create and start all the services from your configuration.
    
    - # Using Compose is basically a three-step process:

        - 1. Define your app’s environment with a Dockerfile so it can be reproduced anywhere.

        - 2. Define the services that make up your app in docker-compose.yml so they can be run together in an isolated environment.

        - 3. Run docker-compose up and Compose starts and runs your entire app.
        
        - A docker-compose.yml looks like this:
        ```python
        version: "3.9"  # optional since v1.27.0
        services:
          web:
            build: .
            ports:
              - "5000:5000"
            volumes:
              - .:/code
              - logvolume01:/var/log
            links:
              - redis
          redis:
            image: redis
        volumes:
          logvolume01: {}
        ```
        
    
    
    
    
    
    
    
    
