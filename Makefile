##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [2.29.2] date: [Thu Dec 06 23:31:18 CET 2018]
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = L073


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
Src/main.c \
Src/stm32l0xx_it.c \
Src/stm32l0xx_hal_msp.c \
Drivers/PERIPHERALS_STM32L073/src/HW_GPIO.c \
Drivers/PERIPHERALS_STM32L073/src/HW_SPI.c \
Drivers/PERIPHERALS_STM32L073/src/HW_RTC.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim_ex.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c_ex.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ramfunc.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ex.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rtc.c \
Src/system_stm32l0xx.c  \
Drivers/PERIPHERALS_STM32L073/src/HW_RCC.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_ll_utils.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_ll_gpio.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_ll_spi.c \
Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_ll_exti.c \

# ASM sources
ASM_SOURCES =  \
startup_stm32l073xx.s


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
CPU = -mcpu=cortex-m0plus

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_FULL_LL_DRIVER \
-DUSE_HAL_DRIVER \
-DSTM32L073xx


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-IDrivers/STM32L0xx_HAL_Driver/Inc \
-IInc \
-IDrivers/PERIPHERALS_STM32L073/inc \
-IDrivers/STM32L0xx_HAL_Driver/Inc/Legacy \
-IDrivers/CMSIS/Device/ST/STM32L0xx/Include \
-IDrivers/CMSIS/Include \

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
LDSCRIPT = STM32L073RZTx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

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
clean:
	-rm -fR $(BUILD_DIR)

  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***