HDRS = \
	Format.hpp \
	Imaginary.hpp \
	Matrix.hpp \
	Vector.hpp \
	abs.hpp \
	atok.hpp \
	conjugate.hpp \
	lerp.hpp \

SRCS = \
	Format.cpp \

TEST_HDRS = \
	TestFactory.hpp \
	matrix_tester.hpp \
	nmp_tester.hpp \
	number_tester.hpp \
	vector_tester.hpp \

TEST_SRCS = \
	main.cpp \

LIBS = \
	logutil/logutil.a \

OBJS      = ${SRCS:.cpp=.o}
TEST_OBJS = ${TEST_SRCS:.cpp=.o}

NAME = ft_matrix.a
TEST = ft_matrix.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}


${NAME}: ${LIBS} ${HDRS} ${OBJS}
	ar rcs ${NAME} ${OBJS}

${TEST}: ${NAME} ${TEST_OBJS}
	${CXX} ${TEST_OBJS} ${NAME} ${LIBS} -o ${TEST} ${CPPFLAGS}


${OBJS}: ${LIBS} ${HDRS}

${TEST_OBJS}: ${LIBS} ${HDRS} ${TEST_HDRS}

%.a: lib
	make $(@F) -C $(@D)


headers_test: ${HDRS:.hpp=.hpp.o} ${TEST_HDRS:.hpp=.hpp.o}
%.hpp.o: ${HDRS} ${TEST_HDRS}
	${CXX} ${CPPFLAGS} ${@:.o=} -c -o $@
%.hpp:

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.out

re: clean all

.PHONY: all clean re lib headers_test
