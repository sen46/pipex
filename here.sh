make re
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
./pipex here_doc EOF "wa" "cat -e" output.txt
cat output.txt
