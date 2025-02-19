# include <iostream>
# include <fstream>
# include "Process.h"
using namespace std;

int main()
{
	Process test1;
	string inputFilePath = "./Test Model 3.txt";
	test1.Input( inputFilePath );
	test1.PrintData();

//	vector<vector<double>> A = {
//		{2.2, 1.1, -19.1},
//		{-3.2 , -1.0, 2.3},
//		{-2.3, 1.1, 2.4}
//	};
//	vector<double> B = {8.8, -11.7, -3.5};
//	test1.Print_Matrix(A);
//	vector<double> X = test1.Solve(A, B);
//	if ( !X.empty() )
//	{
//		cout << "Solution vector X:" << endl;
//		for (const auto& x : X)
//		{
//			cout << x << endl;
//		}
//	}
//	
//	vector<vector<double>> C = {
//		{1.0, 2.0, 3.0},
//		{2.0, 4.0, 5.0},
//		{3.0, 5.0, 6.0}
//	};
//	cout << "check symmetric with tolence less than 1e-9 " << (test1.Symmetric_Cond(C)?"true":"false") << endl << endl;
//	vector<double> K;
//	vector<int> Q,P;
//	tie(K, Q, P) = test1.CSR(C);
//	// OR auto [K, Q, P] = Sol.CSR(C);
//	cout << "K: ";
//	for (double val : K) cout << val << " ";
//	cout << endl;

//	cout << "Q: ";
//	for (int val : Q) cout << val << " ";
//	cout << endl;

//	cout << "P: ";
//	for (int val : P) cout << val << " ";
//	cout << endl;

//	cout << endl;

	vector<vector<double>> K;
	vector<double> F, D, flux;
	tie(K, F) = test1.Build();
	D = test1.Solution();
	test1.Print_Vector(D);
	flux = test1.Flux(D);
	test1.Print_Vector(flux);
	
	// Create output file name
	size_t lastDot = inputFilePath.find_last_of(".");
	string outputFilePath = inputFilePath.substr(0, lastDot) + ".out";
	
	// Open the output file
	ofstream outFile(outputFilePath);
	if (!outFile.is_open())
	{
		cerr << "Error: Unable to open output file: " << outputFilePath << endl;
		return 1;
	}

	// Print formatted output to the file
	test1.PrintFormattedOutput(outFile);
	
	// Close the file
	outFile.close();
	
	cout << "Output written to: " << outputFilePath << endl;

	return 0;
}
