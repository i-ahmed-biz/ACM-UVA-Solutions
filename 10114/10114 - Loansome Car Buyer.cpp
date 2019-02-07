#include <iostream>

using namespace std;

int main() {
	int noMonths, noRec, depAppliedMonth, noLossMonths, i, j;
	double downPayment, loanAmount, depreciations[101], depAmount, amountAfterDep, monthlyPayment;

	while (1) {
		cin>>noMonths;

		if(noMonths < 0) {
		    break;
		}

		cin>>downPayment>>loanAmount>>noRec;

		for(i = 0; i < noRec; i++) {
		    cin>>depAppliedMonth>>depAmount;
		    for(j = depAppliedMonth; j < 101; j++) {
		        depreciations[j] = depAmount;
		    }
		}
        amountAfterDep = (loanAmount + downPayment) * (1 - depreciations[0]);

        noLossMonths = 0;
        monthlyPayment = loanAmount / noMonths;

        while(amountAfterDep < loanAmount) {
            noLossMonths++;

            loanAmount = loanAmount - monthlyPayment;
            amountAfterDep = amountAfterDep - depreciations[noLossMonths] * amountAfterDep;
        }
	    if(noLossMonths == 1) {
	        cout<<noLossMonths<<" month"<<endl;
	    }
	    else {
	       cout<<noLossMonths<<" months"<<endl;
	    }
	}

	return 0;
}

