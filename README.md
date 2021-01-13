# Nonhomogeneous PDE - Heat equation
Developed by Moeid Heidari and Omar Mohammed  
Non homogeneous Heat conduction equation implementation in c++.

<a href="https://imgbb.com/"><img src="https://i.ibb.co/9ZHd4x7/eq1p.png" alt="eq1p" border="0" width="320" height="135"></a>
<a href="https://imgbb.com/"><img src="https://i.ibb.co/G3M7z6G/1.png" alt="1" border="0" width="110" height="140"></a>
<h3><b>Strategy:</b> </h3>
Step 1. Obtain the eigenfunctions in x, Gn(x), that satisfy the PDE and boundary conditions (I) and (II) <br />
Step 2. Expand u(x,t), f(x,t), and P(x) in series of Gn(x). This will convert the nonhomogeneous 
PDE to a set of simple nonhomogeneous ODEs. <br />
Step 3. We Solve the nonhomogeneous ODEs, use their solutions to reassemble the complete solution.
for the PDE. <br /> <br />

For the current example, our eigenfunctions are Gn(x) = sin(n<span style='color:black'>&pi;</span>x), so we should try <br /> <br /><br />

<a href="https://imgbb.com/"><img src="https://i.ibb.co/KbSS600/eq-2-3-4p.png" alt="eq-2-3-4p" border="0" width="320" height="195"></a> 
<a href="https://ibb.co/3p6Pwhk"><img src="https://i.ibb.co/F5Zd97n/eq-2-3-4p1.png" alt="eq-2-3-4p1" border="0" width="360" height="190"></a> 

<br /><br />
From Eqs. (3) and (4), qn(t) and un(0) have already been determined. Our task is to solve un(t) and express it in
un(0) (the initial condition of un(t)) and qn(t) (the forcing that acts on un(t)). <br /><br />
Plugging Eq. (2) into the original PDE, we have

<a href="https://ibb.co/mD3vQ0Z"><img src="https://i.ibb.co/JB9xXq6/mathpix-2021-01-13-18-07-19.png" alt="mathpix-2021-01-13-18-07-19" border="0"></a><br /><br />
<a href="https://ibb.co/5jT0GGW"><img src="https://i.ibb.co/FY6rmmb/mathpix-2021-01-13-18-14-14.png" alt="mathpix-2021-01-13-18-14-14" border="0" ></a><br /><br />
<a href="https://ibb.co/kc6RwrV"><img src="https://i.ibb.co/XJkhKdf/mathpix-2021-01-13-18-16-24.png" alt="mathpix-2021-01-13-18-16-24" border="0" width="800"></a> <br />
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
