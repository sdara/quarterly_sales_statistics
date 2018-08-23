09-20-2004
CSC153-02
Project #02

Psuedocode

This program will ask the user for the total sales of six divisions of a company over 4 quarters.

Include Header Files

Include Function prototypes.

This is where the function would go to get the data that the user would enter, but for ease of testing and debugging, the array of 24 values was initialized.

Call the function that displays the users input

Call the function that calculates and displays each division’s change over the 4 quarters

Call the function that displays the quarterly totals

Call the function that calculates the company change over the 4 quarters

calls the function that calculates the average sales for all division per quarter

Call the function that calculates the highest selling division per quarter


Source Code

/*
Programmer		:	Seth Dara
Program No.		:	2
Date Written	:	09/19/04
Date Revised	:	09/19/04
Program	Title	:	Quarterly Sales Statistics
Description		:
 
  This program will ask the user for the total sales of six divisions of a company
  over 4 quarters.
  
  Input Validation: Do not allow negative numbers for sales totals to be entered.
 
*/
 
//Include header files for the entire program to use
#include <iostream.h>
#include <iomanip.h>
 
//function prototypes
void ListSalesFigures(float SalesArray[][4]);
void DivChangeFromPrevQuarter(float SalesArray[][4]);
void TotalForQuarters(float SalesArray[][4]);
void CompanyChangeFromPrevQuarter(float SalesArray[][4]);
void AverageSalesForDivisionsPerQuarter(float SalesArray[][4]);
void HighestDivisionPerQuarter(float SalesArray[][4]);
 
 
/*
This is the main program, which initializes the array of
24 values (for ease) and then calls the 6 functions
which make the various calculations
*/
 
void main(void)
{
		//initialize array with predefined values - for ease
	float TotalSales[6][4]={100,200,300,400,
							10,20,30,40,
							200,400,600,800,
							10,200,30,400,
							13,444,52,798,
							123,456,789,987};
 
	//display cout statement
	cout<<setiosflags(ios::fixed|ios::right|ios::showpoint)<<setprecision(2);
	
	cout<<"This program will take the 24 values (consisting of figures from 6 divisions of a company spanning 4 quarters) and display certain statistics about them!"<<endl;
 
	//calls the function which lists all sales figures
	ListSalesFigures(TotalSales);
	cout<<endl;
	
	//calls the function that calculats the division 
	//change over the 4 quarters
	DivChangeFromPrevQuarter(TotalSales);
	cout<<endl;
 
	//calls the function that displays the quarterly totals
	TotalForQuarters(TotalSales);
	cout<<endl;
 
	//calls the function that calculates the company
	//change over the 4 quarters
	CompanyChangeFromPrevQuarter(TotalSales);
	cout<<endl;
 
	//calls the function that calculates the average
	//sales for all division per quarter
	AverageSalesForDivisionsPerQuarter(TotalSales);
	cout<<endl;
 
	//calls the function that calculates the highest selling
	//division per quarter
	HighestDivisionPerQuarter(TotalSales);	
	cout<<endl;
 
	//a thank you message
	cout<<"Thank you for using this program!";
	cout<<endl<<endl;;
 
 
}
 
 
/*
This function displays the entered (or in this case pre-defined)
values in the two-dimentional array which represents the
sales figures for 6 divisions of a company over 4 quarters
*/
void ListSalesFigures(float SalesArray[][4])
{
	int Quarter=0,Division=0;
	cout << "\n========================================\n";
	cout << "SALES FIGURES BY DIVISION"<<endl;
	cout << "========================================\n\n";
	cout << "\t\t\t QUARTER\n\t     |==================================\nDIVISION     |\t";
	cout<<"  Q1\t  Q2\t  Q3\t  Q4\n\t     |"<<endl;
	for(Division=0;Division<6;Division++)
	{
		cout<<"   "<<Division+1<<":\t     |\t";
		for(Quarter=0;Quarter<4;Quarter++){
			cout << "$"<<SalesArray[Division][Quarter] << "\t";
		}
		cout << endl;
	}
}
 
