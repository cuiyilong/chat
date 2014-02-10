
export BASE=${shell pwd}
export BUILD=${BASE}/build
export APP=${BASE}/app
export CC=gcc 
MAKE=make
MYCFLAGS=-Wall -g
MYCFLAGS+=-I${BASE}/include
export MYCFLAGS
ALL_MODULES=server 

.PHONY: all clean install rebuild 
default:all
all :  ${ALL_MODULES} 
	@echo "start compiling $^ "
	@[ -d ${BUILD} ] || mkdir -p {BUILD}
	${MAKE} -C ${BUILD} -f ${BASE}/rules/$^.mk  $@ 

install:${ALL_MODULES}

	${MAKE} -C ${BUILD} -f ${BASE}/rules/$^.mk  $@

clean: ${ALL_MODULES}
	@echo "start clean  $^ "
	${MAKE} -C ${BUILD} -f ${BASE}/rules/$^.mk  $@

	





