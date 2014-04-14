#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
    #include <windows.h>
    typedef unsigned char   u_char;
    typedef unsigned short  u_short;
    typedef unsigned int    u_int;
    typedef unsigned long   u_long;

    BOOL WINAPI _DllMainCRTStartup(HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved) {
        return(TRUE);
    }
    BOOL WINAPI _DllMain(HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved) {
        return(TRUE);
    }
#else
    // gcc -shared -fPIC -o FILE.SO FILE.C
#endif



#include "sv_huffman.c"



int sudp_init(u_char *data) {
    printf("- PLUGIN: Doom huffman\n");     // plugin name

    if(data && !data[0]) {                  // help
        printf("- no plugin's options\n");
        return(1);
    }

    HuffInit();
    return(0);                              // 0 = ok
}



int sudp_pck(u_char *data, int len) {
    return(len);
}



int sudp_vis(u_char *data, int len) {
    static u_char   huffbuff[2000];     // blocked by MAX_UDP_SIZE

    HuffDecode(data, huffbuff, len, &len);
    memcpy(data, huffbuff, len);
    return(len);
}


