#!/bin/bash

sudo cp interfaces /etc/network
sudo cp setup-adhoc.c ~/routing-control/
sudo cp record-route.c ~/routing-control/

cd ~/routing-control
gcc rc.c setup-adhoc.c -o setup-adhoc
gcc rc.c record-route.c -o record-route

mkdir route-record