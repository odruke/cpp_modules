#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <sstream>


int	main(int ac, char **av)
{
	std::stringstream	buff;
	std::string			content;
	std::string			filename;
	std::string			s1;
	std::string			s2;
	size_t				pos = 0;

	if (ac != 4){
		std::cout
			<< "Wrong parameters. Usage:\n"
			<< "./sedplus [filename.txt] [\"to replace\"] [\"to be replaced\"]" << std::endl;
			return EXIT_FAILURE;
	}

	filename = av[1];
	if (filename.empty()){
		std::cout << "no file to open" << std::endl;
		return EXIT_FAILURE;
	}
	if (!filename.compare("replaced.txt")){
		std::cout << "can't read and write to the same file" << std::endl;
		return EXIT_FAILURE;
	}

	s1 = av[2];
	s2 = av[3];
	if (s1.empty()){
		std::cout << "no text to find inputed" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(filename.c_str());
	if (!file){
		std::cout << "couldn't open the file" << std::endl;
		return EXIT_FAILURE;
	}

	buff << file.rdbuf();
	content = buff.str();

	while ((pos = content.find(s1, pos)) != std::string::npos){
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	if (pos == 0) {
		std::cout << "No occurrences of \"" << s1 << "\" found.\n";
		file.close();
		return EXIT_SUCCESS;
	}

	std::ofstream	outfile("replaced.txt");
	if (!outfile){
		file.close();
		std::cout << "could't create/open replaced.txt" << std::endl;
		return EXIT_FAILURE;
	}

	outfile << content;
	file.close();
	outfile.close();
	return EXIT_SUCCESS;
}
