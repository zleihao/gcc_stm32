######################################
# target
######################################
TARGET = FreeRtos_Hao

######################################
# target
######################################
TARGET = FreeRtos_Hao

SYS_DIR = -I./Hardware
SYS_SOURCE = ./Hardware
######################################

# 若添加新的文件在目录Hardware下，只需在“USER_INC”添加即可，若不是需要在“USER_SOURCE”添加.c文件的路径
# user_include 添加.h文件所在路径
USER_INC = \
$(SYS_DIR)/usart 

# user_Source 添加.c文件
USER_SOURCE = \
$(wildcard $(SYS_SOURCE)/*/*.c)

######################################
#openocd路径配置 
OPENOCD_DOWN_PATH = /usr/share/openocd/scripts/interface/cmsis-dap.cfg
OPENOCD_CHIP_PATH = /usr/share/openocd/scripts/target/stm32f4x.cfg


######################################
# 启动文件选择
#startup_stm32f429xx.s
#startup_stm32f407xx.s

STARTUP = startup_stm32f429xx.s

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
./User/Src/main.c \
./User/Src/stm32f4xx_it.c \
$(USER_SOURCE) \
./FreeRtos/src/timers.c \
./FreeRtos/src/croutine.c \
./FreeRtos/src/list.c \
./FreeRtos/src/event_groups.c \
./FreeRtos/src/queue.c \
./FreeRtos/src/tasks.c \
./FreeRtos/port/MemMang/heap_4.c \
./FreeRtos/port/ARM_CM4F/port.c \
./Libraries/CMSIS/Device/ST/STM32F4xx/Include/Source/system_stm32f4xx.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pccard.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_fmpi2c_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_lptim.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_fmpi2c.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_mmc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fsmc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_iwdg.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cec.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nor.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_smartcard.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_wwdg.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nand.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_qspi.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_timebase_rtc_alarm_template.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rng.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dfsdm.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_irda.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_msp_template.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
./Libraries/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.c




# ASM sources
ASM_SOURCES =  \
./Libraries/CMSIS/Start/$(STARTUP)


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
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F429xx \
-DUSE_STM32F429I_DISCO


# AS includes
AS_INCLUDES =  

# C includes
C_INCLUDES =  \
-I./User/Inc \
-I./Libraries/CMSIS/Device/ST/STM32F4xx/Include \
-I./Libraries/CMSIS/Include \
-I./Libraries/STM32F4xx_HAL_Driver/Inc \
-I./Libraries/STM32F4xx_HAL_Driver/Inc/Legacy \
-I./FreeRtos/port/ARM_CM4F \
-I./FreeRtos/port/include \
$(USER_INC)





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
LDSCRIPT = ./Libraries/CMSIS/Link/STM32F429IGTx_FLASH.ld

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
# clean:
# 	del /s/q $(BUILD_DIR)
#linux
clean:
	rm -rf $(BUILD_DIR)

download:
	openocd -f $(OPENOCD_DOWN_PATH) -f $(OPENOCD_CHIP_PATH)  -c init -c halt -c "flash write_image erase ./build/$(TARGET).hex" -c reset -c halt -c shutdown

#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
