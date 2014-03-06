.NOTPARALLEL:

BLDDIR=${BUILD}/thirdpart/sqlite-autoconf-3080300
SRCDIR=${BASE}/thirdpart/sqlite-autoconf-3080300
TGTOUT=sqllite
MYASFLAGS=
MYCFLAGS =
MYLDFLAGS=
MYLIBS   =

.PHONY: all clean distclean
all: ${BLDDIR}/Makefile
	${MAKE} -C ${BLDDIR}
	${MAKE} DESTDIR=${BASE} -C ${BLDDIR} install
clean:
	if [ -e ${BLDDIR}/Makefile ]; then ${MAKE} -C ${BLDDIR} clean; fi

distclean:
	if [ -e ${BLDDIR}/Makefile ]; then ${MAKE} -C ${BLDDIR} distclean; fi
	-rm -rf ${BLDDIR}

${BLDDIR}/Makefile:
	mkdir -p ${BLDDIR}
	cd ${BLDDIR} && export LD_LIBRARY_PATH=${BASE}${PREFIX}/lib && \
		${SRCDIR}/configure --quiet --prefix=${BASE}/app

