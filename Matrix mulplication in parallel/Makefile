TARGETS = main

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

%: %.c
	gcc -g -o $@ $^ -lpthread
