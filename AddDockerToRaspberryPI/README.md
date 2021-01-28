1. Install Docker
- `curl -sSL https://get.docker.com | sh`

2. Add permission to User to run Docker Commands
- `sudo usermod -aG docker [USER]`

Reboot here or run the next commands with a sudo

3. Test Docker installation
- `docker run hello-world`

4. IMPORTANT! Install proper dependencies
- `sudo apt-get install -y libffi-dev libssl-dev`

- `sudo apt-get install -y python3 python3-pip`

- `sudo apt-get remove python-configparser`

5. Install Docker Compose
- `sudo pip3 -v install docker-compose`

Boom! 🔥 It's done!

To Get Rid Of Sudo:  'sudo gpasswd -a $USER docker'

** RESTART or REBOOT Device **


## ----------------------------------------------------------------------------------------------------------
  Steps For Setting Docker Conatiner for [Amazon Dev Alexa Rasp] Project
  somelibs:['unzip', '']
   1. After Setting Up the Docker Container from Above
    - 'sudo apt-get python3-dev'
    - 'python3 -m pip install Flask-Ask' .... If fails: 'pip install git+https://github.com/johnwheeler/flask-ask.git@v0.8.8'
    - 'sudo apt install python3-testresources'
    - 'pip3 install --upgrade setuptools '
    - 'pip3 install 'cryptography<2.2'' ---> then 'pip3 install 'cryptography==2.5''
    - 'sudo apt-get install rpi.gpio'
    - 'sudo apt-get install unzip'
    - 'wget https://bin.equinox.io/c/4VmDzA7iaHb/ngrok-stable-linux-arm.zip
     - 'unzip ngrok-stable-linux-arm.zip' 
     - Create an Account For NGROK So that it doesnt reset the URL link it created for you
     - Login and Grab the Auth Token, then run--> './ngrok authtoken <TOKEN>'
    - 
