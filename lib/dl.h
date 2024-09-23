#pragma once
#ifndef _DL_HEADER_HH
#define _DL_HEADER_HH
#include <sys/types.h>
#include <stddef.h>

//
// module_segment - structure representing a segment of a module (library)
struct module_segment {
    uint64_t addr;    // Base address of the segment in memory
    uint32_t size;    // Size of the segment in bytes
    uint32_t flags;   // Flags indicating segment attributes (e.g., readable, writable)
};

//
// module_info_ex - structure containing the information of a module (.sprx?)
//
struct module_info_ex {
    size_t st_size;                    // Size of this structure
    char name[256];                    // Name of the module (library)
    int id;                            // Identifier for the module
    uint32_t tls_index;                // Index for thread-local storage (TLS)
    uint64_t tls_init_addr;            // Address for TLS initialization function
    uint32_t tls_init_size;            // Size of the TLS initialization data
    uint32_t tls_size;                 // Size of the thread-local storage
    uint32_t tls_offset;               // Offset for TLS in the module
    uint32_t tls_align;                // Alignment for TLS data
    uint64_t init_proc_addr;           // Address of the initialization function
    uint64_t fini_proc_addr;           // Address of the finalization function
    uint64_t reserved1;                // Reserved for future use
    uint64_t reserved2;                // Reserved for future use
    uint64_t eh_frame_hdr_addr;        // Address of the exception handling frame header
    uint64_t eh_frame_addr;            // Address of the exception handling frame
    uint32_t eh_frame_hdr_size;        // Size of the exception handling frame header
    uint32_t eh_frame_size;            // Size of the exception handling frame
    struct module_segment segments[4]; // Array of module segments (up to 4)
    uint32_t segment_count;            // Number of segments in the module
    uint32_t ref_count;                // Reference count for the module (used for unloading)
};

#endif
