all:
	make -C linkedlist/
	make -C src/

clean:
	make -C linkedlist/ $@
	make -C src/ $@

fclean:
	make -C linkedlist/ $@
	make -C src/ $@

re:
	make -C linkedlist/ $@
	make -C src/ $@

.PHONY: all clean fclean re