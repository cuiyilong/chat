
MYSRCDIR = ${SRCDIR}/${TARGET}
SRC = ${wildcard ${MYSRCDIR}/*.c}
OBJS = ${patsubst ${MYSRCDIR}/%.c,${BLDDIR}/${TARGET}/%.o, ${wildcard ${MYSRCDIR}/*.c}}

.PHONY: all clean  
all : prepare ${OBJS}

${OBJS}:  
	${CC} -c ${SRC} -o $@ ${MYCFLAGS}

.PHONY: prepare
prepare:
	@echo "prepare main ${TARGET}" 
	@echo "15  ${OBJS}"
		

