#include <iostream>
#include <crow.h> 
#include <immintrin.h>


struct coords{
	float x = 0;
	float y = 0; 

};



float get_random(){
	unsigned int cpu_value;
	float random = 0;
	if(_rdrand32_step(&cpu_value))
		random = static_cast<float>(cpu_value);
	
	return random;

}

int main(){



	crow::SimpleApp app;




	//call the route to see if the service and network is working
	CROW_ROUTE(app, "/debug")
	([]{
		return "Working!\n";
	}
	);
	
	//this is still debug but for the random number generation
	CROW_ROUTE(app,"/random")
	([]{
		crow::json::wvalue random_number;
		random_number["value"] = get_random();
		return random_number;
	}
	);
	app.port(8081).multithreaded().run();
	
	return 0;
}


