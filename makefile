CC=gcc
AR=ar
FLAGS= -Wall -g
LOOPERS=advancedClassificationLoop.o basicClassification.o
RECURSER=advancedClassificationRec.c basicClassification.c 

advancedClassificationLoop.o:advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c 

advancedClassificationRec.o:advancedClassificationRec.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRec.c 

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c 



loopd : libclassloops.so
loops : libclassloops.a 
recursives : libclassrec.a 
recursived : libclassrec.so
all: loopd loops recursived recursives mains maindloop maindrec

libclassloops.a: advancedClassificationLoop.o basicClassification.o
	$(AR) -rcs libclassloops.a $(LOOPERS)

libclassrec.a: $(RECURSER)

	$(AR) -rcs libclassrec.a $(RECURSER)

libclassrec.so: $(RECURSER)
	$(CC) -shared -o -fPIC libclassrec.so $(RECURSER)  

libclassloops.so: $(LOOPERS)
	$(CC) -shared -fPIC -o libclassloops.so $(RECURSER)

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c 

mains: main.o libclassrec.a 
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec : main.o libclassrec.so 
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm








clean:
	rm maind maindrec mains.o.so*.a 

