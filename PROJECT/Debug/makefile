################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TWI/subdir.mk
-include MCAL/TMR2/subdir.mk
-include MCAL/TMR1/subdir.mk
-include MCAL/TMR0/subdir.mk
-include MCAL/GI/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/HTR/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/DCM/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
electric_heat_water.lss \

FLASH_IMAGE += \
electric_heat_water.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: electric_heat_water.elf secondary-outputs

# Tool invocations
electric_heat_water.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,electric_heat_water.map -mmcu=atmega32 -o "electric_heat_water.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

electric_heat_water.lss: electric_heat_water.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S electric_heat_water.elf  >"electric_heat_water.lss"
	@echo 'Finished building: $@'
	@echo ' '

electric_heat_water.hex: electric_heat_water.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex electric_heat_water.elf  "electric_heat_water.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: electric_heat_water.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 electric_heat_water.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) electric_heat_water.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
