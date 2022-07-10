FILE = src/Infix_Postfix_Stack.c
PROG = build/Infix_Postfix_Stack

CC = gcc
CFLAGS = -Wall -o

${PROG}: ${FILE}
	${CC} ${CFLAGS} ${PROG} ${FILE}

run: ${PROG}
	./${PROG}

clean: ${PROG}
	rm ${PROG}