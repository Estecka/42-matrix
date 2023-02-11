HDRS = \
	Matrix.hpp \
	Vector.hpp \

SRCS = \

LIBS = \
	logutil/logutil.a \

OBJS = ${SRCS:.cpp=.o}

NAME = ft_matrix.a
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${NAME}: ${LIBS} ${HDRS} ${OBJS}
	ar rcs ${NAME} ${OBJS}

${TEST}: ${NAME} main.o
	${CXX} main.o ${NAME} ${LIBS} -o ${TEST} ${CPPFLAGS}

${OBJS} main.o: ${LIBS} ${HDRS}

%.a: lib
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
