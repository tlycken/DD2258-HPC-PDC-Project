CPPFLAGS = -I/usr/local/MATLAB/R2011a/extern/include -g
LDFLAGS = -L/usr/local/MATLAB/R2011a/bin/glnxa64 -Wl,-rpath /usr/local/MATLAB/R2011a/bin/glnxa64
LDLIBS = -lmat -lmx

EXE = animate_shot

clean:
	rm -f $(EXE) *.o *~ *#

rebuild: clean $(EXE)

$(EXE): dataloader.o
