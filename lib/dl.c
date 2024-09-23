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

//
// Custom implementation of the dlopen() with extended capabilities
void *dlopen_ex(const char *path, int mode /* ignored */, void *data, size_t data_len) {
    int handle = 0; // Handle for the loaded module

    // Load the module from the specified path. Return NULL on failure
    if (dynlib_load_prx(path, 0, &handle, 0))
        return NULL;

    // Define and Initialize structure to hold module information
    struct module_info_ex mi = { .st_size = sizeof(struct module_info_ex) };

    // Get information about the loaded module. Return NULL on failure
    if (dynlib_get_info_ex(handle, 0, &mi))
        return NULL;

    // If the module's reference count is less than 2, we try to Call the 
    // initialization function?
    if (mi.ref_count < 2) {
        // Custom/Private typedef function pointer, only used by dlopen_ex() that
        // acts as a replacement for the previous method of doing a: Function ptr
        // cast and then direct invocation.
        typedef int (*dlUtilsFunctionInit)(size_t, void *, void *);
        
        // Cast the initialization procedure address to the function pointer type.
        // Then we Execute the initialization function with the provided data
        dlUtilsFunctionInit init_func = (dlUtilsFunctionInit)mi.init_proc_addr;
        init_func(data_len, data, NULL);
    }

    // Return the handle as a pointer
    return (void *)(long long)handle;
}

// Standard implementation of dlopen(), calling the custom version without additional data
void *dlopen(const char *path, int mode) {
    return dlopen_ex(path, mode, NULL, 0);
}

// Function to retrieve the address of a symbol from a loaded module
void *dlsym(void *handle, const char *name) { 
    void* addr = NULL; // Holds the resolved symbol address

    // Call the symbol resolution function and pass the handle and name
    dynlib_dlsym((int)(long long)handle, name, &addr);
    
    // Return the address of the resolved symbol
    return addr;
}
