#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "api.h"
#include "interface.h"


void test_demo_hello()
{
    json_object* input = json_object_new_object();
    json_object* output = json_object_new_object();

    demo_hello(input, output);

    printf("result:\n%s\n", json_object_to_json_string(output));

    json_object_put(input);
    json_object_put(output);
}
void test_list_of_connected_devices()
{
    json_object* input = json_object_new_object();
    json_object* output = json_object_new_object();
    get_list_of_connected_clients(input, output);
    printf("Connected Clients:\n%s\n", json_object_to_json_string(output));
    json_object_put(input);
    json_object_put(output);
}

void test_port_scanning()
{
    json_object* input = json_object_new_object();
    json_object* output = json_object_new_object();
    portscan();
}

int main(int argc , char *argv[])
{
    if (argv[1] == NULL){
        printf("\n/demo/hostname_set result:\nUsage: demotest <hostname>\n\n");
        return -1;
    }else if (!strcmp(argv[1], "/client/list")) {
        test_list_of_connected_devices();
    }else if (!strcmp(argv[1], "/demo/hello")) {
        test_demo_hello();
    }else if(!strcmp(argv[1], "services/portscan")){
        test_port_scanning();
    }
    return 0;
}