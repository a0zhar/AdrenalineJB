# PS4 (PlayStation 4) Information
#### A Brief Overview of the PS4 (Playstation 4)'s System Software Components, Kernel Space, Development Tools, and more. The system software runs on a customized version of **FreeBSD**, a Unix-like operating system, with Sony modifying FreeBSD 9.0 as its foundation.

### Operating System (OS)
- The PS4 operating system, known as **Orbis OS**, is derived from **FreeBSD 9.0**.
- Orbis OS shares many characteristics with FreeBSD, including its Unix-like structure and POSIX compliance. 
- Sony has made significant modifications, adding proprietary drivers, APIs, and features to support PS4 hardware, such as the AMD-based APU (Jaguar CPU and GPU) and custom I/O systems.

### Kernel
- The PS4's kernel is based on the **FreeBSD 9.0 kernel**, modified to suit the console's specific hardware.
- Proprietary drivers have been added to support custom hardware (e.g., AMD Radeon GPU, audio, and input systems like the DualShock 4 controller).
- The kernel is optimized for low-latency operations, crucial for real-time gaming performance, and includes enhancements for power management and fast context switching.

### Additional System Information
- **Standard Libraries**: Orbis OS supports standard POSIX-compliant libraries, including those from FreeBSD's **libc**.
- **Graphics APIs**: The PS4 uses a custom low-level API called **GNM** for rendering, optimized for its AMD GPU. There's also **GNMX**, which offers higher-level functionality similar to Direct3D or OpenGL.
- **Audio and Networking**: Sony provides proprietary libraries for sound, networking, and input/output operations, integrated into the FreeBSD-based user space.

### Development Tools & C/C++
- **Compiler**: Sony supplies a custom development kit (SDK) featuring an **LLVM/Clang** compiler for C/C++ development. The PS4 SDK does not use GCC (GNU Compiler Collection) but is tightly integrated with the platform's architecture and optimizations.
- **Supported C/C++ Standards**: `Unknown Which System FW's this applies to`:
  - **C++11 and possibly C++14**: Full support for C++11 is expected, with partial support for C++14 depending on the SDK version.
  - **C99** and possibly **C11**: The system fully supports C99, with some features of C11 potentially available based on compiler updates.
- **SDK**: The proprietary SDK includes libraries for networking, audio, controller input, trophies, and various PlayStation Network (PSN) services.

### File System
- The PS4 utilizes a **custom version of FreeBSD's UFS (Unix File System)**, and may support **exFAT** for external storage devices. The primary file system is optimized for game data storage, retrieval, caching, and large file handling (e.g., game assets, save data).

### Other Subsystems
- **Networking**: The PS4's networking stack is built on FreeBSD's robust TCP/IP stack, featuring additional libraries for integration with PlayStation Network (PSN) services.
- **Audio**: A proprietary audio subsystem supports advanced 3D audio capabilities and multimedia features necessary for games and applications.
- **Storage and Memory**: The system uses a **custom virtual memory system** optimized for the hardware's 8 GB of GDDR5 unified memory, providing high memory bandwidth essential for both CPU and GPU operations.
