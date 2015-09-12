CXX        := g++
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f KitayutasGift
	rm -f test.tmp

config:
	git config -l

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: KitayutasGift.tmp

KitayutasGift: KitayutasGift2.c++ 
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) KitayutasGift2.c++ -o KitayutasGift

KitayutasGift.tmp: KitayutasGift
	./KitayutasGift < test.in > test.tmp
	diff test.tmp test.out
