#!/usr/bin/lua

require "iwinfo"

local devices = {}
devices["5G"] = "wlan0"
devices["2.4G"] = "wlan1"

function getinfo(ifname, func)
        local driver_type = iwinfo.type(ifname)
        if driver_type and iwinfo[driver_type][func] then
                return iwinfo[driver_type][func](ifname)
        end
        return nil
end

local key, device
for key, device in pairs(devices) do
        local opmode = getinfo(device, "mode")
        if opmode == "Master" then
                local count = 0
                local assoclist = getinfo(device, "assoclist")
                if assoclist then
                        local _
                        for _ in pairs(assoclist) do
                        end
                end
                print(key .. " radio is up, " .. count .. " clients connected")
        else
                print(key .. " radio appears to be down")
        end
end
