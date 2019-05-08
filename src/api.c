#include "api.h"



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

int portscan(){
    int sockfd, port;
    struct hostent *he;

    for(port=0; port<=65000; port++)
    {
        struct sockaddr_in their_addr; // connector's address information
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
            perror("socket");
            exit(1);
        }

        their_addr.sin_family = AF_INET;    // host byte order
        their_addr.sin_port = htons(port);  // short, network byte order
        their_addr.sin_addr = *((struct in_addr *)he->h_addr);
        memset(&(their_addr.sin_zero), '\0', 8);  // zero the rest of the struct

        if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
        {
            close(sockfd);
        }
        else
        {
            printf("%i open\n", port);
            close(sockfd);
        }
    }
}

