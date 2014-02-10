TGTOUT = chatserver
export SRCDIR = ${BASE}/server
export BLDDIR = ${BUILD}/server


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
		

