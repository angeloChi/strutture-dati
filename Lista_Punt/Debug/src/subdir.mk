################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lista.cpp \
../src/Nodo.cpp \
../src/main.cpp \
../src/serviziLista.cpp 

OBJS += \
./src/Lista.o \
./src/Nodo.o \
./src/main.o \
./src/serviziLista.o 

CPP_DEPS += \
./src/Lista.d \
./src/Nodo.d \
./src/main.d \
./src/serviziLista.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


