//split.cpp

#pragma once
#include "Split.h"

vector<std::string> Split(std::string str, char delimiter)  //takes a string and a delimiter as parameters and
															//returns the corresponding vector of strings
{
	vector<std::string> splittedString;
	unsigned int i =0;
	unsigned int k=0; //number of characters between two delimiters
	while(i<str.size())
	{
		while(i<str.size() && str[i]!=delimiter) //i<str.size() if not str[i] could be out of range
		{
			i++;
			k++;
		} //str[i] is now a delimiter or i is out of range, even if we did not enter the while
		if(k>0)  //that means we entered the second while and that there is a string between two delimiters
		//i may be equal to str.size() but as k>0, i-k and i-k-1 (the last char of substr(i-k,k)) are not out of range
		{
			splittedString.push_back(str.substr(i-k,k)); //add the string between two delimiters (w/o them) to the vector splitted String
			                //(i because str[i-k-1] is a delimiter)	
		}
		else  //that means there is no string
		{	
			
			splittedString.push_back("");  //we want to know there are two delimiters with nothing between them
		}
		i++;
		k=0; 

	}
	if(str[str.size()-1] = delimiter)
		{
			splittedString.push_back("");  //if a delimiter is at the end of the string, it will take it into account
				//and add "" at the end of the vector : when we split e.g "52;Chateau de Vincennes;1;" we want splittedString.size()=4
		}
	return splittedString;
}