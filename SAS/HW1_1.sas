LIBNAME mine 'C:\전산통계\과제';

DATA mine.one;
INFILE 'C:\전산통계\과제\HW1_data.txt' FIRSTOBS = 9;
INPUT major $12. id #3 fullname $7-13 #2 exam1 exam2 exam3 #3 final;
Run;

DATA mine.new(drop = fullname exam1 exam2 exam3 final);
	SET mine.one;

	lastname = SUBSTR(fullname, 1, 2);
	firstname = SUBSTR(fullname, 4, 7);

	total = exam1 + exam2 + exam3 + final;
	if total >= 80 then grade = 'Pass';
				else grade = 'Fail';
Run;
PROC SORT DATA = mine.new;
	BY DESCENDING total;
RUN;

DATA mine.finaldata;
	SET mine.new;

	rank  = _N_ || "등";
Run;

PROC EXPORT DATA= MINE.FINALDATA 
            OUTFILE= "C:\전산통계\과제\finaldata.txt" 
            DBMS=TAB REPLACE;
     PUTNAMES=YES;
RUN;
