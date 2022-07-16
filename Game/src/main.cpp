#include "Bright.h"


class Game : public Bright::Application
{
public:
	Game()
	{
		
	}

	~Game()
	{

	}



};


Bright::Application* Bright::CreateApplication()
{
	return new Game();
}