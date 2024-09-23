// ----------------------
// Sources Used: 
// https://gist.github.com/flatz/1055a8d7819c8478db1b464842582c9c
// ----------------------

// Header containing the structures previously defined here
#include "dl.h"

// Function to load a dynamic library (module) into memory
long long dynlib_load_prx(const char* path, int flags, int* handle, int unknown);
// Function to retrieve information about a loaded module
int dynlib_get_info_ex(int handle, int unknown, struct module_info_ex* info);
// Function to resolve a symbol's address in a module
long long dynlib_dlsym(int handle, const char* name, void** addr);

// Custom implementation of dlopen with extended capabilities
void *dlopen_ex(const char *path, int mode /*ignored*/, void *data, size_t data_len) {
    int handle = 0;
    if (dynlib_load_prx(path, 0, &handle, 0))
        return 0;
    struct module_info_ex mi;
    mi.st_size = sizeof(mi);
    if (dynlib_get_info_ex(handle, 0, &mi))
        return 0;
    if (mi.ref_count < 2)
        ((int(*)(size_t, void *, void *))mi.init_proc_addr)(data_len, data, 0);
    return (void *)(long long)handle;
}

// Standard implementation of dlopen(), calling the custom version without additional data
void *dlopen(const char *path, int mode) {
    return dlopen_ex(path, mode, NULL, 0);
}

// Function to resolve a symbol's address from a loaded module
void *dlsym(void *handle, const char *name) {
    void *addr = 0;
    dynlib_dlsym((int)(long long)handle, name, &addr);
    return addr;
}
