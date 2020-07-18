################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/1_Hardware&Drivers.cpp \
../src/2_Threads&Handlers.cpp \
../src/3_Application&FSM.cpp \
../src/main.cpp 

OBJS += \
./src/1_Hardware&Drivers.o \
./src/2_Threads&Handlers.o \
./src/3_Application&FSM.o \
./src/main.o 

CPP_DEPS += \
./src/1_Hardware&Drivers.d \
./src/2_Threads&Handlers.d \
./src/3_Application&FSM.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


