HDRS = \
	BoundingBox.hpp \
	Format.hpp \
	Frustrum.hpp \
	Imaginary.hpp \
	Matrix.hpp \
	Matrix_RowEchelon.hpp \
	Vector.hpp \
	abs.hpp \
	atok.hpp \
	conjugate.hpp \
	lerp.hpp \

SRCS = \
	Format.cpp \
	Frustrum.cpp \
	proj.cpp \

TEST_HDRS = \
	TestFactory.hpp \
	matrix_tester.hpp \
	nmp_tester.hpp \
	number_tester.hpp \
	vector_tester.hpp \

MAIN_SRCS = \
	main.cpp \

LIBS = \
	logutil/logutil.a \

OBJS      = ${SRCS:.cpp=.o}
MAIN_OBJS = ${MAIN_SRCS:.cpp=.o}

NAME = ft_matrix.a
TEST = ft_matrix.out proj.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}


${NAME}: ${LIBS} ${HDRS} ${OBJS}
	ar rcs ${NAME} ${OBJS}

ft_matrix.out: ${NAME} main.o
	${CXX} main.o ${NAME} ${LIBS} -o $(@F) ${CPPFLAGS}

proj.out: ${NAME} main.proj.o
	${CXX} main.proj.o ${NAME} ${LIBS} -o $(@F) ${CPPFLAGS}


${OBJS}: ${LIBS} ${HDRS}

${MAIN_OBJS}: ${LIBS} ${HDRS} ${TEST_HDRS}

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
