HDRS = \
	Matrix.hpp \
	Vector.hpp \

SRCS = \

LIBS = \

OBJS = ${SRCS:.cpp=.o}

TEST = \
	ex00/ex00.out \

NAME = ft_matrix.a
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${NAME}: ${LIBS} ${HDRS} ${OBJS}
	ar rcs ${NAME} ${OBJS}

${OBJS} main.o: ${LIBS} ${HDRS}

%.a: lib
	make $(@F) -C $(@D)

${TEST}: lib
	make $(@F) -C $(@D)

headers_test: ${HDRS:.hpp=.hpp.o}
%.hpp.o: ${HDRS}
	${CXX} ${CPPFLAGS} ${@:.o=} -c -o $@
%.hpp:

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.out

re: clean all

.PHONY: all clean re lib headers_test
