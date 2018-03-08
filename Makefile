

SRC=yuv-test.c
OBJ=yuv-test.o

APP=test


INCLUDES = -I./

.PONEY:all

all:$(APP) 


$(APP):$(OBJ) 
	@g++  $(OBJ) /usr/local/lib/libyuv.a  -o $@ 

    
%.o:%.cpp
	g++ -c  -fPIC $(INCLUDES) $< -o $@
	
%.o:%.c
	gcc -c $(INCLUDES) $< -o $@    
    
clean:
	@rm -rf $(OBJ) $(APP)
	
	
