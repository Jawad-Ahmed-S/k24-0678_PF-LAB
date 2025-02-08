#include<stdio.h>
int main(){
	float distance,firstFuelPrice,secondFuelPrice,VehicleAvg;
	float FuelConsumed,FuelPrice;
		printf("Enter one sided distance: ");
		scanf("%f",&distance);
		printf("Enter fuel prce on day of departure: ");
		scanf("%f",&firstFuelPrice);
		printf("Enter fuel prce on day of coming back: ");
		scanf("%f",&secondFuelPrice);
		printf("Enter vehicle average in km/litres: ");
		scanf("%f",&VehicleAvg);

		if(VehicleAvg<=0){
			printf("Enter a valid Vehicle Average");
			}
		else{
		FuelConsumed = ((distance*2)/VehicleAvg);
		
		FuelPrice = (((FuelConsumed/2) *firstFuelPrice) + ((FuelConsumed/2) *secondFuelPrice));

		printf("Total fuel consumed : %0.2f \n ",FuelConsumed);
		printf("Total price for the fuel :%0.2f \n",FuelPrice );
			}
	return 0;

}