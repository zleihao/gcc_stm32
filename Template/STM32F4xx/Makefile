######################################
# target
######################################
TARGET = Hao

######################################
SYS_DIR    = -I./Hardware/inc
SYS_SOURCE = ./Hardware/src
######################################

# user_Source 添加.c文件
USER_SOURCE =                     \
	$(wildcard $(SYS_SOURCE)/*.c) \
	./CMSIS/system_stm32f4xx.c

######################################
#openocd路径配置 
OPENOCD_DOWN_PATH = C:/openocd/openocd/scripts/interface/cmsis-dap.cfg
OPENOCD_CHIP_PATH = C:/openocd/openocd/scripts/target/stm32f4x.cfg


######################################
# 启动文件选择
STARTUP = startup_stm32f40xx.s

# 系统外设库
STD_PERIPH_LIB_SRC = \
$(wildcard ./Libraries/src/*.c)

STD_PERIPH_LIB_INC =             \
	-I ./Libraries/inc           \
	-I ./CMSIS/Device/Include    \
	-I ./CMSIS/Include 


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -O0

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =               \
	$(wildcard ./Users/*.c)   \
	$(USER_SOURCE)            \
	$(STD_PERIPH_LIB_SRC)


# ASM sources
ASM_SOURCES =  \
	./CMSIS/Device/StartUp/$(STARTUP)


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS =

# C defines
C_DEFS =                   \
-DUSE_STDPERIPH_DRIVER     \
-DSTM32F40_41xxx

# AS includes
AS_INCLUDES =  

# C includes
C_INCLUDES =                 \
	-I./Users                \
	$(SYS_DIR)				 \
	$(STD_PERIPH_LIB_INC)            

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = ./Link/STM32F40_41xxx/STM32F417IGHx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections -lc -lrdimon -u _printf_float


# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
#windows
.PHONY : clean
clean:
	del /s/q $(BUILD_DIR)
#linux
#clean:
#	rm -rf $(BUILD_DIR)

download:
	openocd -f $(OPENOCD_DOWN_PATH) -f $(OPENOCD_CHIP_PATH)  -c init -c halt -c "flash write_image erase ./build/$(TARGET).hex" -c reset -c halt -c shutdown

#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
