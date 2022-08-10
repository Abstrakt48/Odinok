#.DEFAULT_GOAL := build_engine

all: build_game run_game

CC = g++
CFLAGS = -ggdb -O3
LIBS = -lm -lGL -lGLU -lglfw

SRC_DIRS=\
Odinok/src_main/system/*.cpp \
Odinok/src_main/mathlib/*.cpp \
Odinok/src_main/game/*.cpp \
Odinok/src_main/renderer/*.cpp \
Odinok/src_main/tools/*.cpp \
Odinok/src_main/odinok_src/*.cpp \

INCLUDE_DIRS=-I Odinok/src_main

BUILD_FILE = build/Odinok

build_game:
	${CC} ${CFLAGS} ${SRC_DIRS} ${INCLUDE_DIRS} -o ${BUILD_FILE} ${LIBS}

run_game:
	./${BUILD_FILE}