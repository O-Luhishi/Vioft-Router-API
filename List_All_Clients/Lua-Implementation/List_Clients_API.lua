#!/usr/bin/lua

local json = require ("root.dkjson")

-- Take Bash Script Output & Returns It As A String
function read_input_from_wifi_clients_script()
  local text = assert(io.popen('root/show_wifi_clients.sh', 'r'))
  local output = text:read('*a')
  text:close()
  return output
end

-- Main Function Which Parses In The Bash Script Ouput & Creates Clients Array
function create_connected_clients_array()
  local count = 0
  local clients ={}
  local file = read_input_from_wifi_clients_script()
  for line in file:gmatch("[^\r\n]+") do
    count = count + 1
    local client = {}
    client.hostname, client.ip, client.mac = line:match("(%S+) (%S+) (%S+)")
    table.insert(clients, client)
  end
  return clients
end

function return_array()
   client_table = create_connected_clients_array()
   local st = json.encode(client_table)
   return st
end

function handle_request(env)
        client_list_array = return_array()
        uhttpd.send("Status: 200 OK\r\n")
        uhttpd.send("Content-Type: text/plain\r\n\r\n")
        uhttpd.send(client_list_array)
end
