#include <iostream>
#include <filesystem>
#include <cassert>
namespace fs = std::filesystem;
 
int main(int arc,char** argv)
{
    std::error_code ec;
    fs::create_symlink(argv[1], argv[2], ec);
	if (ec)
		std::cerr << "create_symlink " << argv[1] << " " << argv[2] << "\n\tError: " << ec.message() << "\n";
}
