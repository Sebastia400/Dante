##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

GENERATOR = generator/

SOLVER = solver/

all: $(OBJ)
	make -C $(GENERATOR)
	make -C $(SOLVER)

clean:
	make -C $(GENERATOR) clean
	make -C $(SOLVER) clean

fclean: clean
	make -C $(GENERATOR) fclean
	make -C $(SOLVER) fclean

re:	fclean all
