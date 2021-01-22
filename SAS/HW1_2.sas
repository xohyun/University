PROC EXPORT DATA= MINE.FINALDATA 
            OUTFILE= "C:\전산통계\과제\finaldata.txt" 
            DBMS=TAB REPLACE;
     PUTNAMES=YES;
RUN;
