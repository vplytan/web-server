################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/handlers/BinaryHandler.cpp \
../src/handlers/DirectoryHandler.cpp \
../src/handlers/ErrorHandler.cpp \
../src/handlers/Handler.cpp \
../src/handlers/IndexHandler.cpp \
../src/handlers/TextHandler.cpp 

OBJS += \
./src/handlers/BinaryHandler.o \
./src/handlers/DirectoryHandler.o \
./src/handlers/ErrorHandler.o \
./src/handlers/Handler.o \
./src/handlers/IndexHandler.o \
./src/handlers/TextHandler.o 

CPP_DEPS += \
./src/handlers/BinaryHandler.d \
./src/handlers/DirectoryHandler.d \
./src/handlers/ErrorHandler.d \
./src/handlers/Handler.d \
./src/handlers/IndexHandler.d \
./src/handlers/TextHandler.d 


# Each subdirectory must supply rules for building sources it contributes
src/handlers/%.o: ../src/handlers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


