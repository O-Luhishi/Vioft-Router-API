///** The implementation of the GetAPIFunctions function **/
#include "interface.h"

static api_info_t gl_lstCgiApiFuctionInfo[] = {
        map("/demo/hello", "get", demo_hello),
        map("/client/list", "get", get_list_of_connected_clients),
};

api_info_t* get_api_entity(int* pLen)
{
    (*pLen) = sizeof(gl_lstCgiApiFuctionInfo) / sizeof(gl_lstCgiApiFuctionInfo[0]);
    return gl_lstCgiApiFuctionInfo;
}