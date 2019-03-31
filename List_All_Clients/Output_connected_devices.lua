-- Take Bash Script Output & Returns It As A String
function read_input_from_wifi_clients_script()
  local text = assert(io.popen('./Print_Wifi_Clients.sh', 'r'))
  local output = text:read('*a')
  text:close()
  return output
end

-- A Function To Print Out Clients Array
function parse_clients_array(clients, count)
  for i = 1, count do
    print ("Hostname:",clients[i][1],"IP:",clients[i][2],"MAC:",clients[i][3])
  end
end

-- Main Function Which Parses In The Bash Script Ouput & Creates Clients Array
function create_connected_clients_array()
  local count = 0
  local clients ={}
  local file = read_input_from_wifi_clients_script()
  for line in file:gmatch("[^\r\n]+") do
    count = count + 1
    local hostname, ip, mac = line:match("(.+)%s+(.+)%s+(.+)")
    local client = {hostname, ip, mac}
    table.insert(clients, client)
  end
  return client, count
end

create_connected_clients_array()
