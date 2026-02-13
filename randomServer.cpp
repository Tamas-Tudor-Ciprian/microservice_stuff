#include <iostream>
#include <crow.h>
#include <random>
#include <ctime>
#include <cstdlib>



int get_random(){

	return std::rand() % 100 + 1;

}


int main(){

	std::srand(std::time(nullptr));

	crow::SimpleApp app;
	
	//this is so you can see that the server is working
	CROW_ROUTE(app, "/debug")
	([]{
		return "Working\n";

	}
	);

	//you get your random number from te main route
	CROW_ROUTE(app, "/")
	([]{
		crow::json::wvalue random_number;

		random_number["value"] = get_random();

		return random_number;

	}
	);

	app.port(8081).multithreaded().run();

	return 0;
}



