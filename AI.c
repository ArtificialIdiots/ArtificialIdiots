#include <stdio.h>
#include <string.h>

int main() {
	char buf[128];
	while (fgets(buf, 127, stdin)) {
		char *p = strstr(buf, "吗");
		if (p)
			*p = 0;
		printf("%s！\n", buf);
	}
}