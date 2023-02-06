/* program on execlp() system call
 * execlp() sys call takes the input as file name whereas execl() takes the first arguement as
 * path to the file 
 * so, execlp() by default searches the file inside /bin, /sbin, /usr/bin directories
 */

/* this program creates child process of */
#include<stdio.h>
#include<unistd.h>
void main()
{

	pid_t pid;

	pid = fork();

	
