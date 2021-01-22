//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n;
		do {
			System.out.print("정수를 입력하세요: ");
			n = scan.nextInt();
			if (n < 1) {
				System.out.println("잘못된 입력입니다. 다시 입력하세요.");
			}
		}while(n < 1);
		
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 5 != 0) {
				count++;
				System.out.print(i + "\t");
			}
			if (count % 7 == 0) {
				System.out.println();
			}
		}
	}

}
//do while 띄어쓰기 확인.