################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Pinmask.cpp \
../src/Threads.cpp \
../src/finiteStateMachine.cpp \
../src/main.cpp 

OBJS += \
./src/Pinmask.o \
./src/Threads.o \
./src/finiteStateMachine.o \
./src/main.o 

CPP_DEPS += \
./src/Pinmask.d \
./src/Threads.d \
./src/finiteStateMachine.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


