################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/communicator/Communicator.cpp 

OBJS += \
./src/communicator/Communicator.o 

CPP_DEPS += \
./src/communicator/Communicator.d 


# Each subdirectory must supply rules for building sources it contributes
src/communicator/%.o: ../src/communicator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


