################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/nAlbero.cpp \
../src/nodoNalbero.cpp \
../src/serviziNalbero.cpp 

OBJS += \
./src/main.o \
./src/nAlbero.o \
./src/nodoNalbero.o \
./src/serviziNalbero.o 

CPP_DEPS += \
./src/main.d \
./src/nAlbero.d \
./src/nodoNalbero.d \
./src/serviziNalbero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


