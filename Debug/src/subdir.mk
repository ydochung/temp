################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AcceleratedCpp.cpp \
../src/Student_info.cpp \
../src/grade.cpp \
../src/median.cpp 

OBJS += \
./src/AcceleratedCpp.o \
./src/Student_info.o \
./src/grade.o \
./src/median.o 

CPP_DEPS += \
./src/AcceleratedCpp.d \
./src/Student_info.d \
./src/grade.d \
./src/median.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


