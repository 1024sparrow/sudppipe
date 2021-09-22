# To run the resulting program, try something like:
#    ./sudppipe -l ./replace_plugin.so -L xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx,<hosted-graphite-key> <destination-server> 2004 2004

# sudo apt install -y gcc-mingw-w64


CFLAGS = -Wall -funsigned-char -Wno-unused-result 

all: sudppipe sudppipe-win64.exe replace_plugin.so

sudppipe-win64.exe: sudppipe.c
	x86_64-w64-mingw32-gcc sudppipe.c -o sudppipe-win64.exe -lwsock32

sudppipe: sudppipe.c
	$(CC) $(CFLAGS) -g -O2 -o "$@" "$<" -ldl

replace_plugin.so: replace_plugin.c
	$(CC) $(CFLAGS) -g -O2 -shared -fPIC -o "$@" "$<"


clean:
	rm sudppipe sudppipe-win64.exe replace_plugin.so
