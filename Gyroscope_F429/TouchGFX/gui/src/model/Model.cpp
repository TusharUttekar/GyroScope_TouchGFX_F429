#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern int tickCounter;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(tickCounter % 2 == 0)
	{
		modelListener->Update_Graph();
	}
}
