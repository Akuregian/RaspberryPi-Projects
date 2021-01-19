This Tutorial will explain how to setup a full LAMP {Linux, Apache, MySQL, PHP} stack on the Raspberry Pi, using Ubunto Server.
- This will be a Terminal, where you can create your lamp Stack.


1) Download the Raspi Pi Imager, Then Select Ubunto Server 32 bit and download this too a SD Card
2) Boot the Raspi and Login:
  [Defualt Username and Passwords]
  - Username: ubunto
  - password: ubunto
3) At this point, You should have Ubuntu Server installed, BUT not connected to the wifi if you didnt hook it up too ethernet.
  - To solve this:
      - Navigate 'cd /etc/netplan' where there should be a '50-cloud-init.yaml' file. [Open this File using Vim]
      - Under 'version: 2', start adding the following to connect wirelessly
      ```yaml
      wifis:
        wlan0:
          dhcp4: true
          optional: true
          access-points:
            "NameOfWirelessRouter":
              password: "Password"
      ```
   - 'sudo reboot' and it should have connected to your wireless router.

   
4) Connect Using SSH
   - run the command in the termincal to enable ssh 'sudo systemctl ssh enable' or if the fails 'sudo systemctl ssh start'
   - check to ensure ssh is up and running. 'sudo service ssh status'
   - Download Putty to ssh into Raspi by connecting to the Rapi via IP Address [Just Type in IP into Putty and clicked Connect]
   
5) Install Some Packages:
  - 'sudo apt-get install php libapache2-mod-php php-mysql'
  - 'sudo apt-get install mysql'
      - run the command to clean up security vulnerabilites 'sudo mysql_secure_installation'
6) Navigate too 'cd /var/www' and change the privilages of the directory bt running the command 'sudo chown NameOfUser html' (chown[Change Owner Ship], NameOfUser: root@localhost, wher root is the user name.. another example ubuntu@ubuntu ---> username: ubuntu)
  - cd into html and remove the index.html and replace it with index.php
  - Add the script to test that everything is working:
    ```php
     <?php
     phpinfo()
     ?> ```
     
  - 'sudo service apache2 restart'
  

7
