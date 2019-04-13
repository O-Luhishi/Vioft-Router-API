#include "demo.h"



int demo_hello(json_object* input, json_object* output)
{
    json_object_object_add(output, "msg", json_object_new_string("TEST World"));
    return 0;
}


int get_list_of_connected_clients(json_object* input, json_object* output) {
    json_object *clients = json_object_new_array();
    char line[1024];
    FILE *filepath;

    filepath = popen("./Sample_Bash_Script_Test.sh", "r");
    if (filepath == NULL){
        printf("Failed To Run Script \n");
        exit(1);
    }

    while (fgets(line, sizeof(line), filepath) != NULL) {
        json_object_array_add(
                clients,
                bash_connected_clients_line_to_json(line)
        );
    }

    json_object_object_add(output, "Clients", clients);
    return 0;
}

json_object* bash_connected_clients_line_to_json( const char *line ) {
    char hostname[1024], ip[1024], macaddr[1024];
    if( sscanf(line, "%1023s %1023s %1023s", hostname, ip, macaddr) != 3 ) {
        fprintf(stderr, "Could not parse line: '%s'\n", line);
        return NULL;
    }

    json_object *json = json_object_new_object();

    json_object_object_add(json, "Hostname", json_object_new_string(hostname));
    json_object_object_add(json, "IP", json_object_new_string(ip));
    json_object_object_add(json, "MacAddr", json_object_new_string(macaddr));

    return json;
}

///** The implementation of the GetAPIFunctions function **/
#include "glapibase.h"

static api_info_t gl_lstCgiApiFuctionInfo[] = {
        map("/demo/hello", "get", demo_hello),
        map("/client/list", "get", get_list_of_connected_clients),
};

api_info_t* get_api_entity(int* pLen)
{
    (*pLen) = sizeof(gl_lstCgiApiFuctionInfo) / sizeof(gl_lstCgiApiFuctionInfo[0]);
    return gl_lstCgiApiFuctionInfo;
}