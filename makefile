CMPLR=gcc

CFLAGS= -std=c11 -g -Wall -Wextra -Werror
LCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

LIB_NAME = data_types
SOURCES = *.c

all: $(LIB_NAME).a

$(LIB_NAME).a: make_obj_dir
	cd src && $(CMPLR) $(CFLAGS) $(SOURCES) -c
	mv src/$(SOURCES:.c=.o) $(OBJ_DIR)
	ar rc $(LIB_NAME).a $(OBJ_DIR)/*.o
	ranlib $(LIB_NAME).a
	mv $(LIB_NAME).a $(BUILD_DIR)/

build_covered: add_coverage rebuild

build_debug: add_debug rebuild

clean:	
	rm -rf $(BUILD_DIR)/$(LIB_NAME).a $(OBJ_DIR)/*.o
	rm -rf *.gcda *.gcno

rebuild: clean $(LIB_NAME).a

make_obj_dir:
	mkdir -p $(OBJ_DIR)

add_coverage:
	$(eval CFLAGS += --coverage)
add_debug:
	$(eval CFLAGS += -DDEBUG_MODE)
remove_dushnina:
	$(eval CFLAGS = -g)
