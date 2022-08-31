# GyroScope_TouchGFX_F429

Description
-----------

First using the touchgfx we create the basic UI where we add the background images, Text area's and the most important part
of our interface that is the Dynamic Graph Widget.

We need to add 3 instances of the Dynamic graph widget since we need to display and update three individual value's.

Currently i was not able to update mutiple lines in one instance of the Dynamic graph widget so that is the reason we are using mutiple instances.

Next in the programming side we do the basic setup of the Graph Update function for updating graph values based on touchgfx MVP Model

```
void Model::tick()
{
	if(tickCounter % 2 == 0)
	{
		modelListener->Update_Graph();
	}
}
```

Next we do the Initialization for the Gyroscope Sensor Based on the library and Fetch its value every 100 milliseconds which will be updated to the graph

```
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	  tickCounter++;
	  if(tickCounter >= 0xFFFF0000)
	  {
		  tickCounter = 0;
	  }

	  //Gyro_ID = L3GD20_ReadID();
	  L3GD20_ReadXYZAngRate(Gyro_Value);
	  osDelay(100);
  }
  /* USER CODE END 5 */
}
```
Output
------

![20220815_201915](https://user-images.githubusercontent.com/104786774/184659121-385177c2-a139-4f08-a6f1-1e2507d7facf.jpg)

Hardware
--------

->STM32F429-DISC1 Development Board

->ON Board Gyroscope (L3GD20)

->ON Board TFT Display (SF-TC240T-9370-T)

Software
--------

->STM32Cube-IDE for Programming

->TouchGFX for Creating the GUI Interface

Reference
---------

TouchGFX Dynamic Graph : https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiL7f6qjcn5AhX99zgGHX01A80QwqsBegQIBRAB&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3Dvv9TTHav-gY&usg=AOvVaw0X8roheKvXFOTbbVfGLw_Z

TouchGFX MVP Modle : https://support.touchgfx.com/4.14/docs/development/ui-development/software-architecture/model-view-presenter-design-pattern
