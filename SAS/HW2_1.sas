DATA homework;
	FILE 'C:\전산통계\과제\hw2gugudan.txt';

	PUT '<<구구단 (18단)>>' /  29 * '=';
	DO index1 = 2 TO 18;
		DO index2 = 1 TO 18;
			result = index1 * index2;
			PUT index1 'X ' index2 '= ' result;
		END;
		PUT 29 * '=';
	END;
RUN;
