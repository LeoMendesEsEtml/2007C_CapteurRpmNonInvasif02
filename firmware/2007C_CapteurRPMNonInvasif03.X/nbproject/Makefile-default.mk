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
FINAL_IMAGE=${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/app.c ../src/main.c ../src/LCD.c ../src/Mc32Delays.c ../src/GestBtn.c ../src/PotControl.c ../src/Mc32Spi.c ../src/menu.c ../src/ProfilStorage.c ../../../../framework/system/int/src/sys_int_pic32.c ../src/system_config/default/framework/driver/i2c/src/drv_i2c_static.c ../src/system_config/default/framework/driver/i2c/src/drv_i2c_mapping.c ../src/system_config/default/framework/driver/ic/src/drv_ic_mapping.c ../src/system_config/default/framework/driver/ic/src/drv_ic_static.c ../src/system_config/default/framework/driver/nvm/src/drv_nvm_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/LIS2HH12.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/LCD.o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ${OBJECTDIR}/_ext/1360937237/GestBtn.o ${OBJECTDIR}/_ext/1360937237/PotControl.o ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o ${OBJECTDIR}/_ext/1360937237/menu.o ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o ${OBJECTDIR}/_ext/875444448/drv_ic_static.o ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/LCD.o.d ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d ${OBJECTDIR}/_ext/1360937237/GestBtn.o.d ${OBJECTDIR}/_ext/1360937237/PotControl.o.d ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o.d ${OBJECTDIR}/_ext/1360937237/menu.o.d ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o.d ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o.d ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o.d ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o.d ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o.d ${OBJECTDIR}/_ext/875444448/drv_ic_static.o.d ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/LCD.o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ${OBJECTDIR}/_ext/1360937237/GestBtn.o ${OBJECTDIR}/_ext/1360937237/PotControl.o ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o ${OBJECTDIR}/_ext/1360937237/menu.o ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o ${OBJECTDIR}/_ext/875444448/drv_ic_static.o ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o

# Source Files
SOURCEFILES=../src/app.c ../src/main.c ../src/LCD.c ../src/Mc32Delays.c ../src/GestBtn.c ../src/PotControl.c ../src/Mc32Spi.c ../src/menu.c ../src/ProfilStorage.c ../../../../framework/system/int/src/sys_int_pic32.c ../src/system_config/default/framework/driver/i2c/src/drv_i2c_static.c ../src/system_config/default/framework/driver/i2c/src/drv_i2c_mapping.c ../src/system_config/default/framework/driver/ic/src/drv_ic_mapping.c ../src/system_config/default/framework/driver/ic/src/drv_ic_static.c ../src/system_config/default/framework/driver/nvm/src/drv_nvm_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/LIS2HH12.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFH064
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/f24bfe70469f2c545636b8d8877859959a2e3a31 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/ccf0543a6bbbc8eef555d41a73e6a7b56e1fb928 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--gdwarf-2 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/b58ccb6549c6c8d0f92d6a46cbba29d7aabc16cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/74b5558a5a17f86697b457840fbba4aabcdc3b35 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  .generated_files/flags/default/a8086162f206813ae8baa27d172faa229316b49d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d" -o ${OBJECTDIR}/_ext/1360937237/LCD.o ../src/LCD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Delays.o: ../src/Mc32Delays.c  .generated_files/flags/default/1d75c043cc95f10eb31831e801e8aab7bac0fbf3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ../src/Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/GestBtn.o: ../src/GestBtn.c  .generated_files/flags/default/ccac7b1b7569758d98f0d2dd9d500c68581ddb20 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GestBtn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GestBtn.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GestBtn.o.d" -o ${OBJECTDIR}/_ext/1360937237/GestBtn.o ../src/GestBtn.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/PotControl.o: ../src/PotControl.c  .generated_files/flags/default/eb01e9283396906df5d3363404e10f4cb124a6d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PotControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PotControl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/PotControl.o.d" -o ${OBJECTDIR}/_ext/1360937237/PotControl.o ../src/PotControl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Spi.o: ../src/Mc32Spi.c  .generated_files/flags/default/934f7b98c0115cf18c9e01f7b41636e8a7edeb72 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Spi.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o ../src/Mc32Spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/menu.o: ../src/menu.c  .generated_files/flags/default/4c4fae09a41640720315e0c7362fdaa4e378b7f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/menu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/menu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/menu.o.d" -o ${OBJECTDIR}/_ext/1360937237/menu.o ../src/menu.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/ProfilStorage.o: ../src/ProfilStorage.c  .generated_files/flags/default/8237a223b912cae25e1b02c19f35f332a94266f8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ProfilStorage.o.d" -o ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o ../src/ProfilStorage.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/122796885/sys_int_pic32.o: ../../../../framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/ee33e3efbd7af5b9c51a8a0f108e60d0adf669c8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/122796885" 
	@${RM} ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/122796885/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o ../../../../framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/12144542/drv_i2c_static.o: ../src/system_config/default/framework/driver/i2c/src/drv_i2c_static.c  .generated_files/flags/default/97c7f1a8a88131fc673e8db861cf4be972139f53 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/12144542" 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/12144542/drv_i2c_static.o.d" -o ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o ../src/system_config/default/framework/driver/i2c/src/drv_i2c_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o: ../src/system_config/default/framework/driver/i2c/src/drv_i2c_mapping.c  .generated_files/flags/default/47f43d1ecccefe2d90c9ebe8f3de8ba4c359ed0c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/12144542" 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o.d" -o ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o ../src/system_config/default/framework/driver/i2c/src/drv_i2c_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o: ../src/system_config/default/framework/driver/ic/src/drv_ic_mapping.c  .generated_files/flags/default/f258d19ca43029032554473d77ac82801f2d5e0d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/875444448" 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o.d" -o ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o ../src/system_config/default/framework/driver/ic/src/drv_ic_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/875444448/drv_ic_static.o: ../src/system_config/default/framework/driver/ic/src/drv_ic_static.c  .generated_files/flags/default/feaa0c23ee26523653973f4da2ad7c3066c2517a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/875444448" 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/875444448/drv_ic_static.o.d" -o ${OBJECTDIR}/_ext/875444448/drv_ic_static.o ../src/system_config/default/framework/driver/ic/src/drv_ic_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o: ../src/system_config/default/framework/driver/nvm/src/drv_nvm_static.c  .generated_files/flags/default/9233ceb9cb8c272a67dc31c852a55de67d9b9a89 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2110713129" 
	@${RM} ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o.d" -o ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o ../src/system_config/default/framework/driver/nvm/src/drv_nvm_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  .generated_files/flags/default/93b1e54ae96e5bc14c6ad1ea3ed36d574e3c57e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  .generated_files/flags/default/6c351bb7e20e11752bc74856e2883e110bda5438 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/17e4105e9382a13f83ee533215a433a6db6983c0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/8dc82664321518db303725874df4fddc6751d083 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/1420a02a032e105adfb7b34fbfb01b09f0d5a794 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/f60c528a66b8fc0769c1e245d60ce5adbc51f5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/6deaf260c329d9155a07f062af0a73ac1e53ef27 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/31f197c79414459c6e105788546b55f2405a619f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/78d66123b487a0946daed0e33346a7ab9e9cbe41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/2b67df03dcf46af3661c01b4411f6d040118dd7d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/LIS2HH12.o: ../src/LIS2HH12.c  .generated_files/flags/default/5fe2e6b0a7fb8ede93e8c9a1e81b5c59375c2fce .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LIS2HH12.o.d" -o ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o ../src/LIS2HH12.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/8c5cddfddfb5fcdeee3ccdf7bbef23d8835a53a6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/d339449de81742c1b275d230d180a04ea58ff9a7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  .generated_files/flags/default/dc71190902ca36bb8283bedf611d4ecab74fe0ee .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d" -o ${OBJECTDIR}/_ext/1360937237/LCD.o ../src/LCD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Delays.o: ../src/Mc32Delays.c  .generated_files/flags/default/c1b22c084dfb7fbecf102b42aeee1ac8e4e46bce .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Delays.o ../src/Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/GestBtn.o: ../src/GestBtn.c  .generated_files/flags/default/a9df2c3a043c4eebea3dbfd212c9b9911baeab14 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GestBtn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GestBtn.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GestBtn.o.d" -o ${OBJECTDIR}/_ext/1360937237/GestBtn.o ../src/GestBtn.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/PotControl.o: ../src/PotControl.c  .generated_files/flags/default/e0aecc968591a1dcb01fbd4498f744c46fe496ff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PotControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PotControl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/PotControl.o.d" -o ${OBJECTDIR}/_ext/1360937237/PotControl.o ../src/PotControl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Spi.o: ../src/Mc32Spi.c  .generated_files/flags/default/18a0a2999100f9b5ef118a42ab19060b539ec0ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Spi.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Spi.o ../src/Mc32Spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/menu.o: ../src/menu.c  .generated_files/flags/default/1db785ac20df8c060e2ea956861681446c0ab9aa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/menu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/menu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/menu.o.d" -o ${OBJECTDIR}/_ext/1360937237/menu.o ../src/menu.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/ProfilStorage.o: ../src/ProfilStorage.c  .generated_files/flags/default/fffb4b965d5b9ab177f49bd4efb248b7aeec2af1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ProfilStorage.o.d" -o ${OBJECTDIR}/_ext/1360937237/ProfilStorage.o ../src/ProfilStorage.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/122796885/sys_int_pic32.o: ../../../../framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/14019ff19ba6e0455ad05625af76e6ba8ce10725 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/122796885" 
	@${RM} ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/122796885/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/122796885/sys_int_pic32.o ../../../../framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/12144542/drv_i2c_static.o: ../src/system_config/default/framework/driver/i2c/src/drv_i2c_static.c  .generated_files/flags/default/b7b445383824ca5686a6add29f465cb847f9a07b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/12144542" 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/12144542/drv_i2c_static.o.d" -o ${OBJECTDIR}/_ext/12144542/drv_i2c_static.o ../src/system_config/default/framework/driver/i2c/src/drv_i2c_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o: ../src/system_config/default/framework/driver/i2c/src/drv_i2c_mapping.c  .generated_files/flags/default/9ecc1a78ac139941b5e9154372f0c05c083ecc94 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/12144542" 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o.d" -o ${OBJECTDIR}/_ext/12144542/drv_i2c_mapping.o ../src/system_config/default/framework/driver/i2c/src/drv_i2c_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o: ../src/system_config/default/framework/driver/ic/src/drv_ic_mapping.c  .generated_files/flags/default/c6a084f69dfc2cc530cbe256736ef053924b5896 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/875444448" 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o.d" -o ${OBJECTDIR}/_ext/875444448/drv_ic_mapping.o ../src/system_config/default/framework/driver/ic/src/drv_ic_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/875444448/drv_ic_static.o: ../src/system_config/default/framework/driver/ic/src/drv_ic_static.c  .generated_files/flags/default/e48c8568826541cd3e2ddb28ca6131451b273858 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/875444448" 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/875444448/drv_ic_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/875444448/drv_ic_static.o.d" -o ${OBJECTDIR}/_ext/875444448/drv_ic_static.o ../src/system_config/default/framework/driver/ic/src/drv_ic_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o: ../src/system_config/default/framework/driver/nvm/src/drv_nvm_static.c  .generated_files/flags/default/cf5dfe966298dafb6460bc2c2b49dff050baaf47 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2110713129" 
	@${RM} ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o.d" -o ${OBJECTDIR}/_ext/2110713129/drv_nvm_static.o ../src/system_config/default/framework/driver/nvm/src/drv_nvm_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  .generated_files/flags/default/5e9099c203edca3c9c515a9984d0368a00fd8ee .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  .generated_files/flags/default/dbec67c8fbda060b6957069414415f3d17cdf28f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/8526e525ffe1c6530e9a384993752b050bc07a8c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/adbe704ffa2b3143ae770e676febac1227e97b0f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/39be20727fc1fb138e8dc4af0de644dc2aab89e9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/5b838071ca5c6247fa7170f1a830cad7c40e98f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/62cbac751699c605158c066f05ddaa33362b36fe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/6a1db1bc1c28337aa8725b9a8df1061ff18dadde .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/c05189331bde4fe1aefdb77869308dcae414b7c5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/b0916fdaee8540d2da3255978f63d611df4d503e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/LIS2HH12.o: ../src/LIS2HH12.c  .generated_files/flags/default/f5e7efcab31a450bcae7341ff57002230c3e5da .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../framework" -I"../src/system_config/default/framework" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LIS2HH12.o.d" -o ${OBJECTDIR}/_ext/1360937237/LIS2HH12.o ../src/LIS2HH12.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../bin/framework/peripheral/PIC32MZ2048EFH064_peripherals.a  
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD4=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\bin\framework\peripheral\PIC32MZ2048EFH064_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD4=1,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../bin/framework/peripheral/PIC32MZ2048EFH064_peripherals.a 
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\bin\framework\peripheral\PIC32MZ2048EFH064_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/2007C_CapteurRPMNonInvasif03.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
