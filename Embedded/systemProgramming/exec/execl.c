/* replacing parent process image wiht a new process that is ps*/
/* ps lies in /bin directory 
 * declaration of execl();
 * int execl(const char *path, const char *arg0,...,(char *)0);
 */

#include<unistd.h>
#include<stdio.h>
void main()
{
	pid_t pid;


	printf(" parent---processID: %d\n",getpid());

	sleep(10);

	//execl("/bin/ps", "ps", "ax", 0);

	//replacing process image of a.out wiht gnome-calculator
	execl("/bin/gnome-calculator","murali", NULL);

	
	

}


