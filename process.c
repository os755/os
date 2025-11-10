#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t num_pid;
int arr[5] = {1,4,5,2,3};
const int n = 5;

void asc(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("Ascending: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void desc(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] < a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("Descending: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// int main() {
// 	num_pid = fork();
// 
// 	if (num_pid < 0) {
// 		printf("Error in fork execution\n");
// 	} 
// 	else if (num_pid == 0) {
// 		printf("This is the child process id %d\n", getpid());
// 		asc(arr, n);
// 	} 
// 	else {
// 		wait(NULL); // wait for child to finish
// 		printf("This is the parent process id %d\n", getpid());
// 		desc(arr, n);
// 	}
// 
// 	return 0;
// }

//orphan
// int main() {
// 	num_pid = fork();
// 
// 	if (num_pid > 0) {
// 		printf("This is the parent process id %d\n", getpid());
// 		printf("This is the child process id %d\n", num_pid);
// 	} 
// 	else if (num_pid == 0) {
// 	//sleep(6);
// 		printf("This is the child process id %d\n", getpid());
// 		printf("This is the parent process id %d\n", getppid());
// 	} 
// }

// zombie
int main(void) {
	pid_t pid;
	if((pid=fork()) < 0)
	printf("\tfork error\n");
	else
	if (pid==0)
	printf("child process id is %d\n",getpid());
	else {
		sleep(10);
		printf("*****parent\n");
		system("ps -axj | tail");
	}
	exit(0);
}
