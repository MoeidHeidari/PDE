# Nonhomogeneous PDE - Heat equation
Developed by Moeid Heidari and Omar Mohammed  
Non homogeneous Heat conduction equation implementation in c++.

<a href="https://ibb.co/6BTfyS2"><img src="https://i.ibb.co/jRQ18Yd/imgonline-com-ua-impr-Scanned-Text-2y-MBx3r-N8sj.png" alt="imgonline-com-ua-impr-Scanned-Text-2y-MBx3r-N8sj" border="0"></a>

<h3><b>Strategy:</b> </h3>
Step 1. Obtain the eigenfunctions in x, Gn(x), that satisfy the PDE and boundary conditions (I) and (II) <br />
Step 2. Expand u(x,t), f(x,t), and P(x) in series of Gn(x). This will convert the nonhomogeneous 
PDE to a set of simple nonhomogeneous ODEs. <br />
Step 3. We Solve the nonhomogeneous ODEs, use their solutions to reassemble the complete solution
for the PDE. <br />

For the current example, our eigenfunctions are Gn(x) = sin(npx), so we should try <br />

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
