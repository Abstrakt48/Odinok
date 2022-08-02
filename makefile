#.DEFAULT_GOAL := build_engine

all: build_game run_game

CC = g++
CFLAGS = -ggdb -O3
LIBS = -lm -lGL -lGLU -lglfw

SRC_DIRS=\
Order-1994/src_main/engine/*.cpp \
Order-1994/src_main/game/*.cpp \
Order-1994/src_main/launcher/*.cpp \
Order-1994/src_main/launcher/linux/*.cpp \
Order-1994/src_main/renderer/*.cpp \
Order-1994/src_main/tools/*.cpp \

INCLUDE_DIRS=-I Order-1994/src_main

BUILD_FILE = build/Order-1994

build_game:
	${CC} ${CFLAGS} ${SRC_DIRS} ${INCLUDE_DIRS} -o ${BUILD_FILE} ${LIBS}

run_game:
	./${BUILD_FILE}