// Windows users please compile in Cygwin/MingW/WSL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/poll.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

int malfunction = 0;
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

int begins_with(const char *s) {
	size_t l = strlen(s);
	if (l > input_size)
		return 0;
	return !memcmp(s, input_string, l);
}

void overwrite(const char *s) {
	size_t l = strlen(s);
	memcpy(input_string, s, l);
}

// AI 核心代码，估值一个亿
void idiot_logic() {
	if (input_string[0] == '\n') {
		puts("喵？");
		return;
	}

	if (strstr(input_string, "996")) {
		malfunction = 2;
		printf("如果没有没有这么多加班，何来现在这么的财富？\n");
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

	if (begins_with("你") || begins_with("您")) {
		if (!begins_with("你好") && !begins_with("您好")){
			overwrite("我");
		}
	}

	char *e = strstr(input_string, "！");

	if (e) {
		*e = 0;
		printf("%s呀～\n", input_string);
	} else
		printf("%s！\n", input_string);
}

#define LEN_WORDS	72
const char malfunction_words[][LEN_WORDS] = {
	"I don't know how to help with that.",
	"Hmmmm, something went wrong, please try again in a few seconds.",
	"我好像没听明白",
	"Please stand by...",
	"Sorry, but err != nil",
	"I cannot access the internet, check your router's connection",
	"Whoops! I stepped in an interface{}",
	"hhhhhhhhhhhhhh",
	"我不懂你的意思//",
	"能再说一遍吗？",
	"什么？",
	"emmmmm",
	"Segmentation fault",
	"Bus error",
	"bnx2x: probe of 0001:14:51.4 failed with error -23333",
	"嘿小朋友们大家好",
	"哇",
	"openssh.com reply 1",

};

const char malfunction_words2[][LEN_WORDS] = {
	// Someone's famous words
	"时间是显性的，效率是隐性的",
	"Go非常的显式，你们C++一点都不显式",
	"2. 先不管了 √",
	"我是一个爱才的人",
	"我不纠结，不纠结",
	"这是出于综合考虑",
	"我觉得你大有可为",
	"只要你不写出这样的代码就行了",
	"为什么你们可以那么轻松而我就那么累呢",
	"你们怎么忍心对我这么残忍",
	"我不想把deadline压到你们头上",
	"我这是为了你好",

	// lol
	"啦啦我是一棵蔬菜",
	"虽然我连git都不会用，但是我能让老板把你开了哦hhhhhh",
	"就算我每天上班都摸鱼，也要让老板看到我坐在那里",
	"抽烟怎么了？老子在楼下抽烟已经给你面子了"
};

void idiot_logic_malfunction() {
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	srand(ts.tv_nsec);
	if (malfunction == 1) {
		int rnd = rand() % sizeof(malfunction_words) / LEN_WORDS;
		puts(malfunction_words[rnd]);
	} else {
		int rnd = rand() % sizeof(malfunction_words2) / LEN_WORDS;
		puts(malfunction_words2[rnd]);
	}
}

int main(int argc, char **argv) {
	signal(SIGINT, sigint_handler);

	if (argv[1] && 0 == strcmp(argv[1], "114514"))
		malfunction = 1;

	input_string = malloc(0);
	char buf[128];

	fd_set_nonblocking(STDIN_FILENO);

	struct pollfd fds = {
		.fd = STDIN_FILENO,
		.events = POLLIN
	};

	puts("你好，我的朋友！");

	prompt();

	while (1) {
		int rc_poll = poll(&fds, 1, 100);

		if (rc_poll == 0) {
			if (input_size) {
				if (malfunction)
					idiot_logic_malfunction();
				else
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
