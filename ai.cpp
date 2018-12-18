#include <iostream>
#include <string>

int main() {
	std::string buf;

	while (1) {
		std::cin >> buf;
		auto t = buf.find("吗");
		if (t != buf.npos)
			buf.erase(t, buf.size()-t);
		std::cout << buf << "！\n";
	}
}