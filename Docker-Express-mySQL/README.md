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
2. # Executing the Docker Command Without Sudo [OPTIONAL] 

    run : ``` sudo usermod -aG docker $USER ```
    - ``` $USER ``` is an environment variable that holds your username. You dont need to change anything, just run the command
3. # Test That Everything Worked
    ``` docker container run hello-world ```
