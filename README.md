# PDE
Developed by Moeid Heidari and Omar Mohammed  
Non homogeneous Heat conduction equation implementation in c++

## Installation

Use the Makefile to make the source code

```bash

IDIR =include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =lib

_DEPS = PDE.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pde.o main.o
OBJ = $($(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: main.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) src/main.cpp -o main

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

```

#use make in the root directory of the project
```
make
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Skheydari@stud.etu.ru  
Omokhammed@stud.etu.ru

## License
[MIT](https://choosealicense.com/licenses/MIT/)
