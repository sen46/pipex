#include <stdio.h>
#include <unistd.h>

int main()
{
	int j = 0;
	pid_t pid = fork();
	for (int i = 0; i < 3; i++)
	{
		if (pid == 0)
		{
			printf("child%d\n", j++);
		}
		else
		{
			pid_t pid = fork();
			printf("parent%d\n", j++);
		}
	}
	/// printf("finish\n");
	return (0);
}

