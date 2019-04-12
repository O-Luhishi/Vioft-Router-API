#include "demo.h"



int demo_hello(json_object* input, json_object* output)
{
    json_object_object_add(output, "msg", json_object_new_string("TEST World"));
    return 0;
}


int get_list_of_connected_clients(json_object* input, json_object* output){
    FILE *filepath;
    char output_line[1035];
    int index=0;
    char arr_clients[30][100];

    filepath = popen("./Sample_Bash_Script_Test.sh", "r");
    if (filepath == NULL){
        printf("Failed To Run Script \n");
        exit(1);
    }
    while (fgets(output_line, sizeof(output_line)-1, filepath) != NULL){
        stpcpy(arr_clients[index], output_line);
        index++;
    }
    pclose(filepath);


    /*Creating a json object*/
    json_object * jobj = json_object_new_object();

    /*Creating a json array*/
    json_object *jarray = json_object_new_array();
    json_object *jstring[3][3];


    for (int y=0; y < 3; y++) {
        int x = 0;
        char *p = strtok(arr_clients[y], " ");
        char *array[3][3];

        while (p != NULL) {
            array[y][x++] = p;
            p = strtok(NULL, " ");
        }

        for (x = 0; x < 3; ++x) {
            printf("%s\n", array[y][x]);
            jstring[y][x] = json_object_new_string(array[y][x]);
            jstring[y][x] = json_object_new_string(array[y][x]);
            jstring[y][x] = json_object_new_string(array[y][x]);

        }
    }
    int i;
    int z;
    for (z=0; z < 3; z++) {
        for (i = 0; i < 3; i++) {
            json_object_array_put_idx(jarray, i + 2, jstring[z][i]);
        }
    }
    /*Form the json object*/
    json_object_object_add(jobj,"Categories", jarray);
    /*Now printing the json object*/
    printf ("The json object created: %sn",json_object_to_json_string(jobj));

    printf("%s", arr_clients[0]);

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