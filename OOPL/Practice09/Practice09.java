//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int n, total = 0;
		do {
			System.out.print("숫자를 입력하세요: ");
			n = scan.nextInt();
			if (n < 0) {
				System.out.println("음수가 입력되었습니다. 다시 입력하세요.");
				continue;
			}
			total += n;
		}while (n != 0);
		System.out.println("입력된 숫자들의 합은 " + total + "입니다.");
	}

}
