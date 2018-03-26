FLAGS:="-pthread"

all: signal

signal: play_with_signals.o
	gcc -o signal play_with_signals.o ${FLAGS}

play_with_signals.o:
	gcc -c play_with_signals.c ${FLAGS}

clean: 
	rm -f signal play_with_signals.o
