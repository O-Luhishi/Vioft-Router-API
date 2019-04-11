#include "demo.h"



int demo_hello(json_object* input, json_object* output)
{
    json_object_object_add(output, "msg", json_object_new_string("TEST World"));
    return 0;
}


int get_list_of_connected_clients(json_object* input, json_object* output){
    FILE *fp;
    char path[1035];

    int i=0;
    const char *a[3];

    fp = popen("./Sample_Bash_Script_Test.sh", "r");
    if (fp == NULL){
        printf("Failed To Run Script \n");
        exit(1);
    }
    while (fgets(path, sizeof(path)-1, fp) != NULL){
        a[i] = path;
        i++;
    }
    printf("Array 1 : %s", a[0]);
    printf("Array 2 : %s", a[1]);
    pclose(fp);
    json_object_object_add(output, "Client", json_object_new_string(path));
    return 0;
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