//컴퓨터학과 20170988 한소현
import java.util.Scanner;

public class Practice05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.print("정수를 입력하세요: ");
		int n = scan.nextInt();
		
		if (n >= 0) {
			System.out.println("입력한 정수 " + n + "의 절대값은 " + n + "입니다.");
		}
		else {
			System.out.println("입력한 정수 " + n + "의 절대값은 " + (-n) + "입니다.");
		}
	}

}
