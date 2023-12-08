//approx=0.3433 real=0.3333
//Error
#include<stdio.h>
#include<math.h>

double calculateAbsoluteError(double trueValue, double approx){
	return fabs(trueValue-approx);
}
double calculateRelativeError(double trueValue, double approx){
	return fabs((trueValue-approx)/trueValue);
}
double calculatePercentageError(double trueValue , double approx){ 
	return calculateRelativeError(trueValue, approx)*100.0;
}
int main(){
	double trueValue, approx;
	printf("Enter True Value: ");
	scanf("%lf", &trueValue);
	printf("Enter Approximate Value: ");
	scanf("%lf", &approx);
	double absError=calculateAbsoluteError(trueValue, approx);
	double relError=calculateRelativeError(trueValue, approx);
	double percError=calculatePercentageError(trueValue, approx);
	printf("Absolute error= %lf, Relative error= %lf, Percentage error= %lf", absError, relError, percError);	
}
