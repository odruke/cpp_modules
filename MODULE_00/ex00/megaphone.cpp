#include <iostream>
#include <cctype>

int	main(int ac, char **av){

	if (ac > 1){
		for (int i = 1; i < ac; i++){
			std::string	param(av[i]);
			for (int j = 0;j < param.length(); j++){
				 param[j] = std::toupper(param[j]);
			}
			std::cout << param;
		}
		std::cout << std::endl;
	}
	else{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}
