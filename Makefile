name = nwm
exec = $(name)
flags = -std=c++17 -g -Wall -lm -ldl -fPIC -rdynamic -lnapi

source_files := $(shell find src/ -name *.cpp)
objects_files := $(patsubst src/%.cpp, build/%.o, $(source_files))

$(objects_files): build/%.o : src/%.cpp
	mkdir -p $(dir $@) && \
	g++ -c -I src $(patsubst build/%.o, src/%.cpp, $@) -o $@

clean:
	-rm -rf build $(exec) && \
	mkdir build

all: clean build

build: $(objects_files)
	g++ -o $(exec) $(objects_files) $(flags)
