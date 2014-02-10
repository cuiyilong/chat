TGTOUT = chatserver
export SRCDIR = ${BASE}/server
export BLDDIR = ${BUILD}/server


.PHONY: all clean ${SUBDIR} 
all: prepare ${BLDDIR}
	${MAKE} -C ${SRCDIR} all 

${BLDDIR}: 
	@[ -d ${BLDDIR} ] || mkdir -p ${BLDDIR}

clean: 
	${MAKE} -C ${SRCDIR} $@
install:
	${MAKE} -C ${SRCDIR} $@

.PHONY: prepare
prepare:
	@echo "prepare start"
		

