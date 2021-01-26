// last web pract 20.1.21.cpp : Problem solving with teams
//
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
int sumArr(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum = sum + arr[i];
	}
	return sum;
}
static void generateCombOfKElements(int arr[], int arrSize, int currentComb[], int combSize, int sum, int combIndex = 0, int arrIndex = 0){
	if (combIndex == combSize){//The combination is completed 
		int combSum = sumArr(currentComb, combSize);//if the sum of the elements in the combination == sum, then the combinations is printed
		if (combSum == sum){
			cout << sum << " = ";
			for (int j = 0; j < combSize; j++){
				if (currentComb[j] >= 0 && j != 0){
					cout << " + ";
				}
				else{
					cout << " ";//if the number is negative, we dont need to put another sign before the number 
				}
				cout << currentComb[j];
			}
			cout << endl;
		}
		return;
	}
	if (arrIndex >= arrSize){
		return;//There are no more elements 
	}
	currentComb[combIndex] = arr[arrIndex];//The current index is added to the combination and we can proceed to the next index
	generateCombOfKElements(arr, arrSize, currentComb, combSize, sum, combIndex + 1, arrIndex + 1);
	//We take the next index at the place of the current one  
	generateCombOfKElements(arr, arrSize, currentComb, combSize, sum, combIndex, arrIndex + 1);
}
void combinationAllElements(int arr[], int arrSize, int sum) {
	for (int k = 1; k <= arrSize; k++){
		int comb[MAX_SIZE] = { 0, };
		generateCombOfKElements(arr, arrSize, comb, k, sum);
	}
}
int main(){
	//8. Даден е масив с цели числа и число N.
	//Напишете рекурсивна прог­рама, 
	//която намира всички подмножества от числа от масива,
	//които имат сума N.
	//Например ако имаме масива{ 2, 3, 1, -1 } и N = 4, можем да получим N = 4 като сума по следните два начина : 4 = 2 + 3 - 1; 4 = 3 + 1.
	int arr[MAX_SIZE] = { 2, 3, 1, -1 };
	//int arr[] = { 3, 1, 1, -1 };
	int size = 4;
	int sum = 4;
	combinationAllElements(arr, size, sum);
	return 0;
}
