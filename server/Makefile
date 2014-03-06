TGTOUT = ${BLDDIR}/chatserver

SUBDIRNAME=${shell find ${SRCDIR}/ -type d  |grep -v include}
SUBDIR=${patsubst ${SRCDIR}/%,%,${SUBDIRNAME}}
MYCFLAGS+=-I${SRCDIR}/include 

.PHONY: all clean ${SUBDIR} 
all: prepared ${SUBDIR}
	${CC} -o ${TGTOUT} `find ${BLDDIR} -name '*.o'` ${MYCFLAGS} ${MYLIBS} 

${SUBDIR}:
	${MAKE} -C ${SRCDIR}/$@ all TARGET=$@
install:
	cp ${TGTOUT} ${APP}/bin
clean: 
	-rm `find ${BLDDIR} -name '*.o'`
	-rm ${TGTOUT}
	-rm ${APP}/bin/chatserver
distclean:

prepared:
	@echo "${SUBDIR}"
