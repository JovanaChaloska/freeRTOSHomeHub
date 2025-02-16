#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

	#include "FreeRTOS.h"
	#include "queue.h"
	#include "task.h"
float tempval;
int pollutionval;
float lightval;
int ishomeval;

extern "C"{
	//Communicate with the backend app via queues
	xQueueHandle TempQueueHandle;
	xTaskHandle xTempSensor;
	xQueueHandle PollutionQueueHandle;
	xTaskHandle xPollutionSensor;
	xQueueHandle LightQueueHandle;
	xTaskHandle xLightSensor;
	xQueueHandle IsHomeQueueHandle;
	xTaskHandle xIsHomeSensor;
}

Model::Model() : modelListener(0)
{
	//Queues creation
	TempQueueHandle = xQueueGenericCreate(1, sizeof(float), 0);
	PollutionQueueHandle = xQueueGenericCreate(5, sizeof(int), 0);
	LightQueueHandle = xQueueGenericCreate(1, sizeof(float), 0);
	IsHomeQueueHandle = xQueueGenericCreate(1, sizeof(int), 0);
}

void Model::tick()
{
	//Check if there are some new values in the queues and transfer them to the Presenter Layer
	if(xQueueReceive(TempQueueHandle, &tempval, 0) == pdTRUE){
			modelListener->setNewTemp(tempval);
	}
	if(xQueueReceive(PollutionQueueHandle, &pollutionval, 0) == pdTRUE){
			//printf("Pollution queue full! Data lost.\n");
			modelListener->setNewPollution(pollutionval);
	}
	if(xQueueReceive(LightQueueHandle, &lightval, 0) == pdTRUE){
			//printf("Pollution queue full! Data lost.\n");
			modelListener->setNewLight(lightval);
	}
	if(xQueueReceive(IsHomeQueueHandle, &ishomeval, 0) == pdTRUE){
			//printf("Pollution queue full! Data lost.\n");
			modelListener->setNewIsHome(ishomeval);
	}
}
