#!/bin/sh

# /etc/config/show_wifi_clients.sh
# Shows MAC, IP address and any hostname info for all connected wifi devices

for interface in `iwinfo | grep ESSID | cut -f 1 -s -d" "`
do
  # for each interface, get mac addresses of connected stations/clients
  maclist=`iwinfo $interface assoclist | grep dBm | cut -f 1 -s -d" "`
  # for each mac address in that list...
  for mac in $maclist
  do
    # If a DHCP lease has been given out by dnsmasq,
    # save it.
    ip="UNKN"
    host=""
    ip=`cat /tmp/dhcp.leases | cut -f 2,3,4 -s -d" " | grep -i $mac | cut -f 2 -s -d" "`
    host=`cat /tmp/dhcp.leases | cut -f 2,3,4 -s -d" " | grep -i $mac | cut -f 3 -s -d" "`
    # ... show the mac address:
    echo "$host" "$ip" "$mac"
done
done
