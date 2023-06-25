OUT = bin/task
CC = g++
ODIR = obj
SDIR = src
INC = -Iinc

_OBJS = main.o circle.o ellipse.o helix.o 
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS) 
	$(CC) -o $(OUT) $^

clean:
	rm -f $(ODIR)/*.o $(OUT)