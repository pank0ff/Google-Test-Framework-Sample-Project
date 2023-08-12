GTEST_DIR = ..

USER_DIR = ../samples

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra
CFLAG = -fPIC -fprofile-arcs -ftest-coverage

TESTS = test

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h \
				$(GTEST_DIR)/include/gmock/*.h \
                $(GTEST_DIR)/include/gmock/internal/*.h

all : $(TESTS)

clean :
	rm -rf $(TESTS) gtest.a gtest_main.a *.o *.gcno *.gcda *.info out

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX)  $(CFLAG) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) $(CFLAG) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gmock-all.o : $(GTEST_SRCS_)
	$(CXX)  $(CFLAG) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gmock-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gmock.a : gmock-all.o
	$(AR) $(ARFLAGS) $@ $^	

gtest_main.a : gtest-all.o gmock-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

sample.o : $(USER_DIR)/sample.c $(USER_DIR)/sample.h $(GTEST_HEADERS)
	$(CXX) $(CFLAG) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample.c

test.o : $(USER_DIR)/test.cpp $(USER_DIR)/sample.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test.cpp

test : sample.o test.o gtest_main.a
	$(CXX) $(CFLAG) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
