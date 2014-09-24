#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/347633335/charset.o \
	${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary.o \
	${OBJECTDIR}/_ext/347633335/crc32.o \
	${OBJECTDIR}/_ext/347633335/darray.o \
	${OBJECTDIR}/_ext/347633335/lock.o \
	${OBJECTDIR}/_ext/347633335/pool.o \
	${OBJECTDIR}/_ext/347633335/rule.o \
	${OBJECTDIR}/_ext/347633335/scws.o \
	${OBJECTDIR}/_ext/347633335/xdb.o \
	${OBJECTDIR}/_ext/347633335/xdict.o \
	${OBJECTDIR}/_ext/347633335/xtree.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libscws4j.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libscws4j.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libscws4j.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/_ext/347633335/charset.o: /home/intexh/NetBeansProjects/scws4j/charset.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/charset.o /home/intexh/NetBeansProjects/scws4j/charset.c

${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary.o: /home/intexh/NetBeansProjects/scws4j/com_intexh_segmentation_impl_scws_SCWSLibrary.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary.o /home/intexh/NetBeansProjects/scws4j/com_intexh_segmentation_impl_scws_SCWSLibrary.c

${OBJECTDIR}/_ext/347633335/crc32.o: /home/intexh/NetBeansProjects/scws4j/crc32.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/crc32.o /home/intexh/NetBeansProjects/scws4j/crc32.c

${OBJECTDIR}/_ext/347633335/darray.o: /home/intexh/NetBeansProjects/scws4j/darray.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/darray.o /home/intexh/NetBeansProjects/scws4j/darray.c

${OBJECTDIR}/_ext/347633335/lock.o: /home/intexh/NetBeansProjects/scws4j/lock.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/lock.o /home/intexh/NetBeansProjects/scws4j/lock.c

${OBJECTDIR}/_ext/347633335/pool.o: /home/intexh/NetBeansProjects/scws4j/pool.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/pool.o /home/intexh/NetBeansProjects/scws4j/pool.c

${OBJECTDIR}/_ext/347633335/rule.o: /home/intexh/NetBeansProjects/scws4j/rule.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/rule.o /home/intexh/NetBeansProjects/scws4j/rule.c

${OBJECTDIR}/_ext/347633335/scws.o: /home/intexh/NetBeansProjects/scws4j/scws.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/scws.o /home/intexh/NetBeansProjects/scws4j/scws.c

${OBJECTDIR}/_ext/347633335/xdb.o: /home/intexh/NetBeansProjects/scws4j/xdb.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/xdb.o /home/intexh/NetBeansProjects/scws4j/xdb.c

${OBJECTDIR}/_ext/347633335/xdict.o: /home/intexh/NetBeansProjects/scws4j/xdict.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/xdict.o /home/intexh/NetBeansProjects/scws4j/xdict.c

${OBJECTDIR}/_ext/347633335/xtree.o: /home/intexh/NetBeansProjects/scws4j/xtree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/xtree.o /home/intexh/NetBeansProjects/scws4j/xtree.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/1138114085/scws4jTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lcunit 


${TESTDIR}/_ext/1138114085/scws4jTest.o: /home/intexh/NetBeansProjects/scws4j/tests/scws4jTest.c 
	${MKDIR} -p ${TESTDIR}/_ext/1138114085
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1138114085/scws4jTest.o /home/intexh/NetBeansProjects/scws4j/tests/scws4jTest.c


${OBJECTDIR}/_ext/347633335/charset_nomain.o: ${OBJECTDIR}/_ext/347633335/charset.o /home/intexh/NetBeansProjects/scws4j/charset.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/charset.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/charset_nomain.o /home/intexh/NetBeansProjects/scws4j/charset.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/charset.o ${OBJECTDIR}/_ext/347633335/charset_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary_nomain.o: ${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary.o /home/intexh/NetBeansProjects/scws4j/com_intexh_segmentation_impl_scws_SCWSLibrary.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary_nomain.o /home/intexh/NetBeansProjects/scws4j/com_intexh_segmentation_impl_scws_SCWSLibrary.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary.o ${OBJECTDIR}/_ext/347633335/com_intexh_segmentation_impl_scws_SCWSLibrary_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/crc32_nomain.o: ${OBJECTDIR}/_ext/347633335/crc32.o /home/intexh/NetBeansProjects/scws4j/crc32.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/crc32.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/crc32_nomain.o /home/intexh/NetBeansProjects/scws4j/crc32.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/crc32.o ${OBJECTDIR}/_ext/347633335/crc32_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/darray_nomain.o: ${OBJECTDIR}/_ext/347633335/darray.o /home/intexh/NetBeansProjects/scws4j/darray.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/darray.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/darray_nomain.o /home/intexh/NetBeansProjects/scws4j/darray.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/darray.o ${OBJECTDIR}/_ext/347633335/darray_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/lock_nomain.o: ${OBJECTDIR}/_ext/347633335/lock.o /home/intexh/NetBeansProjects/scws4j/lock.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/lock.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/lock_nomain.o /home/intexh/NetBeansProjects/scws4j/lock.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/lock.o ${OBJECTDIR}/_ext/347633335/lock_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/pool_nomain.o: ${OBJECTDIR}/_ext/347633335/pool.o /home/intexh/NetBeansProjects/scws4j/pool.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/pool.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/pool_nomain.o /home/intexh/NetBeansProjects/scws4j/pool.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/pool.o ${OBJECTDIR}/_ext/347633335/pool_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/rule_nomain.o: ${OBJECTDIR}/_ext/347633335/rule.o /home/intexh/NetBeansProjects/scws4j/rule.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/rule.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/rule_nomain.o /home/intexh/NetBeansProjects/scws4j/rule.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/rule.o ${OBJECTDIR}/_ext/347633335/rule_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/scws_nomain.o: ${OBJECTDIR}/_ext/347633335/scws.o /home/intexh/NetBeansProjects/scws4j/scws.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/scws.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/scws_nomain.o /home/intexh/NetBeansProjects/scws4j/scws.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/scws.o ${OBJECTDIR}/_ext/347633335/scws_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/xdb_nomain.o: ${OBJECTDIR}/_ext/347633335/xdb.o /home/intexh/NetBeansProjects/scws4j/xdb.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/xdb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/xdb_nomain.o /home/intexh/NetBeansProjects/scws4j/xdb.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/xdb.o ${OBJECTDIR}/_ext/347633335/xdb_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/xdict_nomain.o: ${OBJECTDIR}/_ext/347633335/xdict.o /home/intexh/NetBeansProjects/scws4j/xdict.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/xdict.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/xdict_nomain.o /home/intexh/NetBeansProjects/scws4j/xdict.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/xdict.o ${OBJECTDIR}/_ext/347633335/xdict_nomain.o;\
	fi

${OBJECTDIR}/_ext/347633335/xtree_nomain.o: ${OBJECTDIR}/_ext/347633335/xtree.o /home/intexh/NetBeansProjects/scws4j/xtree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/347633335
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/347633335/xtree.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -I/usr/lib/jdk1.7.0_65/include -I/usr/lib/jdk1.7.0_65/include/linux -I/home/intexh/CUnitHome/include/CUnit -I/home/intexh/CUnitHome/include -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/347633335/xtree_nomain.o /home/intexh/NetBeansProjects/scws4j/xtree.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/347633335/xtree.o ${OBJECTDIR}/_ext/347633335/xtree_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libscws4j.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
