Main: Main.o
	g++ Main.o Time.o -o Main

Main.o: main.cpp Time.o
	g++ -c main.cpp -o Main.o
Time.o: Time.cpp Time.h
	g++ -c Time.cpp -o Time.o

clean:
	rm *.o Main
