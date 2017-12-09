################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/arcoGrafo.cpp \
../src/cellaGrafo.cpp \
../src/grafo.cpp \
../src/main.cpp \
../src/serviziGrafo.cpp 

OBJS += \
./src/arcoGrafo.o \
./src/cellaGrafo.o \
./src/grafo.o \
./src/main.o \
./src/serviziGrafo.o 

CPP_DEPS += \
./src/arcoGrafo.d \
./src/cellaGrafo.d \
./src/grafo.d \
./src/main.d \
./src/serviziGrafo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


