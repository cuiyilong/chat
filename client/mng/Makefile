TARGETS = chatserver
SRCDIR = ${shell pwd}
SUBDIR=${shell find . -type d |grep './' |grep -v include}
#OBJS=$(foreach subdir, ${DIR},${patsubst %.c,${SRCDIR}/${subdir}/%.o, ${wildcard ${SRCDIR}/${subdir}/*.c}})
MYCFLAGS+=-I${SRCDIR}/include 

.PHONY: all clean ${SUBDIR} 
all : prepare ${TARGETS}
	@echo "11$@"

${TARGETS}: ${SUBDIR} 
${SUBDIR}: 
	@echo "16 $@"
	${MAKE} -C $@

.PHONY: prepare
prepare:
	@echo "prepare start"
	@echo "${SUBDIR} ${MYCFLAGS}"
		

