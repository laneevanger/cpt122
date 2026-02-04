#include "pa1.h" 
 
int main(void) 
{ 
	FILE* inputStream = fopen("FitbitDataCopy.csv", "r"); 
 
	FitbitData entries[1440] = {0}; 
	char user[10]; 
	char line[125]; 
	char header[125]; 
	char sleep[20] = { 0 }; 
	int index; 
	char* charTok = NULL; 
	 
	double tCal = 0; 
	double tDis = 0; 
	double avgHrate = 0; 
	int tFloors = 0; 
	int mSteps = 0; 
	int tSteps = 0; 
	 
	//user row 
	fgets(line, sizeof(line), inputStream); 
	charTok = strtok(line, ","); 
	charTok = strtok(NULL, ","); 
	strcpy(user, charTok); 
 
	//header row 
	fgets(header, sizeof(header), inputStream); 
 
	//cleansing and dedupe  
	while (fgets(line, sizeof(line), inputStream) != NULL) 
	{ 
		//written that if id or time doesnt exist it is thrown out garbage data 
		charTok = strtok(line, ","); 
		if (strcmp(charTok, user) == 0) 
		{ 
			charTok = strtok(NULL, ","); 
 
			index = timeToIndex(charTok); 
 
			if(charTok[0] != NULL && isDuplicate(entries, index) == 0) 
			{ 
				strcpy(entries[index].patient, user); 
				strcpy(entries[index].minute, charTok); 
 
				//calories 
				charTok = strtok(NULL, ","); 
				if (charTok[0] != NULL) 
				{ 
					entries[index].calories = atof(charTok); 
					tCal += entries[index].calories; 
				} 
				else 
				{ 
					entries[index].calories = -1; 
				} 
 
				//distance 
				charTok = strtok(NULL, ","); 
				if (charTok[0] != NULL) 
				{ 
					entries[index].distance = atof(charTok); 
					tDis += entries[index].distance; 
				} 
				else 
				{ 
					entries[index].distance = -1; 
				} 
 
				//floors 
				charTok = strtok(NULL, ","); 
				if (charTok[0] != NULL) 
				{ 
					entries[index].floors = atoi(charTok); 
					tFloors += entries[index].floors; 
				} 
				else 
				{ 
					//completely unreasonable number for a minute 
					entries[index].floors = 1000; 
				} 
 
				//heart rate 
				charTok = strtok(NULL, ","); 
				if (charTok[0] != NULL) 
				{ 
					entries[index].heartRate = atoi(charTok); 
					avgHrate += entries[index].heartRate; 
				} 
				else 
				{ 
					//completely unreasonable number for a minute 
					entries[index].heartRate = 1000; 
				} 
 
				//steps 
				charTok = strtok(NULL, ","); 
				if (charTok != NULL) 
				{ 
					entries[index].steps = atoi(charTok); 
					tSteps += entries[index].steps; 
					if (entries[index].steps >= mSteps) 
					{ 
						mSteps = entries[index].steps; 
					} 
				} 
				else 
				{ 
					//completely unreasonable number for a minute 
					entries[index].steps = 1000; 
				} 
 
				charTok = strtok(NULL, ","); 
				if (charTok != NULL && atoi(charTok) != 0) 
				{ 
					if (atoi(charTok) == 1) 
					{ 
						entries[index].sleepLevel = ASLEEP; 
					} 
					if (atoi(charTok) == 2) 
					{ 
						entries[index].sleepLevel = AWAKE; 
					} 
					if (atoi(charTok) == 3) 
					{ 
						entries[index].sleepLevel = REALLYAWAKE; 
					} 
				} 
				else 
				{ 
					entries[index].sleepLevel = -1; 
				} 
 
				//for average 
				//totalEntries++; 
			} 
		} 
	} 
 
 
	avgHrate = avgHeartrate(entries); 
	worstSleep(entries, sleep); 
 
	fclose(inputStream); 
 
	FILE* outputStream = fopen("Results.csv", "w"); 
 
	//csv print 
 
	fprintf(outputStream, "%s", header); 
	fprintf(outputStream, "%lf, %lf, %d, %d, %lf, %d, %s\n", tCal, tDis, tFloors, tSteps, avgHrate, mSteps, sleep); 
 
	for (int i = 0; i < 1440; i++) 
	{ 
		if (entries[i].minute[0] != '\0') 
		{ 
			fprintf(outputStream,"%s", entries[i].patient); 
			fprintf(outputStream, ",%s", entries[i].minute); 
			fprintf(outputStream, ",%lf", entries[i].calories); 
			fprintf(outputStream, ",%lf", entries[i].distance); 
			fprintf(outputStream, ",%u", entries[i].floors); 
			fprintf(outputStream, ",%u", entries[i].heartRate); 
			fprintf(outputStream, ",%u", entries[i].steps); 
			fprintf(outputStream, ",%d\n", entries[i].sleepLevel); 
		}	 
	} 
 
	fclose(outputStream); 
 
} 
 