/*
This function calculates and displays the division change
from that divisions previous quarter (either + or -)
*/
void DivChangeFromPrevQuarter(float SalesArray[][4]){
	int Quarter=0,Division=0;
	float PreviousQuarter=0, CurrentQuarter=0,DisplayNum=0;
	cout << "\n========================================\n";
	cout << "CHANGE FROM PREVIOUS QUARTER"<<endl;
	cout << "========================================\n\n";
	
	for(Division=0;Division<6;Division++)
	{
		cout<<"DIVISION " << Division+1 << ": "<<endl;
		for(Quarter=0;Quarter<4;Quarter++)
		{
			PreviousQuarter=0;
			CurrentQuarter=0;
			if(Quarter!=0){
			PreviousQuarter=SalesArray[Division][Quarter-1];
			CurrentQuarter=SalesArray[Division][Quarter];
			cout<<"QUARTER "<<Quarter+1<<": ";
			if(CurrentQuarter>PreviousQuarter){
				DisplayNum=CurrentQuarter-PreviousQuarter;
				cout<<"+";
			}else{
				DisplayNum=(CurrentQuarter-PreviousQuarter)*-1;
					cout<<"-";
			}
			cout<<" $"<<DisplayNum;
			if(CurrentQuarter>PreviousQuarter){
			cout<<" (UP)"<<endl;
			}else{
			cout<<" (DOWN)"<<endl;
			}
			}
		
 
		}
			cout<<endl;
	}
}
 
/*
This function calculates and displays the total sales
for all 6 divisions per quarter.
*/
void TotalForQuarters(float SalesArray[][4])
{
	int Quarter=0,Division=0;
	float QuarterTotal=0;
	cout << "========================================\n";
	cout << "QUARTERLY TOTALS"<<endl;
	cout << "========================================\n\n";
	for(Quarter=0;Quarter<4;Quarter++){
		QuarterTotal=0;
		for(Division=0;Division<6;Division++){
			QuarterTotal+= SalesArray[Division][Quarter];
		}
		cout << "Quarter " << Quarter+1 << ", All Divisions: $" << QuarterTotal<<endl;
	}
 
}
 
/*
This function calculates and displays the company's overall
increase or decrease in profit per quarter (either + or -)
*/
void CompanyChangeFromPrevQuarter(float SalesArray[][4])
{
	int Quarter=0,Division=0;
	float CompanyPreviousQtr=0,CompanyCurrentQtr=0;
	cout << "\n========================================\n";
	cout << "COMPANY QUARTERLY CHANGES"<<endl;
	cout << "========================================\n\n";
	for(Quarter=0;Quarter<4;Quarter++){
		CompanyPreviousQtr=0;
		CompanyCurrentQtr=0;
		if(Quarter!=0){
		for(Division=0;Division<6;Division++){
			CompanyPreviousQtr+= SalesArray[Division][Quarter-1];
			CompanyCurrentQtr+= SalesArray[Division][Quarter];
		}
		cout << "Quarter " << Quarter << " to Quarter " << Quarter+1<<": ";
		if(CompanyCurrentQtr>CompanyPreviousQtr){
			cout<<"+ $";
		}else{
				cout<<"- $";
		}
		cout<<CompanyCurrentQtr-CompanyPreviousQtr;
		if(CompanyCurrentQtr>CompanyPreviousQtr){
			cout<<" (UP)";
		}else{
			cout<<" (DOWN)";
		}
		cout<<endl;
		}
		
	}
 
}
 
/*
This function calculates and displays the average sales figures
for all 6 divisions per quarter
*/
void AverageSalesForDivisionsPerQuarter(float SalesArray[][4]){
		int Quarter=0,Division=0;
		float QuarterTotalForAvg=0;
	cout << "\n========================================\n";
	cout << "AVERAGE OF ALL DIVISIONS PER QUARTER"<<endl;
	cout << "========================================\n\n";
	for(Quarter=0;Quarter<4;Quarter++){
			QuarterTotalForAvg=0;	
		for(Division=0;Division<6;Division++){
				QuarterTotalForAvg+=SalesArray[Division][Quarter];
		}
		cout<<"Quarter "<<Quarter+1<<", All Divisions (avg): $"<< QuarterTotalForAvg/(Division)<<endl;
 
				}
}
 
