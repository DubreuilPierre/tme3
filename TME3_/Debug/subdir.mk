################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Banque.cpp \
../Compte.cpp \
../Comptelock.cpp \
../main1.cpp 

OBJS += \
./Banque.o \
./Compte.o \
./Comptelock.o \
./main1.o 

CPP_DEPS += \
./Banque.d \
./Compte.d \
./Comptelock.d \
./main1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


