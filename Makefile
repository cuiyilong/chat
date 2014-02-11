
export BASE=${shell pwd}
export BUILD=${BASE}/build
export APP=${BASE}/app
export CC=gcc 
MAKE=make
MYCFLAGS=-Wall -g
MYCFLAGS+=-I${BASE}/include
MYCFLAGS+=-lpthread
export MYCFLAGS
ALL_MODULES_MK=${shell find ${BASE}/rules/ -name "*.mk" -printf "%f "}
ALL_MODULES=${ALL_MODULES_MK:.mk=}
ifeq (${M},)
	M:=${ALL_MODULES}
endif

.PHONY: all clean install rebuild 
default:all
all: ${M}  
.PHONY:${ALL_MODULES} 
${ALL_MODULES}:
	@echo "start compiling ${ALL_MODULES} "
	@[ -d ${BUILD} ] || mkdir -p {BUILD}
	${MAKE} -C ${BUILD} -f ${BASE}/rules/$@.mk  all

install:
	$(foreach mod,${M},${MAKE} -C ${BUILD} -f ${BASE}/rules/${mod}.mk install;)
clean: 
	@echo "start clean  "
	$(foreach mod,${M},${MAKE} -C ${BUILD} -f ${BASE}/rules/${mod}.mk clean;)

rebuild:
	$(foreach mod,${M},${MAKE} -C ${BUILD} -f ${BASE}/rules/${mod}.mk clean;)
	$(foreach mod,${M},${MAKE} -C ${BUILD} -f ${BASE}/rules/${mod}.mk all;)
	


