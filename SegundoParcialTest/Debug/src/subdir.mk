################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/SegundoParcialTest.c \
../src/entidad.c \
../src/parser.c \
../src/utn_lib.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/SegundoParcialTest.o \
./src/entidad.o \
./src/parser.o \
./src/utn_lib.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/SegundoParcialTest.d \
./src/entidad.d \
./src/parser.d \
./src/utn_lib.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


