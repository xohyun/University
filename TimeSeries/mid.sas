data lab1;
	infile 'C:\stock.txt';
	input p @@;

	date = intnx('month', '1JAN84'D, _n_ - 1);
	format date Monyy.;
run;

symbol i = join c = black;
proc gplot data = lab1;
	plot p*date=1;
run;quit;

data lab1plus;
	set lab1;
	z0 = p;
	a = dif1(p);
	z = dif1(p)/(z0-a) * 100;
	output;
run;

symbol i = join c = black;
proc gplot data = lab1plus;
	plot z * date = 1;
run; quit;


data lab2;
	a1 = 0;
	z1 = 0;
	do t = 1 to 100;
		a = rannor(1840);
		z = 10 + 0.5 * z1 + a - 0.3 * a1;
		output;
		a1 = a;
		z1 = z;
	end;
run;

symbol1 i = join v = none h = 2 l = 1c = black;
proc gplot data = lab2;
	plot z * t = 1 / vref = 10 haxis = 0 to 100 by 10;
run; quit;

/*7번*/
ODS RTF FILE = 'C:\시계열\test.rtf';
data lab3;
	infile 'C:\passangerdata.txt'  expandtabs;
	input  d$ number;

	date = intnx('month', '1JAN49'D, _n_ - 1);
	format date Monyy.;
run;
proc X12 data = lab3 seasons = 12 start = Jan49;
	var number;
	x11 mode = MULT;
	output out = lab3out a1 d10 d11 d12 d13;
run;
proc print data = lab3out; run;

data lab4;
	set lab3out;
	label number_a1 = " " number_d10 = " " number_d11 = " " number_d12 = " " number_d13 = " " ;
run;

symbol1 l = 1 i = join v = none c= black;
symbol2 h = 0.5 i = none v = dot c = black;

proc gplot data = lab3out;
	plot number_a1 * _date_ = 1 number_d11 * _date_ = 2 / overlay legend;
run;
/*불규칙성분 그래프*/
proc gplot data = lab3out;
	plot number_d13 * _date_ = 1 / vref = 1 legend;
run;
/*자기상관계수 출력*/
proc arima data = lab3out;
	identify var = number_d13 nlag = 24;
run;
/*백색잡음*/
ods rtf close;
