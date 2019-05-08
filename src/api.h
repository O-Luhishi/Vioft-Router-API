#ifndef DEMO_H
#define DEMO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>


int demo_hello(json_object* input, json_object* output);

json_object* bash_connected_clients_line_to_json( const char *line );

int get_list_of_connected_clients(json_object* input, json_object* output);

int portscan();

#endif /* demo.h */