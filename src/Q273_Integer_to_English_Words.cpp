#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string result;
    string numberToWords(int num) {
    	if (num == 0 && result == "")
    	{
    		return "Zero";
    	}
    	else if (num == 0)
    		return "";
    	else if (num/1000000000)
    	{
    		numberToWords(num/1000000000);
    		result += "Billion ";
    		numberToWords(num%1000000000);
    	}
    	else if (num/1000000 > 0)
    	{
    		numberToWords(num/1000000);
    		result += "Million ";
    		numberToWords(num%1000000);
    	}
    	else if (num/1000 > 0)
    	{
    		numberToWords(num/1000);
    		result += "Thousand ";
    		numberToWords(num%1000);
    	}
    	else if (num/100 > 0)
    	{
    		numberToWords(num/100);
    		result += "Hundred ";
    		numberToWords(num%100);
    	}
    	else if (num >= 20)
    	{
    		int temp = num/10;
    		if (temp == 9)
    			result += "Ninety ";
    		else if (temp == 8)
    			result += "Eighty ";
    		else if (temp == 7)
    			result += "Seventy ";
    		else if (temp == 6)
    			result += "Sixty ";
    		else if (temp == 5)
    			result += "Fifty ";
    		else if (temp == 4)
    			result += "Forty ";
    		else if (temp == 3)
    			result += "Thirty ";
    		else
    			result += "Twenty ";
    		numberToWords(num%10);
    	}
    	else if (num >= 10)
    	{
    		if (num == 10)
    			result += "Ten ";
    		else if (num == 11)
    			result += "Eleven ";
    		else if (num == 12)
    			result += "Twelve ";
    		else if (num == 13)
    			result += "Thirteen ";
    		else if (num == 14)
    			result += "Fourteen ";
    		else if (num == 15)
    			result += "Fifteen ";
    		else if (num == 16)
    			result += "Sixteen ";
    		else if (num == 17)
    			result += "Seventeen ";
    		else if (num == 18)
    			result += "Eighteen ";
    		else
    			result += "Nineteen ";
    	}
    	else
    	{
    		if (num == 1)
    			result += "One ";
    		else if (num == 2)
    			result += "Two ";
    		else if (num == 3)
    			result += "Three ";
    		else if (num == 4)
    			result += "Four ";
    		else if (num == 5)
    			result += "Five ";
    		else if (num == 6)
    			result += "Six ";
    		else if (num == 7)
    			result += "Seven ";
    		else if (num == 8)
    			result += "Eight ";
    		else
    			result += "Nine ";
    	}
    	if (result[result.length()-1] == ' ')
    		return result.substr(0,result.length()-1);
    	return result;
    }
};
