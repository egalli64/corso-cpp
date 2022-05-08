#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Func {
private:
	std::string prefix_;
public:
	Func(const std::string& prefix = "") : prefix_(prefix) {}

	void operator()(const std::string& message) const {
		std::cout << prefix_ << message << '\n';
	}
};

int main() {
	Func func;
	func("A function object is a callable");

	std::vector<std::string> names{ "Tom", "Bob", "Kim" };
	std::cout << "Passing a function object to a function:\n";
	std::for_each(names.begin(), names.end(), Func("-> "));
}