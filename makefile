HDRS = \
	BoundingBox.hpp \
	Format.hpp \
	Frustrum.hpp \
	Imaginary.hpp \
	Matrix.hpp \
	Matrix_RowEchelon.hpp \
	Remap.hpp \
	Vector.hpp \
	abs.hpp \
	atok.hpp \
	conjugate.hpp \
	lerp.hpp \
	proj.hpp \

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

DEPS      = ${SRCS:.cpp=.d} ${MAIN_SRCS:.cpp=.d}
OBJS      = ${SRCS:.cpp=.o}
MAIN_OBJS = ${MAIN_SRCS:.cpp=.o}

NAME = ft_matrix.a
TEST = ft_matrix.out proj.out
CXX = g++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${NAME}: ${LIBS} ${OBJS}
	ar rcs ${NAME} ${OBJS}

ft_matrix.out: ${NAME} main.o
	${CXX} main.o ${NAME} ${LIBS} -o $(@F) ${CPPFLAGS}

proj.out: ${NAME} main.proj.o
	${CXX} main.proj.o ${NAME} ${LIBS} -o $(@F) ${CPPFLAGS}


%.a: lib
	make $(@F) -C $(@D)

%.o : %.cpp %.d
	$(COMPILE.cpp) ${@:.o=.cpp} -MMD -MP -MF $(@:.o=.d.tmp)
	@mv $(@:.o=.d.tmp) $(@:.o=.d)
	@touch $@

${DEPS}:

include $(wildcard ${DEPS})


headers_test: ${HDRS:.hpp=.hpp.gch} ${TEST_HDRS:.hpp=.hpp.gch}
%.hpp.gch: ${HDRS} ${TEST_HDRS}
	${CXX} ${CPPFLAGS} ${@:.gch=} -c -o $@
%.hpp:


clean:
	rm -f *.o
	rm -f *.gch
	rm -f *.d
	rm -f *.a
	rm -f *.out

re: clean all

.PHONY: all clean re lib headers_test
