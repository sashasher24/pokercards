NAME = race03

INC = ./inc/header.h
INCOBJ = header.h

SRC = ./src/main.c ./src/mx_printerr.c ./src/mx_printstr.c ./src/mx_strlen.c ./src/mx_strcmp.c
SRCOBJ = main.c mx_printerr.c mx_strlen.c mx_printstr.c mx_strcmp.c

CFLAGS = -std=c11 -Wall -Werror -Wextra -Wpedantic

all: install clean
install:
	@cp ${INC} .
	@cp ${SRC} .
	@clang ${CFLAGS} -o ${NAME} ${SRCOBJ} -I ${INCOBJ}
uninstall: clean
	@rm -rf ${NAME}
clean:
	@rm -rf ${INCOBJ}
	@rm -rf ${SRCOBJ}
reinstall: uninstall clean all
