COMPILER = g++
a.out: main.o store.o buyer.o seller.o goods.o
	${COMPILER} main.o store.o buyer.o seller.o goods.o

main.o: main.cpp store.h
	${COMPILER} -c main.cpp

store.o: store.cpp store.h
	${COMPILER} -c store.cpp

goods.o: goods.cpp goods.h
	${COMPILER} -c goods.cpp

seller.o: seller.cpp seller.h
	${COMPILER} -c seller.cpp

buyer.o: buyer.cpp buyer.h
	${COMPILER} -c buyer.cpp


clean:
	rm *.o
	rm a.out