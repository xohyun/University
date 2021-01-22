LIBNAME newlib 'C:\전산통계\과제';

PROC SORT DATA = newlib.class1_math; BY descending SSN; RUN;
PROC SORT DATA = newlib.class1_eng; BY descending SSN; RUN;

DATA class1;
	merge newlib.class1_math newlib.class1_eng;
	BY descending SSN;
	class = '1반';
RUN;

PROC SORT DATA = newlib.class2_math; BY descending SSN; RUN;
PROC SORT DATA = newlib.class2_eng; BY descending SSN; RUN;

DATA class2;
	merge newlib.class2_math newlib.class2_eng;
	BY descending SSN;
	class = '2반';
RUN;

DATA all;
	SET class1 class2;
	BY descending SSN;
	fullname = compress(lastname) || ', ' || compress(firstname) || ' ' || compress(middlename);
	total = sum(math,  eng);
	
	if total >= 180 then grade = 'A';
		else if total >= 160 then grade = 'B';
		else if total >= 140 then grade = 'C';
		else if total >= 120 then grade = 'D';
		else grade = 'F';

	DROP lastname firstname middlename;
RUN;

DATA newlib.pass(keep = SSN total grade fullname status) newlib.fail(keep = SSN total grade status);
	SET all;

	if grade in('A', 'B', 'C', 'D')  then do
								status = '성공';
								output newlib.pass;
								end;
		else do
				status = '실패';
				output newlib.fail;
				end;
RUN;
