#ifndef DEMO_H
#define DEMO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

int demo_hello(json_object* input, json_object* output);

int get_list_of_connected_clients(json_object* input, json_object* output);

#endif /* demo.h */