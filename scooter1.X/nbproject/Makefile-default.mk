#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/ECU/button.c INC/MCAL/GPIO.c MAin_scooter.c INC/device_config.c src/ECU/motor.c src/ECU/HAL_LED.c src/ECU/seven_seg.c src/MCAL/CCP.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/ECU/button.p1 ${OBJECTDIR}/INC/MCAL/GPIO.p1 ${OBJECTDIR}/MAin_scooter.p1 ${OBJECTDIR}/INC/device_config.p1 ${OBJECTDIR}/src/ECU/motor.p1 ${OBJECTDIR}/src/ECU/HAL_LED.p1 ${OBJECTDIR}/src/ECU/seven_seg.p1 ${OBJECTDIR}/src/MCAL/CCP.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/src/ECU/button.p1.d ${OBJECTDIR}/INC/MCAL/GPIO.p1.d ${OBJECTDIR}/MAin_scooter.p1.d ${OBJECTDIR}/INC/device_config.p1.d ${OBJECTDIR}/src/ECU/motor.p1.d ${OBJECTDIR}/src/ECU/HAL_LED.p1.d ${OBJECTDIR}/src/ECU/seven_seg.p1.d ${OBJECTDIR}/src/MCAL/CCP.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/ECU/button.p1 ${OBJECTDIR}/INC/MCAL/GPIO.p1 ${OBJECTDIR}/MAin_scooter.p1 ${OBJECTDIR}/INC/device_config.p1 ${OBJECTDIR}/src/ECU/motor.p1 ${OBJECTDIR}/src/ECU/HAL_LED.p1 ${OBJECTDIR}/src/ECU/seven_seg.p1 ${OBJECTDIR}/src/MCAL/CCP.p1

# Source Files
SOURCEFILES=src/ECU/button.c INC/MCAL/GPIO.c MAin_scooter.c INC/device_config.c src/ECU/motor.c src/ECU/HAL_LED.c src/ECU/seven_seg.c src/MCAL/CCP.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/ECU/button.p1: src/ECU/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/button.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/button.p1 src/ECU/button.c 
	@-${MV} ${OBJECTDIR}/src/ECU/button.d ${OBJECTDIR}/src/ECU/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/INC/MCAL/GPIO.p1: INC/MCAL/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/INC/MCAL" 
	@${RM} ${OBJECTDIR}/INC/MCAL/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/INC/MCAL/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/INC/MCAL/GPIO.p1 INC/MCAL/GPIO.c 
	@-${MV} ${OBJECTDIR}/INC/MCAL/GPIO.d ${OBJECTDIR}/INC/MCAL/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/INC/MCAL/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MAin_scooter.p1: MAin_scooter.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MAin_scooter.p1.d 
	@${RM} ${OBJECTDIR}/MAin_scooter.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MAin_scooter.p1 MAin_scooter.c 
	@-${MV} ${OBJECTDIR}/MAin_scooter.d ${OBJECTDIR}/MAin_scooter.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MAin_scooter.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/INC/device_config.p1: INC/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/INC" 
	@${RM} ${OBJECTDIR}/INC/device_config.p1.d 
	@${RM} ${OBJECTDIR}/INC/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/INC/device_config.p1 INC/device_config.c 
	@-${MV} ${OBJECTDIR}/INC/device_config.d ${OBJECTDIR}/INC/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/INC/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/ECU/motor.p1: src/ECU/motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/motor.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/motor.p1 src/ECU/motor.c 
	@-${MV} ${OBJECTDIR}/src/ECU/motor.d ${OBJECTDIR}/src/ECU/motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/ECU/HAL_LED.p1: src/ECU/HAL_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/HAL_LED.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/HAL_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/HAL_LED.p1 src/ECU/HAL_LED.c 
	@-${MV} ${OBJECTDIR}/src/ECU/HAL_LED.d ${OBJECTDIR}/src/ECU/HAL_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/HAL_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/ECU/seven_seg.p1: src/ECU/seven_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/seven_seg.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/seven_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/seven_seg.p1 src/ECU/seven_seg.c 
	@-${MV} ${OBJECTDIR}/src/ECU/seven_seg.d ${OBJECTDIR}/src/ECU/seven_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/seven_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/MCAL/CCP.p1: src/MCAL/CCP.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/MCAL" 
	@${RM} ${OBJECTDIR}/src/MCAL/CCP.p1.d 
	@${RM} ${OBJECTDIR}/src/MCAL/CCP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/MCAL/CCP.p1 src/MCAL/CCP.c 
	@-${MV} ${OBJECTDIR}/src/MCAL/CCP.d ${OBJECTDIR}/src/MCAL/CCP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/MCAL/CCP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/src/ECU/button.p1: src/ECU/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/button.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/button.p1 src/ECU/button.c 
	@-${MV} ${OBJECTDIR}/src/ECU/button.d ${OBJECTDIR}/src/ECU/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/INC/MCAL/GPIO.p1: INC/MCAL/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/INC/MCAL" 
	@${RM} ${OBJECTDIR}/INC/MCAL/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/INC/MCAL/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/INC/MCAL/GPIO.p1 INC/MCAL/GPIO.c 
	@-${MV} ${OBJECTDIR}/INC/MCAL/GPIO.d ${OBJECTDIR}/INC/MCAL/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/INC/MCAL/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MAin_scooter.p1: MAin_scooter.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MAin_scooter.p1.d 
	@${RM} ${OBJECTDIR}/MAin_scooter.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MAin_scooter.p1 MAin_scooter.c 
	@-${MV} ${OBJECTDIR}/MAin_scooter.d ${OBJECTDIR}/MAin_scooter.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MAin_scooter.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/INC/device_config.p1: INC/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/INC" 
	@${RM} ${OBJECTDIR}/INC/device_config.p1.d 
	@${RM} ${OBJECTDIR}/INC/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/INC/device_config.p1 INC/device_config.c 
	@-${MV} ${OBJECTDIR}/INC/device_config.d ${OBJECTDIR}/INC/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/INC/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/ECU/motor.p1: src/ECU/motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/motor.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/motor.p1 src/ECU/motor.c 
	@-${MV} ${OBJECTDIR}/src/ECU/motor.d ${OBJECTDIR}/src/ECU/motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/ECU/HAL_LED.p1: src/ECU/HAL_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/HAL_LED.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/HAL_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/HAL_LED.p1 src/ECU/HAL_LED.c 
	@-${MV} ${OBJECTDIR}/src/ECU/HAL_LED.d ${OBJECTDIR}/src/ECU/HAL_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/HAL_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/ECU/seven_seg.p1: src/ECU/seven_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/ECU" 
	@${RM} ${OBJECTDIR}/src/ECU/seven_seg.p1.d 
	@${RM} ${OBJECTDIR}/src/ECU/seven_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/ECU/seven_seg.p1 src/ECU/seven_seg.c 
	@-${MV} ${OBJECTDIR}/src/ECU/seven_seg.d ${OBJECTDIR}/src/ECU/seven_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/ECU/seven_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/MCAL/CCP.p1: src/MCAL/CCP.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/MCAL" 
	@${RM} ${OBJECTDIR}/src/MCAL/CCP.p1.d 
	@${RM} ${OBJECTDIR}/src/MCAL/CCP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/MCAL/CCP.p1 src/MCAL/CCP.c 
	@-${MV} ${OBJECTDIR}/src/MCAL/CCP.d ${OBJECTDIR}/src/MCAL/CCP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/MCAL/CCP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/scooter1.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/scooter1.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/scooter1.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/scooter1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
