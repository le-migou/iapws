include ../config.mk

CXXFLAGS+=-g

.PHONY: all clean check

all: check

check: tests
	./tests

SRC = $(wildcard test_*.cpp)
OBJ = $(subst .cpp,.o, $(SRC))

tests: tests.o $(OBJ) \
	test-r6.o           \
	test-r7.o           \
	test-r6_inverse.o   \
	test-r10.o          \
	test-r14.o          \
	test-r12.o          \
	test-r12_inverse.o  \
	test-g12.o          \
	test-r10_inverse.o  \
	test-g12_inverse.o  \
	test-r8.o           \
	test-r8_inverse.o   \

SEPARATOR=+
NAMES = $(subst test_,,$(basename $(SRC)))
TEMPLATE = $(join test_, $(1)).o: $(join test_, $(1)).cpp $(foreach h, $(subst $(SEPARATOR), ,$(1)), $(join ../include/calculisto/${PROJECT}/, $(h)).hpp)
$(foreach name, $(NAMES), $(eval $(call TEMPLATE,$(name))))

test-r6.o:          test-r6.cpp          ../include/calculisto/iapws/r6.hpp          ../include/calculisto/iapws/detail/common.hpp
test-r7.o:          test-r7.cpp          ../include/calculisto/iapws/r7.hpp          ../include/calculisto/iapws/detail/common.hpp ../include/calculisto/iapws/detail/data_for_the_tests.hpp
test-r6_inverse.o:  test-r6_inverse.cpp  ../include/calculisto/iapws/r6_inverse.hpp  ../include/calculisto/iapws/detail/common.hpp
test-r10.o:         test-r10.cpp         ../include/calculisto/iapws/r10.hpp         ../include/calculisto/iapws/detail/common.hpp
test-r14.o:         test-r14.cpp         ../include/calculisto/iapws/r14.hpp         ../include/calculisto/iapws/detail/common.hpp
test-r12.o:         test-r12.cpp         ../include/calculisto/iapws/r12.hpp         ../include/calculisto/iapws/detail/common.hpp
test-r12_inverse.o: test-r12_inverse.cpp ../include/calculisto/iapws/r12_inverse.hpp ../include/calculisto/iapws/detail/common.hpp ../include/calculisto/iapws/r6_inverse.hpp
test-g12.o:         test-g12.cpp         ../include/calculisto/iapws/g12.hpp         ../include/calculisto/iapws/detail/common.hpp
test-r10_inverse.o: test-r10_inverse.cpp ../include/calculisto/iapws/r10_inverse.hpp ../include/calculisto/iapws/detail/common.hpp
test-g12_inverse.o: test-g12_inverse.cpp ../include/calculisto/iapws/g12_inverse.hpp ../include/calculisto/iapws/detail/common.hpp
test-r8.o:          test-r8.cpp          ../include/calculisto/iapws/r8.hpp          ../include/calculisto/iapws/detail/common.hpp
test-r8_inverse.o:  test-r8_inverse.cpp  ../include/calculisto/iapws/r8_inverse.hpp  ../include/calculisto/iapws/detail/common.hpp ../include/calculisto/iapws/r6_inverse.hpp

clean: 
	rm -f tests *.o 
