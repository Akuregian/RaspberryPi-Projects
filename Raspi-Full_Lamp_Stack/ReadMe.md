This Tutorial will explain how to setup a full lamp stack on the Raspberry Pi, using Ubunto Server.
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
