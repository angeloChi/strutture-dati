################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/nodoCodaPriorita.cpp \
../src/prioriCoda.cpp \
../src/serviziCodaPri.cpp 

OBJS += \
./src/main.o \
./src/nodoCodaPriorita.o \
./src/prioriCoda.o \
./src/serviziCodaPri.o 

CPP_DEPS += \
./src/main.d \
./src/nodoCodaPriorita.d \
./src/prioriCoda.d \
./src/serviziCodaPri.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


