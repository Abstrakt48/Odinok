#.DEFAULT_GOAL := build_engine

all: build_game run_game

CC = g++
CFLAGS = -ggdb -O3
LIBS = -lm -lGL -lGLU -lglfw

SRC_DIRS=\
mortem/ce2022/engine/*.cpp \
mortem/src_main/game/*.cpp \
mortem/src_main/launcher/*.cpp \
mortem/src_main/launcher/linux/*.cpp \

INCLUDE_DIRS=-I mortem/src_main -I mortem/ce2022

BUILD_FILE = build/Mortem

build_game:
	${CC} ${CFLAGS} ${SRC_DIRS} ${INCLUDE_DIRS} -o ${BUILD_FILE} ${LIBS}

run_game:
	./${BUILD_FILE}