# suite-attacks-dos
A lot of attacks DoS using c<br>
This tool will start sending packages with slow velocity for 30 seconds. After, the
attack will increase three times for 120 seconds.
## Usage
Just run:
`make`
`./run -s server_ip`
## Attack architecture
This is the architecture of the attack.

We have a server with IP 192.168.20.14 and an attacker with other IP.
This software will run in attacker's pc. And will send packages to
the server.
[[arq.png]]
