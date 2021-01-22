ods rtf file = 'c:\time_series\6.rtf';
data lab1;
	infile 'C:\passangerdata.txt'  expandtabs;
	input  d$ p;
	date = intnx('month', '1JAN49'D, _n_ - 1);
	lnp = log(p);
	lnp1 = dif(lnp);
	lnp12 = dif12(lnp);
	lnp121 = dif(lnp12);
	lnp112 = dif12(lnp1);
	format date Monyy.;
run;

symbol1 i = join v = none l = 1 c = black;
symbol2 i = join v = none l = 3 c = blue;
symbol3 i = join v = none l = 3 c = blue;
proc gplot data = lab1;
	plot p*date = 1; run;
	plot lnp * date = 1; run;
	plot lnp1 * date = 1; run;
	plot lnp12*date = 1; run;
	plot lnp121 * date = 1; run;
	plot lnp112*date = 1; run;
quit;

proc arima data = lab1;
	identify var = p stationarity = (adf dlag = 1) nlags = 36;
	identify var = lnp stationarity = (adf dlag = 1) nlags = 36;
	identify var = lnp1 stationarity = (adf dlag = 1) nlags = 36;
	identify var = lnp12 stationarity = (adf dlag = 1) nlags = 36;
	identify var = lnp121 stationarity = (adf dlag = 1) nlags = 36;
	identify var = lnp112 stationarity = (adf dlag = 1) nlags = 36;
run; quit;

proc arima data = lab1;
	identify var = p(1, 12) nlags = 36;
	estimate plot;
run; quit;

proc arima data = lab1;
	identify var = lnp(1,12) nlags = 36;
	estimate q = (1)(12) plot noint;
	forecast lead = 3 out = fore1;
run; quit;

data fore1; set fore1; n = _n_; run;

/*잔차분석*/
proc gplot data = fore1;
	plot residual * n = 1 / frame vref = 0;
run; quit;

proc arima data = fore1;
	identify var = residual nlag = 24;
run; quit;

proc gplot data = fore1;
	plot lnp*n = 1 forecast*n = 3 / overlay legend;
run; quit;
ods rtf close;


/********************************************/


ods rtf file = 'c:\time_series\7.rtf';
data lab2;
    infile 'C:\time_series\uschange.txt';
    input consumption income production savings unemployment;
    date = intnx('qtr', '1JAN70'D, _n_-1);
	z1 = income;
	z2 = consumption;
	z3 = log(z1);
	z4 = log(z2);
    format date Monyy.;
run;

proc timeseries data = lab2 vectorplot = series;
	id  date interval = qtr;
	var z1 z2;
run;

proc timeseries data = lab2 vectorplot = series;
	id  date interval = qtr;
	var z3 z4;
run;

proc arima data = lab2;
	identify var = z1 stationarity = (adf dlag = 1) nlags = 36;
	identify var = z2 stationarity = (adf dlag = 1) nlags = 36;
run; quit;

proc arima data = lab2;
	identify var = z3 stationarity = (adf dlag = 1) nlags = 36;
	identify var = z4 stationarity = (adf dlag = 1) nlags = 36;
run; quit;

proc varmax data = lab2;
	model z1 z2 / p = 4  print = (corry pcorr parcoef) lagmax = 9;
run;

proc varmax data = lab2;
	model z3 z4 / p = 4  print = (corry pcorr parcoef) lagmax = 9;
run;

proc varmax data = lab2;
	model z1 z2 / p = 3 print = (estimates diagnose)
	printform = both lagmax = 7;
	restrict AR(2,1,1) = 0, AR(2,1,2) = 0, AR(3,1,1) = 0, AR(1,2,1) =0, AR(2,2,1) = 0, AR(2,2,2) = 0, AR(3,2,1) = 0;
	causal group1 = (z2) group2 = (Z1);
	causal group1 = (z1) group2 = (z2);
run; quit;

proc varmax data = lab2;
	model z3 z4 / p = 3 print = (estimates diagnose)
	printform = both lagmax = 7;
	restrict AR(2,1,1) = 0, AR(2,1,2) = 0, AR(3,1,1) = 0, AR(1,2,1) =0, AR(2,2,1) = 0, AR(2,2,2) = 0, AR(3,2,1) = 0;
	causal group1 = (z2) group2 = (Z1);
	causal group1 = (z1) group2 = (z2);
run; quit;
ods rtf close;
