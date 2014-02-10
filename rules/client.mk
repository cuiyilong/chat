TGTOUT = chatclient
export SRCDIR = ${BASE}/client
export BLDDIR = ${BUILD}/client


.PHONY: all clean ${SUBDIR} 
all: prepare ${BLDDIR}
	${MAKE} -C ${SRCDIR} $@ 

${BLDDIR}: 
	@[ -d ${BLDDIR} ] || mkdir -p ${BLDDIR}

clean: 
	${MAKE} -C ${SRCDIR} $@
install:
	${MAKE} -C ${SRCDIR} $@

.PHONY: prepare
prepare:
	@echo "prepare start"
		

