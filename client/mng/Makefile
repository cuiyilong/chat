
TGTDIR = ${BLDDIR}/${TARGET} 

MYSRCDIR = ${SRCDIR}/${TARGET}
SRC = ${wildcard ${MYSRCDIR}/*.c}
OBJS = ${patsubst ${MYSRCDIR}/%.c,${BLDDIR}/${TARGET}/%.o, ${wildcard ${MYSRCDIR}/*.c}}
.PHONY: all clean  
all : prepared ${OBJS}

${OBJS}: ${SRC}
	${CC} -c ${SRC} -o $@ ${MYCFLAGS}

prepared:
	@[ -d ${BLDDIR}/${TARGET} ] || mkdir -p ${BLDDIR}/${TARGET}
clean:
	-rm ${TGTDIR}/*.o 

		

