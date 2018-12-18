#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/poll.h>
#include <fcntl.h>
#include <signal.h>

size_t input_size = 0;
char *input_string = NULL;

void fd_set_nonblocking(int fd) {
	int flags = fcntl(fd, F_GETFL, 0);
	flags = flags | O_NONBLOCK;
	fcntl(fd, F_SETFL, flags);
}

void goodbye() {
	puts("\n再见我的朋友！");
	exit(0);
}

void prompt() {
	write(STDOUT_FILENO, ">> ", 3);
}

void sigint_handler(int sig) {
	goodbye();
}

void idiot_logic() {
	if (input_string[0] == '\n') {
		puts("喵？");
		return;
	}

	if (strstr(input_string, "再见")) {
		goodbye();
	}

	char *nl = strchr(input_string, '\n');
	if (nl)
		*nl = 0;

	char *p = strstr(input_string, "吗");
	if (!p)
		p = strstr(input_string, "？");
	if (p)
		*p = 0;

	char *e = strstr(input_string, "！");

	if (e) {
		*e = 0;
		printf("%s呀～\n", input_string);
	} else
		printf("%s！\n", input_string);
}

int main() {
	signal(SIGINT, sigint_handler);

	input_string = malloc(0);
	ssize_t ret = 0;
	char buf[128];

	fd_set_nonblocking(STDIN_FILENO);

	struct pollfd fds = {
		.fd = STDIN_FILENO,
		.events = POLLIN
	};

	prompt();

	while (1) {
		int rc_poll = poll(&fds, 1, 100);

		if (rc_poll == 0) {
			if (input_size) {
				idiot_logic();
				input_string = realloc(input_string, 0);
				input_size = 0;
				prompt();
			}
		} else if (rc_poll > 0) {
			ssize_t rc = read(STDIN_FILENO, buf, 128);
			size_t new_input_size = input_size + rc;
			input_string = realloc(input_string, new_input_size+1);
			memcpy(input_string+input_size, buf, rc);
			input_size = new_input_size;
			input_string[input_size] = 0;
		}
	}

}
