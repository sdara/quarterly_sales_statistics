/*
Programmer		:	sdara
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