/*
This function calculates and displays which division
of the company had the highest sales per quarter
*/
void HighestDivisionPerQuarter(float SalesArray[][4])
{
		int Quarter=0,Division=0;
		int HighestDivNum=0;
		float HighestDivisionTotal=0,CurrentDivisionTotal=0;
	cout << "\n========================================\n";
	cout << "HIGHEST DIVISION PER QUARTER"<<endl;
	cout << "========================================\n\n";
	
	for(Quarter=0;Quarter<4;Quarter++){
	CurrentDivisionTotal=0;
 
	for(Division=0;Division<6;Division++){
	CurrentDivisionTotal=SalesArray[Division][Quarter];
	if(CurrentDivisionTotal>HighestDivisionTotal){
	HighestDivisionTotal=CurrentDivisionTotal;
	HighestDivNum=Division+1;
	}
 
	}
	cout<<"Quarter "<<Quarter+1<<": Division "<<HighestDivNum<<endl;
}
 
}

Program Output

This program will take the 24 values (consisting of figures from 6 divisions of
a company spanning 4 quarters) and display certain statistics about them!
 
========================================
SALES FIGURES BY DIVISION
========================================
 
                         QUARTER
             |==================================
DIVISION     |    Q1      Q2      Q3      Q4
             |
   1:        |  $100.00 $200.00 $300.00 $400.00
   2:        |  $10.00  $20.00  $30.00  $40.00
   3:        |  $200.00 $400.00 $600.00 $800.00
   4:        |  $10.00  $200.00 $30.00  $400.00
   5:        |  $13.00  $444.00 $52.00  $798.00
   6:        |  $123.00 $456.00 $789.00 $987.00
 
 
========================================
CHANGE FROM PREVIOUS QUARTER
========================================
 
DIVISION 1:
QUARTER 2: + $100.00 (UP)
QUARTER 3: + $100.00 (UP)
QUARTER 4: + $100.00 (UP)
 
DIVISION 2:
QUARTER 2: + $10.00 (UP)
QUARTER 3: + $10.00 (UP)
QUARTER 4: + $10.00 (UP)
 
DIVISION 3:
QUARTER 2: + $200.00 (UP)
QUARTER 3: + $200.00 (UP)
QUARTER 4: + $200.00 (UP)
 
DIVISION 4:
QUARTER 2: + $190.00 (UP)
QUARTER 3: - $170.00 (DOWN)
QUARTER 4: + $370.00 (UP)
 
DIVISION 5:
QUARTER 2: + $431.00 (UP)
QUARTER 3: - $392.00 (DOWN)
QUARTER 4: + $746.00 (UP)
 
DIVISION 6:
QUARTER 2: + $333.00 (UP)
QUARTER 3: + $333.00 (UP)
QUARTER 4: + $198.00 (UP)
 
 
========================================
QUARTERLY TOTALS
========================================
 
Quarter 1, All Divisions: $456.00
Quarter 2, All Divisions: $1720.00
Quarter 3, All Divisions: $1801.00
Quarter 4, All Divisions: $3425.00
 
 
========================================
COMPANY QUARTERLY CHANGES
========================================
 
Quarter 1 to Quarter 2: + $1264.00 (UP)
Quarter 2 to Quarter 3: + $81.00 (UP)
Quarter 3 to Quarter 4: + $1624.00 (UP)
 
 
========================================
AVERAGE OF ALL DIVISIONS PER QUARTER
========================================
 
Quarter 1, All Divisions (avg): $76.00
Quarter 2, All Divisions (avg): $286.67
Quarter 3, All Divisions (avg): $300.17
Quarter 4, All Divisions (avg): $570.83
 
 
========================================
HIGHEST DIVISION PER QUARTER
========================================
 
Quarter 1: Division 3
Quarter 2: Division 6
Quarter 3: Division 6
Quarter 4: Division 6
 
Thank you for using this program!
 
Press any key to continue
