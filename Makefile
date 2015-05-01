all:
	g++ -I./ -I../../ -O3 -o cornelius cornelius.cpp
win:
	g++ -I./ -I../../ -O3 -o cornelius cornelius.cpp -l Ws2_32
