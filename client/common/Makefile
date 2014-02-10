SRCDIR = ${shell pwd}
SRC = ${wildcard ${SRCDIR}/*.c}
OBJS = ${patsubst ${SRCDIR}/%.c,${SRCDIR}/%.o, ${wildcard ${SRCDIR}/*.c}}

.PHONY: all clean  
all : prepare ${OBJS}

${OBJS}:  
	${CC} -c -o $@ ${SRC} ${MYCFLAGS}

.PHONY: prepare
prepare:
	@echo "prepare start"
	@echo "14${MYCFLAGS}"
		

