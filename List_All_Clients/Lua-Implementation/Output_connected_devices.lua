local json = require ("dkjson")

-- Take Bash Script Output & Returns It As A String
function read_input_from_wifi_clients_script()
  local text = assert(io.popen('./Sample_Bash_Script_Test.sh', 'r'))
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

output = create_connected_clients_array()
local str = json.encode (output)
print(str)

local handle = io.popen("pwd")
local result = handle:read("*a")
print(result)
handle:close()
