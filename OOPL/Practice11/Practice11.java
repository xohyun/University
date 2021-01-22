//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); 

		int n;
		
		do {
			System.out.print("숫자를 입력하세요: ");
			n = scan.nextInt();
			if (n < 1) {
				System.out.println("잘못된 입력입니다. 다시 입력하세요.");
			}
		}while(n < 1);
		
		boolean isPrime = true;
		
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		
		if (isPrime == false || n == 1) {
			System.out.println("입력된 숫자 " + n +"은 소수가 아닙니다.");
		}
		else {
			System.out.println("입력된 숫자 " + n +"은 소수입니다.");
		}
	}

}
