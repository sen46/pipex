make re
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
	./pipex input.txt "wc -l" "cat -e" "cat -e" output.txt
cat output.txt
