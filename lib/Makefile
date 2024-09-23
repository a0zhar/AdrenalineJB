CC     := gcc
AS     := yasm
PYTHON := python3
LD     := ld

# Source files and output
OBJS      := crt.o dl.o syscalls.o
LIB       := lib.a
ASM_FILES := syscalls.asm

# Targets
all: $(LIB)

$(LIB): $(OBJS)
	@echo "Linking object files into static library: $(LIB)"
	@$(LD) -r $(OBJS) -o $(LIB)
	@echo "Library $(LIB) created successfully."

clean:
	@echo "Cleaning up..."
	@rm -f $(LIB) $(OBJS) $(ASM_FILES)
	@echo "Clean complete."

dl.o: dl.c
	@echo "Compiling dl.c to dl.o"
	@$(CC) -c -isystem ../freebsd-headers -nostdinc -fno-stack-protector dl.c -o dl.o -fPIE -ffreestanding

crt.o: crt.asm
	@echo "Assembling crt.asm to crt.o"
	@$(AS) -f elf64 crt.asm -o crt.o

syscalls.o: syscalls.asm
	@echo "Assembling syscalls.asm to syscalls.o"
	@$(AS) -f elf64 syscalls.asm -o syscalls.o

syscalls.asm: syscalls.py
	@echo "Generating syscalls.asm from syscalls.py"
	@$(PYTHON) syscalls.py > syscalls.asm

.PHONY: all clean
