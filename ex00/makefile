HDRS = \
	vector_tester.hpp \
	matrix_tester.hpp \

SRCS = \
	main.cpp \

LIBS = \
	../logutil/logutil.a \
	../ft_matrix.a \

OBJS = ${SRCS:.cpp=.o}

NAME = ex00.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${NAME}: ${LIBS} ${HDRS} ${OBJS}
	${CXX} main.o ${LIBS} -o ${NAME} ${CPPFLAGS}

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
