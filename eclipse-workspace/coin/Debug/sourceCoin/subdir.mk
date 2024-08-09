################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sourceCoin/Coin.c \
../sourceCoin/main.c 

C_DEPS += \
./sourceCoin/Coin.d \
./sourceCoin/main.d 

OBJS += \
./sourceCoin/Coin.o \
./sourceCoin/main.o 


# Each subdirectory must supply rules for building sources it contributes
sourceCoin/%.o: ../sourceCoin/%.c sourceCoin/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-sourceCoin

clean-sourceCoin:
	-$(RM) ./sourceCoin/Coin.d ./sourceCoin/Coin.o ./sourceCoin/main.d ./sourceCoin/main.o

.PHONY: clean-sourceCoin

