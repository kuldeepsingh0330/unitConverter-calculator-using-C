float distanceConv[] = {1.0, 1000.0, 100000.0, 0.621371192, 1093.6133, 1000000.0, 3280.8399, 39370.0787};
					//    km,      m,     cm,        miles,       yards,     mm,         feet,      inches
float massConv[] = {1.0, 1000.0, 1000000.0, 0.001, 0.00110231131, 2.20462, 0.157473044, 35.2739619};
				    // kg,   g,     mg,     tonne,     US ton,      pounds,       stones,      ounces
float volConv[] = {1.0, 1000.0, 1000000.0, 264.172052, 4166.67, 67628.0454, 219.969157, 3519.51, 56312.1043, 33814.0227};
			    //  cubic m, L,   mL, US liquid gallons, US legal cups, US tablespoons,Imperial gallons,Imperial cups,Imperial tablespoons,fluid ounces

float convertData(int, int, int, float);                // 1) distance, 2) mass, 3) volume

float convertData(int c, int fromUnit, int toUnit, float fromMagnitude)
{
	float toMagnitude;
	switch(c)
	{
		case 1:        // distance
			toMagnitude = (distanceConv[toUnit - 1] / distanceConv[fromUnit - 1]) * fromMagnitude;
			break;
		case 2:        // mass
			toMagnitude = (massConv[toUnit - 1] / massConv[fromUnit - 1]) * fromMagnitude;
			break;
		case 3:        // volume
			if(fromUnit == 0)
			{
				toMagnitude = (volConv[toUnit - 1] / volConv[9]) * fromMagnitude;
				break;
			}
			else if(toUnit == 0)
			{
				toMagnitude = (volConv[9] / volConv[fromUnit - 1]) * fromMagnitude;
				break;
			}
			else
			{
				toMagnitude = (volConv[toUnit - 1] / volConv[fromUnit - 1]) * fromMagnitude;
				break;
			}
		default:
			puts("Error! 'c' can't be other than 1, 2 or 3!");
			getch();
			exit(1);
	}
	return(toMagnitude);
}
