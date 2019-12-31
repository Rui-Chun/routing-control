# Routing-control

## How to use on raspberry pi

1.change firmware if need to change bitrate: firmwares folder

2.change time zone and set time, if need print route table

3. change ip address on interfaces file & cp it into /etc/network

4. compile *.c file  : setup-adhoc record-route

5.change startup config : /etc/rc.local, add setup-adhoc, so that it runs once booted

## Done

setup.c : auto set up when boot
ctrl.txt: control message for testing

## TO DO

main: main routing control

ip-mac: ip address <--> mac address

mac-power-rate: control driver



